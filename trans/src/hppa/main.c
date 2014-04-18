/* $Id$ */

/*
 * Copyright 2002-2012, The TenDRA Project.
 * Copyright 1997, United Kingdom Secretary of State for Defence.
 *
 * See doc/copyright/ for the full copyright terms.
 */

#include <stdio.h>
#include <string.h>

#include <shared/check.h>
#include <shared/getopt.h>

#include <reader/main_reads.h>		/* for d_capsule */
#include <reader/basicread.h>	/* for good_trans */
#include <reader/reader_v.h>
#include <reader/externs.h>

#include <construct/flags.h>		/* for option flags */
#include <construct/flpt.h>
#include <construct/exp.h>		/* for current_alloc_size */
#include <construct/installglob.h>	/* for top_def */
#include <construct/installtypes.h>
#include <construct/construct_v.h>

#include "comment.h"		/* for do_comment */
#include "addrtypes.h"		/* for where */
#include "makecode.h"		/* for nowhere */
#include "exptypes.h"
#include "out.h"
#include "version.h"
#include "diag_out.h"
#include "frames.h"

#ifdef __DATE__
#define compile_date __DATE__
#else
#define compile_date "unknown date"
#endif

extern int good_trans;

char *local_prefix, *name_prefix;

/*
 * XXX: Some of the conditional optimisations local to this installer are
 * miscategorised as OPTIM_PEEPHOLE (which I'm using here for general purpose
 * optimisations, rather than introduce a new category specifically for
 * hppatrans). In particular the jump table optimisations ought to be split
 * out to OPTIM_JUMPS instead.
 */


/* only advertise options in manual page, other debugging options available as well */
static char usage_mess[] = "usage ( s = 0|1 ): trans [-As] [-Bs] [-Cs] [-D] [-d] [-Es] [-Fs] [-Gs] [-H] [-h] [-Is] [-K] [-Ms] [-O] [-P] [-Q] [-Rs] [-T] [-Us] [-V] [-v] [-W] [-Z] TDF-capsule output-as-file\n";

static int init_trans(char *, char *) ; /* forward reference */

int main
(int argc, char ** argv)
{
  char *arg;
  bool errflg = 0;
  bool versionflg = 0;
  char *infname= (char*)0;
  char *outfname= (char*)0;


  /* initialise output file */
  outf = stdout;

  /* errors messages are output on stdout, ensure they get out */
  setbuf(stdout, NULL);

  redo_structfns = 0;	  /* procs delivering structs recast to extra param */
  redo_structparams = 1; /* struct and union value parameters indirected   */
  do_profile = 0;      /* -P option for profiling info */
  do_alloca = 0;      /* inline alloca       */
  PIC_code = 0;
  keep_PIC_vars = 1;
  diagnose_registers = 0;
  use_long_double = 1;

  /* from comment.c */
  do_comment = 0;		/* implement -C option */

#if use_long_double
target_dbl_maxexp = 16384;
#else
target_dbl_maxexp = 308;
#endif

	endian = ENDIAN_BIG;
	assembler = ASM_HP;
	format = FORMAT_SOM;
	diag = DIAG_NONE;
	cconv = CCONV_HPPA;
	abi = ABI_HPUX;

	{
		int c;

		while ((c = getopt(argc, argv,
			"A:B:C:DE:F:G:H:KNO:PQRS:VWX:YZ" "di")) != -1) {
			switch (c) {
			case 'B': builtin = flags_builtin(builtin, optarg); break;
			case 'O': optim   = flags_optim(optim, optarg);     break;
			case 'H': has     = flags_has(has, optarg);         break;
			case 'X': check   = flags_check(check, optarg);     break;

			case 'D':
				/* -D emulates cc's +Z flag */
				PIC_code = 1;
				plusZ = 1;
				break;

			case 'd':
				/* -d emulates cc's +z flag */
				PIC_code = 1;
				plusZ = 0;
				break;

			case 'A':
				abi = switch_abi(optarg, ABI_HPUX);
				break;

			case 'C':
				cconv = switch_cconv(optarg, CCONV_HPPA);
				break;

			case 'E':
				endian = switch_endian(optarg, ENDIAN_BIG | ENDIAN_LITTLE);
				break;

			case 'F':
				format = switch_format(optarg, FORMAT_SOM);
				break;

			case 'G':
#ifdef _SYMTAB_INCLUDED
				diag = switch_diag(optarg, DIAG_STABS);
#else
				diag = switch_diag(optarg, DIAG_STABS | DIAG_XDB | DIAG_GDB);
#endif
				break;

			case 'S':
				assembler = switch_assembler(optarg, ASM_HP | ASM_GAS);
				break;

			case 'K': break;
			case 'M': strict_fl_div = 1;           break;
			case 'P':
				do_profile = 1;
				break;

			case 'Q': exit(EXIT_SUCCESS); break;
			case 'R': round_after_flop = 1; break;

			case 'V':
				fprintf(stderr,"DERA TDF->HP PA-RISC translator %d.%d: "
					"(TDF %d.%d)\n"
					"reader %d.%d:\n"
					"construct %d.%d:\n"
					"translator compilation date = %s\n ",
					MAJOR,MINOR,MAJOR_VERSION,MINOR_VERSION,
					reader_version,reader_revision,construct_version,
					construct_revision,compile_date);
				versionflg = 1;
				break;

			case 'W': break;
			case 'Y': dyn_init = 1; break;
			case 'Z': report_versions = 1; break;

			case 'i':
				do_indexed_loads = 0;
				break;

			case '?':
			default:
				fprintf(stderr, "%s : unknown option, \"%s\"\n", "trans", arg);
				errflg = 1;
				break;
			}
		}

		argc -= optind;
		argv += optind;
	}

   /* we expect two further filename arguments */
   if (argc == 2)
     {
       infname = argv[0];
       outfname = argv[1];
     }
   else if (argc == 1)
     {
       infname = argv[0];
       outfname = "-";
     }
   else { errflg = 1; };

   if (errflg)
     {
       if (!versionflg)		/* no complaints for -v */
	 fprintf(stderr, "%s", usage_mess);
       exit(EXIT_FAILURE);
     }

   if (do_profile && PIC_code)
   {
      fprintf(stderr,"hppatrans warning: \"-P\" and \"-D\" are mutually exclusive. \"-P\" ignored.\n");
      do_profile = 0;
   }

   /* Things trans.hppa does not "has" */
   has &= ~HAS_BYTEOPS;
   has &= ~HAS_BYTEREGS;
   has &= ~HAS_NEGSHIFT;
   has &= ~HAS_ROTATE;
   has &= ~HAS_MAXMIN;
   has &= ~HAS_DIV0;
   has &= ~HAS_SETCC;
   has &= ~HAS_COMPLEX;
   has &= ~HAS_64_BIT;

   /* not implemented */
   optim &= ~OPTIM_TAIL;
   optim &= ~OPTIM_ZEROOFFSETS;
   optim &= ~OPTIM_SUBSTPARAMS;

   /* Careful with procedure results */
   optim &= ~OPTIM_UNPAD_APPLY;

   if (diag != DIAG_NONE) {
      optim = 0;
      /* TODO: do gdb diagnostics depend on gcc assembly? */
   }

   /* init nowhere */
  setregalt(nowhere.answhere, 0);
  nowhere.ashwhere.ashsize = 0;
  nowhere.ashwhere.ashsize = 0;

  local_prefix = "$";		/* Label prefix */
  crt_labno = 101;		/* First label; avoid conflict with reg nos */
				/* (and backward compatibility) */

   name_prefix = "";

  init_flpt();			/* initialise the floating point array */
#include <reader/inits.h>		/* initialise common parts of translator */
  top_def = (dec *)0;

  if (diag != DIAG_NONE)
  {
     init_stab();
  }

  if (init_trans(infname,outfname) || d_capsule() || good_trans)
     exit(EXIT_FAILURE);

  exit_translator();

  /* check for output errors and close the .s file */
  if (ferror(outf)!= 0 || fclose(outf)!= 0)
  {
    fprintf(stderr, "hppatrans: error writing to output file %s\n", outfname);
    exit(EXIT_FAILURE);
  }

  exit(EXIT_SUCCESS);
}

/*
 * Open input and output files.
 */
static int init_trans
(char * infname, char * outfname)
{

  /*
   * Open files.
   */

  if (!initreader(infname))
  {
    fprintf(stderr, "hppatrans: cannot open input file %s\n", infname);
    return 3;
  }

  if (strcmp(outfname, "-") == 0)
  {
    /* "-" by convention means stdout */
    outf = stdout;
  }
  else
  {
    outf = fopen(outfname, "w+");
    if (outf == (FILE *)0)
    {
      fprintf(stderr, "hppatrans: cannot open output file %s\n", outfname);
      return 3;
    }
  }

  return 0;			/* OK */
}

void out_rename
(char * oldid, char * newid)
{
    comment2("renamed %s as %s", oldid, newid);
    return;
}