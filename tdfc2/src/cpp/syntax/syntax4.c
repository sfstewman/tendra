/*
 * Automatically generated from the files:
 *	syntax.sid
 * and
 *	syntax.act
 * by:
 *	sid
 */

/* BEGINNING OF HEADER */

#define __SID_SPLIT
#line 188 "syntax.act"


/* $Id$ */

/*
 * Copyright 2011, The TenDRA Project.
 * Copyright 1997-1998, United Kingdom Secretary of State for Defence.
 *
 * See doc/copyright/ for the full copyright terms.
 */

#include "config.h"
#include "c_types.h"
#include "ctype_ops.h"
#include "exp_ops.h"
#include "hashid_ops.h"
#include "id_ops.h"
#include "nspace_ops.h"
#include "type_ops.h"
#include "error.h"
#include "catalog.h"
#include "option.h"
#include "access.h"
#include "allocate.h"
#include "assign.h"
#include "basetype.h"
#include "cast.h"
#include "chktype.h"
#include "class.h"
#include "constant.h"
#include "construct.h"
#include "convert.h"
#include "declare.h"
#include "derive.h"
#include "dump.h"
#include "exception.h"
#include "expression.h"
#include "function.h"
#include "hash.h"
#include "identifier.h"
#include "initialise.h"
#include "inttype.h"
#include "label.h"
#include "lex.h"
#include "literal.h"
#include "member.h"
#include "namespace.h"
#include "parse.h"
#include "pragma.h"
#include "predict.h"
#include "preproc.h"
#include "redeclare.h"
#include "rewrite.h"
#include "statement.h"
#include "symbols.h"
#include "template.h"
#include "tokdef.h"
#include "token.h"
#include "typeid.h"
#include "variable.h"


/*
    These are the aliases for the compound types used in the parser.
*/

typedef LIST ( EXP ) SID_LIST_EXP ;
typedef LIST ( TYPE ) SID_LIST_TYPE ;


/*
    The function declarations are included at this point so that the
    type definitions are in scope.
*/

#include "syntax.h"


/*
    The output of sid is automatically generated.  Hence it is not
    necessarily appropriate to apply the same level of checking to this
    as to the rest of the program.  These pragmas describe the relaxations
    allowed for the sid output.
*/

#if FS_TENDRA
#pragma TenDRA begin
#pragma TenDRA const conditional allow
#pragma TenDRA unreachable code allow
#pragma TenDRA variable analysis off
#endif


#line 108 "syntax4.c"

void
ZR1194(EXP ZI1192, EXP *ZO1193)
{
	EXP ZI1193;

ZL2_1194:;
	switch (CURRENT_TERMINAL) {
	case 56:
		{
			EXP ZIb;
			EXP ZIe;

			/* BEGINNING OF INLINE: logical-or */
			{
				{
					switch (CURRENT_TERMINAL) {
					case 56:
						break;
					default:
						goto ZL1;
					}
					ADVANCE_LEXER;
				}
			}
			/* END OF INLINE: logical-or */
			ZRlogical_Hand_Hexpression (&ZIb);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: exp_log_or */
			{
#line 716 "syntax.act"

    (ZIe) = make_log_or_exp ( (ZI1192), (ZIb) ) ;
#line 145 "syntax4.c"
			}
			/* END OF ACTION: exp_log_or */
			/* BEGINNING OF INLINE: 1194 */
			ZI1192 = ZIe;
			goto ZL2_1194;
			/* END OF INLINE: 1194 */
		}
		/*UNREACHED*/
	default:
		{
			ZI1193 = ZI1192;
		}
		break;
	case 355:
		return;
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZO1193 = ZI1193;
}

void
ZR1322(int *ZOop)
{
	int ZIop;

	if ((CURRENT_TERMINAL) == 355) {
		return;
	}
	{
		/* BEGINNING OF ACTION: is_array */
		{
#line 2109 "syntax.act"

    /* Resolve 'operator new []' from 'operator new [3]' */
    (ZI0) = predict_array () ;
#line 185 "syntax4.c"
		}
		/* END OF ACTION: is_array */
		if (!ZI0)
			goto ZL2;
		/* BEGINNING OF INLINE: open-square */
		{
			{
				switch (CURRENT_TERMINAL) {
				case 66:
					break;
				default:
					goto ZL1;
				}
				ADVANCE_LEXER;
			}
		}
		/* END OF INLINE: open-square */
		ZRclose_Hsquare_Hx ();
		if ((CURRENT_TERMINAL) == 355) {
			RESTORE_LEXER;
			goto ZL1;
		}
		/* BEGINNING OF ACTION: lex_new_array */
		{
#line 401 "syntax.act"
 (ZIop) = lex_new_Harray ; 
#line 212 "syntax4.c"
		}
		/* END OF ACTION: lex_new_array */
		goto ZL0;
	}
	/*UNREACHED*/
ZL2:;
	switch (CURRENT_TERMINAL) {
	default:
		{
			/* BEGINNING OF ACTION: lex_new */
			{
#line 399 "syntax.act"
 (ZIop) = lex_new ; 
#line 226 "syntax4.c"
			}
			/* END OF ACTION: lex_new */
		}
		break;
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZOop = ZIop;
}

void
ZRcast_Hexpression(EXP *ZOe)
{
	EXP ZIe;

	switch (CURRENT_TERMINAL) {
	case 170:
		{
			int ZIop;

			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: lex_alignof */
			{
#line 396 "syntax.act"
 (ZIop) = lex_alignof ; 
#line 255 "syntax4.c"
			}
			/* END OF ACTION: lex_alignof */
			ZRsizeof_Hexpression (ZIop, &ZIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 83:
		{
			ADVANCE_LEXER;
			ZR1286 (&ZIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 23:
		{
			EXP ZI1281;

			/* BEGINNING OF EXTRACT: complex-exp */
			{
#line 355 "syntax.act"

    IDENTIFIER id = crt_token->pp_data.tok.id ;
    PPTOKEN *args = crt_token->pp_data.tok.args ;
    ZI1281 = parse_exp_token ( id, args ) ;
    RESCAN_LEXER ;
#line 287 "syntax4.c"
			}
			/* END OF EXTRACT: complex-exp */
			ADVANCE_LEXER;
			ZR1242 (ZI1281, &ZIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 25:
		{
			TYPE ZI1267;
			BASE_TYPE ZIbt;
			CV_SPEC ZIcv;
			TYPE ZIt;
			SID_LIST_EXP ZIp;
			EXP ZI1284;

			/* BEGINNING OF EXTRACT: complex-type */
			{
#line 369 "syntax.act"

    IDENTIFIER id = crt_token->pp_data.tok.id ;
    PPTOKEN *args = crt_token->pp_data.tok.args ;
    ZI1267 = parse_type_token ( id, args ) ;
    have_type_declaration = TYPE_DECL_NONE ;
    have_type_specifier = 1 ;
    RESCAN_LEXER ;
#line 317 "syntax4.c"
			}
			/* END OF EXTRACT: complex-type */
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: btype_none */
			{
#line 1252 "syntax.act"
 (ZIbt) = btype_none ; 
#line 325 "syntax4.c"
			}
			/* END OF ACTION: btype_none */
			/* BEGINNING OF ACTION: cv_none */
			{
#line 1220 "syntax.act"
 (ZIcv) = cv_none ; 
#line 332 "syntax4.c"
			}
			/* END OF ACTION: cv_none */
			/* BEGINNING OF ACTION: type_complete */
			{
#line 1321 "syntax.act"

    (ZIt) = complete_pre_type ( (ZIbt), (ZI1267), (ZIcv), 1 ) ;
    have_type_specifier = 0 ;
#line 341 "syntax4.c"
			}
			/* END OF ACTION: type_complete */
			switch (CURRENT_TERMINAL) {
			case 65:
				break;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
			ZRexpression_Hlist_Hopt (&ZIp);
			switch (CURRENT_TERMINAL) {
			case 39:
				break;
			case 355:
				RESTORE_LEXER;
				goto ZL1;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: exp_func_cast */
			{
#line 680 "syntax.act"

    (ZI1284) = make_func_cast_exp ( (ZIt), (ZIp) ) ;
#line 367 "syntax4.c"
			}
			/* END OF ACTION: exp_func_cast */
			ZR1242 (ZI1284, &ZIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 130:
		{
			TYPE ZIt;
			EXP ZIa;
			int ZIn;
			EXP ZI1273;

			ADVANCE_LEXER;
			ZRcast_Hoperand (&ZIt, &ZIa, &ZIn);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: exp_const_cast */
			{
#line 628 "syntax.act"

    /* n is the number of type definitions in t */
    (ZI1273) = make_const_cast_exp ( (ZIt), (ZIa), (ZIn) ) ;
#line 396 "syntax4.c"
			}
			/* END OF ACTION: exp_const_cast */
			ZR1242 (ZI1273, &ZIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 206:
		{
			EXP ZIa;

			ADVANCE_LEXER;
			ZRcast_Hexpression (&ZIa);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: exp_ignore */
			{
#line 688 "syntax.act"

    (ZIe) = make_cast_exp ( type_void, (ZIa), 0 ) ;
#line 421 "syntax4.c"
			}
			/* END OF ACTION: exp_ignore */
		}
		break;
	case 132:
		{
			TYPE ZIt;
			EXP ZIa;
			int ZIn;
			EXP ZI1276;

			ADVANCE_LEXER;
			ZRcast_Hoperand (&ZIt, &ZIa, &ZIn);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: exp_dynamic_cast */
			{
#line 654 "syntax.act"

    /* n is the number of type definitions in t */
    (ZI1276) = make_dynamic_cast_exp ( (ZIt), (ZIa), (ZIn) ) ;
#line 445 "syntax4.c"
			}
			/* END OF ACTION: exp_dynamic_cast */
			ZR1242 (ZI1276, &ZIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 210:
		{
			EXP ZI1279;

			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: exp_ellipsis */
			{
#line 658 "syntax.act"

    (ZI1279) = make_ellipsis_exp () ;
#line 465 "syntax4.c"
			}
			/* END OF ACTION: exp_ellipsis */
			ZR1242 (ZI1279, &ZIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 9:
		{
			NAMESPACE ZIns;

			/* BEGINNING OF EXTRACT: full-name */
			{
#line 266 "syntax.act"

    ZIns = crt_token->pp_data.ns ;
#line 484 "syntax4.c"
			}
			/* END OF EXTRACT: full-name */
			ADVANCE_LEXER;
			ZR1269 (&ZIns, &ZIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 255:
		{
			EXP ZIa;

			ADVANCE_LEXER;
			ZRcast_Hexpression (&ZIa);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: exp_lit */
			{
#line 704 "syntax.act"

    (ZIe) = make_lit_exp ( (ZIa) ) ;
#line 510 "syntax4.c"
			}
			/* END OF ACTION: exp_lit */
		}
		break;
	case 61:
		{
			EXP ZIa;

			ADVANCE_LEXER;
			ZRcast_Hexpression (&ZIa);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: exp_predec */
			{
#line 785 "syntax.act"

    (ZIe) = make_prefix_exp ( lex_minus_Hminus, (ZIa) ) ;
#line 530 "syntax4.c"
			}
			/* END OF ACTION: exp_predec */
		}
		break;
	case 8:
		{
			NAMESPACE ZIns;

			/* BEGINNING OF EXTRACT: nested-name */
			{
#line 262 "syntax.act"

    ZIns = crt_token->pp_data.ns ;
#line 544 "syntax4.c"
			}
			/* END OF EXTRACT: nested-name */
			ADVANCE_LEXER;
			ZR1268 (&ZIns, &ZIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 65:
		{
			ADVANCE_LEXER;
			ZR1288 (&ZIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 71:
		{
			EXP ZIa;

			ADVANCE_LEXER;
			ZRcast_Hexpression (&ZIa);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: exp_preinc */
			{
#line 789 "syntax.act"

    (ZIe) = make_prefix_exp ( lex_plus_Hplus, (ZIa) ) ;
#line 580 "syntax4.c"
			}
			/* END OF ACTION: exp_preinc */
		}
		break;
	case 145:
		{
			TYPE ZIt;
			EXP ZIa;
			int ZIn;
			EXP ZI1274;

			ADVANCE_LEXER;
			ZRcast_Hoperand (&ZIt, &ZIa, &ZIn);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: exp_reinterpret_cast */
			{
#line 802 "syntax.act"

    /* n is the number of type definitions in t */
    (ZI1274) = make_reinterp_cast_exp ( (ZIt), (ZIa), (ZIn) ) ;
#line 604 "syntax4.c"
			}
			/* END OF ACTION: exp_reinterpret_cast */
			ZR1242 (ZI1274, &ZIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 116:
		{
			int ZIop;

			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: lex_sizeof */
			{
#line 403 "syntax.act"
 (ZIop) = lex_sizeof ; 
#line 623 "syntax4.c"
			}
			/* END OF ACTION: lex_sizeof */
			ZRsizeof_Hexpression (ZIop, &ZIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 78:
		{
			EXP ZIa;

			ADVANCE_LEXER;
			ZRcast_Hexpression (&ZIa);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: exp_indir */
			{
#line 696 "syntax.act"

    (ZIe) = make_indir_exp ( (ZIa) ) ;
#line 648 "syntax4.c"
			}
			/* END OF ACTION: exp_indir */
		}
		break;
	case 146:
		{
			TYPE ZIt;
			EXP ZIa;
			int ZIn;
			EXP ZI1275;

			ADVANCE_LEXER;
			ZRcast_Hoperand (&ZIt, &ZIa, &ZIn);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: exp_static_cast */
			{
#line 827 "syntax.act"

    (ZI1275) = make_static_cast_exp ( (ZIt), (ZIa), (ZIn) ) ;
#line 671 "syntax4.c"
			}
			/* END OF ACTION: exp_static_cast */
			ZR1242 (ZI1275, &ZIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 148:
		{
			EXP ZI1278;

			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: exp_this */
			{
#line 831 "syntax.act"

    (ZI1278) = make_this_exp () ;
#line 691 "syntax4.c"
			}
			/* END OF ACTION: exp_this */
			ZR1242 (ZI1278, &ZIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 152:
		{
			int ZIop;
			EXP ZI1272;

			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: lex_typeid */
			{
#line 404 "syntax.act"
 (ZIop) = lex_typeid ; 
#line 711 "syntax4.c"
			}
			/* END OF ACTION: lex_typeid */
			ZRtypeid_Hexpression (ZIop, &ZI1272);
			ZR1242 (ZI1272, &ZIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 330:
		{
			int ZIop;
			EXP ZI1271;

			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: lex_vtable */
			{
#line 405 "syntax.act"
 (ZIop) = lex_vtable ; 
#line 732 "syntax4.c"
			}
			/* END OF ACTION: lex_vtable */
			ZRtypeid_Hexpression (ZIop, &ZI1271);
			ZR1242 (ZI1271, &ZIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 33:
		{
			EXP ZIa;

			/* BEGINNING OF INLINE: and */
			{
				{
					switch (CURRENT_TERMINAL) {
					case 33:
						break;
					default:
						goto ZL1;
					}
					ADVANCE_LEXER;
				}
			}
			/* END OF INLINE: and */
			ZRcast_Hexpression (&ZIa);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: exp_ref */
			{
#line 797 "syntax.act"

    (ZIe) = make_ref_exp ( (ZIa), 0 ) ;
#line 770 "syntax4.c"
			}
			/* END OF ACTION: exp_ref */
		}
		break;
	case 97: case 102: case 106: case 110:
	case 111: case 114: case 115: case 122:
	case 123: case 127: case 156: case 185:
	case 286: case 299:
		{
			BASE_TYPE ZIbt;
			TYPE ZI1267;
			CV_SPEC ZIcv;
			TYPE ZIt;
			SID_LIST_EXP ZIp;
			EXP ZI1282;

			ZRbase_Htype_Hspecifier (&ZIbt);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: type_pre */
			{
#line 1280 "syntax.act"

    (ZI1267) = NULL_type ;
    have_type_specifier = 1 ;
#line 798 "syntax4.c"
			}
			/* END OF ACTION: type_pre */
			/* BEGINNING OF ACTION: cv_none */
			{
#line 1220 "syntax.act"
 (ZIcv) = cv_none ; 
#line 805 "syntax4.c"
			}
			/* END OF ACTION: cv_none */
			/* BEGINNING OF ACTION: type_complete */
			{
#line 1321 "syntax.act"

    (ZIt) = complete_pre_type ( (ZIbt), (ZI1267), (ZIcv), 1 ) ;
    have_type_specifier = 0 ;
#line 814 "syntax4.c"
			}
			/* END OF ACTION: type_complete */
			switch (CURRENT_TERMINAL) {
			case 65:
				break;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
			ZRexpression_Hlist_Hopt (&ZIp);
			switch (CURRENT_TERMINAL) {
			case 39:
				break;
			case 355:
				RESTORE_LEXER;
				goto ZL1;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: exp_func_cast */
			{
#line 680 "syntax.act"

    (ZI1282) = make_func_cast_exp ( (ZIt), (ZIp) ) ;
#line 840 "syntax4.c"
			}
			/* END OF ACTION: exp_func_cast */
			ZR1242 (ZI1282, &ZIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 17: case 18: case 19: case 20:
	case 21: case 22: case 135: case 150:
		{
			EXP ZI1277;

			ZRliteral (&ZI1277);
			ZR1242 (ZI1277, &ZIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 62:
		{
			EXP ZIa;

			/* BEGINNING OF INLINE: not */
			{
				{
					switch (CURRENT_TERMINAL) {
					case 62:
						break;
					default:
						goto ZL1;
					}
					ADVANCE_LEXER;
				}
			}
			/* END OF INLINE: not */
			ZRcast_Hexpression (&ZIa);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: exp_not */
			{
#line 756 "syntax.act"

    (ZIe) = make_not_exp ( (ZIa) ) ;
#line 890 "syntax4.c"
			}
			/* END OF ACTION: exp_not */
		}
		break;
	case 1: case 3: case 5: case 6:
	case 141:
		{
			IDENTIFIER ZIid;
			EXP ZI1285;

			ZRunqualified_Hid (&ZIid);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: exp_identifier */
			{
#line 684 "syntax.act"

    (ZI1285) = make_id_exp ( (ZIid) ) ;
#line 911 "syntax4.c"
			}
			/* END OF ACTION: exp_identifier */
			ZR1242 (ZI1285, &ZIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 2: case 7:
		{
			IDENTIFIER ZIid;
			TYPE ZI1267;
			BASE_TYPE ZIbt;
			CV_SPEC ZIcv;
			TYPE ZIt;
			SID_LIST_EXP ZIp;
			EXP ZI1283;

			ZRunqualified_Htype (&ZIid);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: type_name */
			{
#line 1285 "syntax.act"

    MAKE_type_pre ( cv_none, btype_alias, crt_id_qualifier, (ZI1267) ) ;
    COPY_id ( type_name ( (ZI1267) ), (ZIid) ) ;
    have_type_specifier = 1 ;
#line 943 "syntax4.c"
			}
			/* END OF ACTION: type_name */
			/* BEGINNING OF ACTION: btype_none */
			{
#line 1252 "syntax.act"
 (ZIbt) = btype_none ; 
#line 950 "syntax4.c"
			}
			/* END OF ACTION: btype_none */
			/* BEGINNING OF ACTION: cv_none */
			{
#line 1220 "syntax.act"
 (ZIcv) = cv_none ; 
#line 957 "syntax4.c"
			}
			/* END OF ACTION: cv_none */
			/* BEGINNING OF ACTION: type_complete */
			{
#line 1321 "syntax.act"

    (ZIt) = complete_pre_type ( (ZIbt), (ZI1267), (ZIcv), 1 ) ;
    have_type_specifier = 0 ;
#line 966 "syntax4.c"
			}
			/* END OF ACTION: type_complete */
			switch (CURRENT_TERMINAL) {
			case 65:
				break;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
			ZRexpression_Hlist_Hopt (&ZIp);
			switch (CURRENT_TERMINAL) {
			case 39:
				break;
			case 355:
				RESTORE_LEXER;
				goto ZL1;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: exp_func_cast */
			{
#line 680 "syntax.act"

    (ZI1283) = make_func_cast_exp ( (ZIt), (ZIp) ) ;
#line 992 "syntax4.c"
			}
			/* END OF ACTION: exp_func_cast */
			ZR1242 (ZI1283, &ZIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 131: case 140:
		{
			int ZIb;

			/* BEGINNING OF ACTION: bool_false */
			{
#line 2049 "syntax.act"
 (ZIb) = 0 ; 
#line 1010 "syntax4.c"
			}
			/* END OF ACTION: bool_false */
			ZR1432 (&ZIb, &ZIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 43: case 59: case 69: case 85:
		{
			int ZIop;
			EXP ZIa;

			/* BEGINNING OF ACTION: lex_crt */
			{
#line 389 "syntax.act"
 (ZIop) = crt_lex_token ; 
#line 1029 "syntax4.c"
			}
			/* END OF ACTION: lex_crt */
			ZRunary_Hoperator ();
			ZRcast_Hexpression (&ZIa);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: exp_unary */
			{
#line 855 "syntax.act"

    (ZIe) = make_uminus_exp ( (ZIop), (ZIa) ) ;
#line 1043 "syntax4.c"
			}
			/* END OF ACTION: exp_unary */
		}
		break;
	case 355:
		return;
	default:
		goto ZL1;
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZOe = ZIe;
}

void
ZRtype_Hspecifier(TYPE ZIs, BASE_TYPE *ZObt, TYPE *ZOt, CV_SPEC *ZOcv)
{
	BASE_TYPE ZIbt;
	TYPE ZIt;
	CV_SPEC ZIcv;

	switch (CURRENT_TERMINAL) {
	case 104:
		{
			ADVANCE_LEXER;
			ZR1327 (&ZIs, &ZIbt, &ZIt, &ZIcv);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 153:
		{
			NAMESPACE ZIns;
			IDENTIFIER ZIid;

			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: declarator_start */
			{
#line 1704 "syntax.act"

    crt_templ_qualifier = 0 ;
#line 1090 "syntax4.c"
			}
			/* END OF ACTION: declarator_start */
			ZRany_Hnested_Hname_Hopt (&ZIns);
			ZRany_Hclass_Hname (&ZIid);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: type_typename */
			{
#line 1300 "syntax.act"

    (ZIt) = make_typename ( (ZIns), (ZIid) ) ;
    if ( have_type_declaration == TYPE_DECL_NONE ) {
	have_type_declaration = TYPE_DECL_ELABORATE ;
	found_elaborate_type = 1 ;
    }
    have_type_specifier = 1 ;
#line 1109 "syntax4.c"
			}
			/* END OF ACTION: type_typename */
			/* BEGINNING OF ACTION: btype_none */
			{
#line 1252 "syntax.act"
 (ZIbt) = btype_none ; 
#line 1116 "syntax4.c"
			}
			/* END OF ACTION: btype_none */
			/* BEGINNING OF ACTION: cv_none */
			{
#line 1220 "syntax.act"
 (ZIcv) = cv_none ; 
#line 1123 "syntax4.c"
			}
			/* END OF ACTION: cv_none */
		}
		break;
	case 118: case 121: case 129:
		{
			BASE_TYPE ZIkey;

			ZRclass_Hkey (&ZIkey);
			ZR1326 (&ZIs, &ZIkey, &ZIbt, &ZIt, &ZIcv);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 98: case 124:
		{
			ZRcv_Hqualifier (&ZIcv);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: btype_none */
			{
#line 1252 "syntax.act"
 (ZIbt) = btype_none ; 
#line 1151 "syntax4.c"
			}
			/* END OF ACTION: btype_none */
			/* BEGINNING OF ACTION: type_none */
			{
#line 1276 "syntax.act"

    (ZIt) = NULL_type ;
#line 1159 "syntax4.c"
			}
			/* END OF ACTION: type_none */
		}
		break;
	case 2: case 7: case 8: case 9:
	case 25: case 83: case 97: case 102:
	case 106: case 110: case 111: case 114:
	case 115: case 122: case 123: case 127:
	case 156: case 185: case 286: case 299:
		{
			ZRsimple_Htype_Hspecifier (&ZIbt, &ZIt);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: cv_none */
			{
#line 1220 "syntax.act"
 (ZIcv) = cv_none ; 
#line 1179 "syntax4.c"
			}
			/* END OF ACTION: cv_none */
		}
		break;
	case 355:
		return;
	default:
		goto ZL1;
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZObt = ZIbt;
	*ZOt = ZIt;
	*ZOcv = ZIcv;
}

void
ZRparameter_Hdeclaration_Hclause(int *ZOell)
{
	int ZIell;

	switch (CURRENT_TERMINAL) {
	case 2: case 7: case 8: case 9:
	case 25: case 47: case 83: case 94:
	case 97: case 98: case 102: case 104:
	case 105: case 106: case 110: case 111:
	case 112: case 114: case 115: case 117:
	case 118: case 120: case 121: case 122:
	case 123: case 124: case 127: case 129:
	case 133: case 136: case 137: case 138:
	case 153: case 155: case 156: case 185:
	case 275: case 286: case 299:
		{
			ZRparameter_Hdeclaration_Hlist (&ZIell);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	default:
		{
			/* BEGINNING OF ACTION: bool_false */
			{
#line 2049 "syntax.act"
 (ZIell) = 0 ; 
#line 1229 "syntax4.c"
			}
			/* END OF ACTION: bool_false */
		}
		break;
	case 355:
		return;
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZOell = ZIell;
}

void
ZRabstract_Hdeclarator_Hopt(TYPE ZIp, TYPE *ZOt)
{
	TYPE ZIt;

	switch (CURRENT_TERMINAL) {
	case 10: case 11: case 33: case 65:
	case 66: case 78: case 332:
		{
			TYPE ZIq;

			ZRabstract_Hdeclarator_Haux (&ZIq);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: type_inject */
			{
#line 1393 "syntax.act"

    (ZIt) = ( IS_NULL_type ( (ZIq) ) ? (ZIp) : inject_pre_type ( (ZIq), (ZIp), 1 ) ) ;
#line 1266 "syntax4.c"
			}
			/* END OF ACTION: type_inject */
		}
		break;
	default:
		{
			ZIt = ZIp;
		}
		break;
	case 355:
		return;
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZOt = ZIt;
}

void
ZR1323(int *ZOop)
{
	int ZIop;

	if ((CURRENT_TERMINAL) == 355) {
		return;
	}
	{
		/* BEGINNING OF ACTION: is_array */
		{
#line 2109 "syntax.act"

    /* Resolve 'operator new []' from 'operator new [3]' */
    (ZI0) = predict_array () ;
#line 1302 "syntax4.c"
		}
		/* END OF ACTION: is_array */
		if (!ZI0)
			goto ZL2;
		/* BEGINNING OF INLINE: open-square */
		{
			{
				switch (CURRENT_TERMINAL) {
				case 66:
					break;
				default:
					goto ZL1;
				}
				ADVANCE_LEXER;
			}
		}
		/* END OF INLINE: open-square */
		ZRclose_Hsquare_Hx ();
		if ((CURRENT_TERMINAL) == 355) {
			RESTORE_LEXER;
			goto ZL1;
		}
		/* BEGINNING OF ACTION: lex_delete_array */
		{
#line 402 "syntax.act"
 (ZIop) = lex_delete_Harray ; 
#line 1329 "syntax4.c"
		}
		/* END OF ACTION: lex_delete_array */
		goto ZL0;
	}
	/*UNREACHED*/
ZL2:;
	switch (CURRENT_TERMINAL) {
	default:
		{
			/* BEGINNING OF ACTION: lex_delete */
			{
#line 400 "syntax.act"
 (ZIop) = lex_delete ; 
#line 1343 "syntax4.c"
			}
			/* END OF ACTION: lex_delete */
		}
		break;
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZOop = ZIop;
}

void
ZRopen_Hround_Hx(void)
{
	if ((CURRENT_TERMINAL) == 355) {
		return;
	}
	{
		switch (CURRENT_TERMINAL) {
		case 65:
			break;
		default:
			goto ZL1;
		}
		ADVANCE_LEXER;
	}
	return;
ZL1:;
	{
		int ZIt;

		/* BEGINNING OF ACTION: lex_open_round */
		{
#line 394 "syntax.act"
 (ZIt) = lex_open_Hround ; 
#line 1381 "syntax4.c"
		}
		/* END OF ACTION: lex_open_round */
		/* BEGINNING OF ACTION: expected */
		{
#line 1995 "syntax.act"

    /* Expected symbol */
    int p = primary_form ( crt_lex_token ) ;
    if ( p != (ZIt) ) report ( crt_loc, ERR_lex_expect ( (ZIt) ) ) ;
#line 1391 "syntax4.c"
		}
		/* END OF ACTION: expected */
	}
}

void
ZR1198(EXP ZI1196, EXP *ZO1197)
{
	EXP ZI1197;

ZL2_1198:;
	switch (CURRENT_TERMINAL) {
	case 55:
		{
			EXP ZIb;
			EXP ZIe;

			/* BEGINNING OF INLINE: logical-and */
			{
				{
					switch (CURRENT_TERMINAL) {
					case 55:
						break;
					default:
						goto ZL1;
					}
					ADVANCE_LEXER;
				}
			}
			/* END OF INLINE: logical-and */
			ZRinclusive_Hor_Hexpression (&ZIb);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: exp_log_and */
			{
#line 712 "syntax.act"

    (ZIe) = make_log_and_exp ( (ZI1196), (ZIb) ) ;
#line 1432 "syntax4.c"
			}
			/* END OF ACTION: exp_log_and */
			/* BEGINNING OF INLINE: 1198 */
			ZI1196 = ZIe;
			goto ZL2_1198;
			/* END OF INLINE: 1198 */
		}
		/*UNREACHED*/
	default:
		{
			ZI1197 = ZI1196;
		}
		break;
	case 355:
		return;
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZO1197 = ZI1197;
}

void
ZRenumerator_Hlist(IDENTIFIER ZIe)
{
	if ((CURRENT_TERMINAL) == 355) {
		return;
	}
ZL2_enumerator_Hlist:;
	{
		ZRenumerator_Hdefinition (ZIe);
		/* BEGINNING OF INLINE: 869 */
		{
			switch (CURRENT_TERMINAL) {
			case 42:
				{
					ADVANCE_LEXER;
					/* BEGINNING OF INLINE: 1391 */
					{
						switch (CURRENT_TERMINAL) {
						case 42:
							{
								ADVANCE_LEXER;
								/* BEGINNING OF ACTION: error_comma */
								{
#line 1985 "syntax.act"

    /* Extra comma at the end of a list */
    report ( crt_loc, ERR_lex_extra_comma () ) ;
#line 1484 "syntax4.c"
								}
								/* END OF ACTION: error_comma */
								/* BEGINNING OF INLINE: enumerator-list */
								goto ZL2_enumerator_Hlist;
								/* END OF INLINE: enumerator-list */
							}
							/*UNREACHED*/
						case 1: case 2: case 3: case 4:
							{
								/* BEGINNING OF INLINE: enumerator-list */
								goto ZL2_enumerator_Hlist;
								/* END OF INLINE: enumerator-list */
							}
							/*UNREACHED*/
						default:
							{
								/* BEGINNING OF ACTION: error_comma */
								{
#line 1985 "syntax.act"

    /* Extra comma at the end of a list */
    report ( crt_loc, ERR_lex_extra_comma () ) ;
#line 1507 "syntax4.c"
								}
								/* END OF ACTION: error_comma */
							}
							break;
						}
					}
					/* END OF INLINE: 1391 */
				}
				break;
			case 355:
				RESTORE_LEXER;
				goto ZL1;
			default:
				break;
			}
		}
		/* END OF INLINE: 869 */
	}
	return;
ZL1:;
	SAVE_LEXER (355);
	return;
}

void
ZR1326(TYPE *ZIs, BASE_TYPE *ZIkey, BASE_TYPE *ZObt, TYPE *ZOt, CV_SPEC *ZOcv)
{
	BASE_TYPE ZIbt;
	TYPE ZIt;
	CV_SPEC ZIcv;

	if ((CURRENT_TERMINAL) == 355) {
		return;
	}
	{
		IDENTIFIER ZIid;
		QUALIFIER ZIqu;
		int ZIi;
		DECL_SPEC ZIb;
		IDENTIFIER ZIp;
		int ZIf;
		int ZI1324;
		DECL_SPEC ZIds;
		TYPE ZI1325;
		IDENTIFIER ZIc;

		/* BEGINNING OF ACTION: is_class_spec */
		{
#line 2067 "syntax.act"

    /* Resolve class-specifiers from elaborated-type-specifiers */
    (ZI0) = predict_class ( 1 ) ;
#line 1560 "syntax4.c"
		}
		/* END OF ACTION: is_class_spec */
		if (!ZI0)
			goto ZL2;
		/* BEGINNING OF ACTION: declarator_start */
		{
#line 1704 "syntax.act"

    crt_templ_qualifier = 0 ;
#line 1570 "syntax4.c"
		}
		/* END OF ACTION: declarator_start */
		ZR871 (&ZIid);
		if ((CURRENT_TERMINAL) == 355) {
			RESTORE_LEXER;
			goto ZL1;
		}
		/* BEGINNING OF ACTION: qual_get */
		{
#line 536 "syntax.act"

    (ZIqu) = crt_id_qualifier ;
    (ZIi) = crt_templ_qualifier ;
#line 1584 "syntax4.c"
		}
		/* END OF ACTION: qual_get */
		/* BEGINNING OF ACTION: template_decl */
		{
#line 1864 "syntax.act"

    if ( !IS_NULL_type ( (*ZIs) ) ) template_decl ( (*ZIs) ) ;
#line 1592 "syntax4.c"
		}
		/* END OF ACTION: template_decl */
		/* BEGINNING OF ACTION: access_get */
		{
#line 1453 "syntax.act"
 (ZIb) = crt_access ; 
#line 1599 "syntax4.c"
		}
		/* END OF ACTION: access_get */
		/* BEGINNING OF ACTION: type_class_begin */
		{
#line 1497 "syntax.act"

    IDENTIFIER id = constr_name ( last_namespace, (ZIid) ) ;
    (ZIp) = begin_class_defn ( id, (*ZIkey), cinfo_none, (*ZIs) ) ;
    (ZIf) = in_function_defn ;
    in_function_defn = 0 ;
    in_class_defn++ ;
    really_in_class_defn++ ;
    no_type_defns++ ;
#line 1613 "syntax4.c"
		}
		/* END OF ACTION: type_class_begin */
		ZRbase_Hclause_Hopt (&ZI1324);
		if ((CURRENT_TERMINAL) == 355) {
			RESTORE_LEXER;
			goto ZL1;
		}
		/* BEGINNING OF ACTION: class_base_end */
		{
#line 1518 "syntax.act"

    end_base_class ( crt_class, (ZI1324) ) ;
#line 1626 "syntax4.c"
		}
		/* END OF ACTION: class_base_end */
		/* BEGINNING OF ACTION: dspec_none */
		{
#line 1544 "syntax.act"
 (ZIds) = dspec_none ; 
#line 1633 "syntax4.c"
		}
		/* END OF ACTION: dspec_none */
		/* BEGINNING OF ACTION: type_none */
		{
#line 1276 "syntax.act"

    (ZI1325) = NULL_type ;
#line 1641 "syntax4.c"
		}
		/* END OF ACTION: type_none */
		/* BEGINNING OF INLINE: open-brace */
		{
			{
				switch (CURRENT_TERMINAL) {
				case 64:
					break;
				default:
					goto ZL1;
				}
				ADVANCE_LEXER;
			}
		}
		/* END OF INLINE: open-brace */
		ZRmember_Hspecification_Hopt (ZI1325, ZIds);
		/* BEGINNING OF INLINE: close-brace */
		{
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			{
				switch (CURRENT_TERMINAL) {
				case 38:
					break;
				default:
					goto ZL1;
				}
				ADVANCE_LEXER;
			}
		}
		/* END OF INLINE: close-brace */
		/* BEGINNING OF ACTION: access_check_class */
		{
#line 1467 "syntax.act"

    if ( crt_access_list.pending ) {
	IDENTIFIER id = DEREF_id ( ctype_name ( crt_class ) ) ;
	IGNORE report_access ( id ) ;
    }
#line 1683 "syntax4.c"
		}
		/* END OF ACTION: access_check_class */
		/* BEGINNING OF ACTION: type_class_end */
		{
#line 1507 "syntax.act"

    (ZIc) = end_class_defn ( (ZIp) ) ;
    in_function_defn = (ZIf) ;
    in_class_defn-- ;
    really_in_class_defn-- ;
#line 1694 "syntax4.c"
		}
		/* END OF ACTION: type_class_end */
		/* BEGINNING OF ACTION: access_set */
		{
#line 1454 "syntax.act"
 crt_access = (ZIb) ; 
#line 1701 "syntax4.c"
		}
		/* END OF ACTION: access_set */
		/* BEGINNING OF ACTION: qual_set */
		{
#line 541 "syntax.act"

    crt_id_qualifier = (ZIqu) ;
    crt_templ_qualifier = (ZIi) ;
#line 1710 "syntax4.c"
		}
		/* END OF ACTION: qual_set */
		/* BEGINNING OF ACTION: rescan_token */
		{
#line 2147 "syntax.act"

    RESCAN_LEXER ;
#line 1718 "syntax4.c"
		}
		/* END OF ACTION: rescan_token */
		/* BEGINNING OF ACTION: type_name */
		{
#line 1285 "syntax.act"

    MAKE_type_pre ( cv_none, btype_alias, crt_id_qualifier, (ZIt) ) ;
    COPY_id ( type_name ( (ZIt) ), (ZIc) ) ;
    have_type_specifier = 1 ;
#line 1728 "syntax4.c"
		}
		/* END OF ACTION: type_name */
		/* BEGINNING OF ACTION: btype_none */
		{
#line 1252 "syntax.act"
 (ZIbt) = btype_none ; 
#line 1735 "syntax4.c"
		}
		/* END OF ACTION: btype_none */
		/* BEGINNING OF ACTION: cv_none */
		{
#line 1220 "syntax.act"
 (ZIcv) = cv_none ; 
#line 1742 "syntax4.c"
		}
		/* END OF ACTION: cv_none */
		goto ZL0;
	}
	/*UNREACHED*/
ZL2:;
	switch (CURRENT_TERMINAL) {
	case 1: case 2: case 3: case 4:
	case 7: case 8: case 9: case 83:
		{
			NAMESPACE ZIns;
			IDENTIFIER ZIaid;
			IDENTIFIER ZIid;

			/* BEGINNING OF ACTION: declarator_start */
			{
#line 1704 "syntax.act"

    crt_templ_qualifier = 0 ;
#line 1762 "syntax4.c"
			}
			/* END OF ACTION: declarator_start */
			ZRany_Hnested_Hname_Hopt (&ZIns);
			ZRany_Hclass_Hname (&ZIaid);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: namespace_id */
			{
#line 502 "syntax.act"

    (ZIid) = check_id ( (ZIns), (ZIaid), 0 ) ;
    last_namespace = (ZIns) ;
#line 1777 "syntax4.c"
			}
			/* END OF ACTION: namespace_id */
			/* BEGINNING OF ACTION: type_elaborate */
			{
#line 1291 "syntax.act"

    MAKE_type_pre ( cv_none, (*ZIkey), crt_id_qualifier, (ZIt) ) ;
    COPY_id ( type_name ( (ZIt) ), (ZIid) ) ;
    if ( have_type_declaration == TYPE_DECL_NONE ) {
	have_type_declaration = TYPE_DECL_ELABORATE ;
    }
    have_type_specifier = 1 ;
#line 1790 "syntax4.c"
			}
			/* END OF ACTION: type_elaborate */
			/* BEGINNING OF ACTION: btype_none */
			{
#line 1252 "syntax.act"
 (ZIbt) = btype_none ; 
#line 1797 "syntax4.c"
			}
			/* END OF ACTION: btype_none */
			/* BEGINNING OF ACTION: cv_none */
			{
#line 1220 "syntax.act"
 (ZIcv) = cv_none ; 
#line 1804 "syntax4.c"
			}
			/* END OF ACTION: cv_none */
		}
		break;
	default:
		goto ZL1;
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZObt = ZIbt;
	*ZOt = ZIt;
	*ZOcv = ZIcv;
}

void
ZRfor_Hinit_Hstatement(EXP *ZOe)
{
	EXP ZIe;

	if ((CURRENT_TERMINAL) == 355) {
		return;
	}
	{
		DECL_SPEC ZIds;
		TYPE ZIt;
		EXP ZIa;

		/* BEGINNING OF ACTION: is_decl_statement */
		{
#line 2084 "syntax.act"

    /* Resolve declaration-statements from expression-statements */
    int b = predict_decl () ;
    if ( b ) in_declaration++ ;
    (ZI0) = b ;
#line 1843 "syntax4.c"
		}
		/* END OF ACTION: is_decl_statement */
		if (!ZI0)
			goto ZL2;
		/* BEGINNING OF ACTION: dspec_none */
		{
#line 1544 "syntax.act"
 (ZIds) = dspec_none ; 
#line 1852 "syntax4.c"
		}
		/* END OF ACTION: dspec_none */
		/* BEGINNING OF ACTION: type_none */
		{
#line 1276 "syntax.act"

    (ZIt) = NULL_type ;
#line 1860 "syntax4.c"
		}
		/* END OF ACTION: type_none */
		ZRdeclaration_Hbasic (ZIt, ZIds);
		if ((CURRENT_TERMINAL) == 355) {
			RESTORE_LEXER;
			goto ZL1;
		}
		/* BEGINNING OF ACTION: exp_none */
		{
#line 579 "syntax.act"

    (ZIa) = NULL_exp ;
#line 1873 "syntax4.c"
		}
		/* END OF ACTION: exp_none */
		/* BEGINNING OF ACTION: stmt_decl */
		{
#line 929 "syntax.act"

    (ZIe) = (ZIa) ;
    in_declaration-- ;
#line 1882 "syntax4.c"
		}
		/* END OF ACTION: stmt_decl */
		goto ZL0;
	}
	/*UNREACHED*/
ZL2:;
	switch (CURRENT_TERMINAL) {
	case 1: case 2: case 3: case 5:
	case 6: case 7: case 8: case 9:
	case 17: case 18: case 19: case 20:
	case 21: case 22: case 23: case 25:
	case 33: case 43: case 59: case 61:
	case 62: case 65: case 69: case 71:
	case 77: case 78: case 83: case 85:
	case 97: case 102: case 106: case 110:
	case 111: case 114: case 115: case 116:
	case 122: case 123: case 127: case 130:
	case 131: case 132: case 135: case 140:
	case 141: case 145: case 146: case 148:
	case 149: case 150: case 152: case 156:
	case 170: case 185: case 206: case 210:
	case 255: case 286: case 298: case 299:
	case 324: case 330: case 346:
		{
			ZRexpression_Hstatement (&ZIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	default:
		goto ZL1;
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZOe = ZIe;
}

void
ZRfunction_Htry_Hblock(EXP *ZOe)
{
	EXP ZIe;

	if ((CURRENT_TERMINAL) == 355) {
		return;
	}
	{
		int ZIr;
		EXP ZIa;
		EXP ZIb;
		EXP ZIf;
		EXP ZIc;
		EXP ZId;

		switch (CURRENT_TERMINAL) {
		case 151:
			break;
		default:
			goto ZL1;
		}
		ADVANCE_LEXER;
		/* BEGINNING OF ACTION: reach_check */
		{
#line 1121 "syntax.act"

    (ZIr) = unreached_code ;
    if ( (ZIr) ) {
	if ( !unreached_last ) {
	    report ( crt_loc, ERR_stmt_stmt_unreach () ) ;
	    unreached_last = 1 ;
	}
    } else {
	unreached_last = 0 ;
    }
#line 1961 "syntax4.c"
		}
		/* END OF ACTION: reach_check */
		/* BEGINNING OF ACTION: stmt_try_func */
		{
#line 1041 "syntax.act"

    (ZIa) = begin_try_stmt ( 1 ) ;
#line 1969 "syntax4.c"
		}
		/* END OF ACTION: stmt_try_func */
		/* BEGINNING OF ACTION: stmt_compound_begin */
		{
#line 905 "syntax.act"

    (ZIb) = begin_compound_stmt ( 1 ) ;
#line 1977 "syntax4.c"
		}
		/* END OF ACTION: stmt_compound_begin */
		/* BEGINNING OF ACTION: stmt_try_inject */
		{
#line 1045 "syntax.act"

    inject_try_stmt ( (ZIa) ) ;
#line 1985 "syntax4.c"
		}
		/* END OF ACTION: stmt_try_inject */
		ZRfunction_Hbody (ZIb, &ZIf);
		if ((CURRENT_TERMINAL) == 355) {
			RESTORE_LEXER;
			goto ZL1;
		}
		/* BEGINNING OF ACTION: stmt_compound_end */
		{
#line 921 "syntax.act"

    (ZIc) = end_compound_stmt ( (ZIf) ) ;
#line 1998 "syntax4.c"
		}
		/* END OF ACTION: stmt_compound_end */
		/* BEGINNING OF ACTION: stmt_try_cont */
		{
#line 1049 "syntax.act"

    (ZId) = cont_try_stmt ( (ZIa), (ZIc) ) ;
#line 2006 "syntax4.c"
		}
		/* END OF ACTION: stmt_try_cont */
		ZRhandler_Hseq_Hopt (ZId);
		if ((CURRENT_TERMINAL) == 355) {
			RESTORE_LEXER;
			goto ZL1;
		}
		/* BEGINNING OF ACTION: reach_prev */
		{
#line 1132 "syntax.act"
 unreached_prev = (ZIr) ; 
#line 2018 "syntax4.c"
		}
		/* END OF ACTION: reach_prev */
		/* BEGINNING OF ACTION: stmt_try_end */
		{
#line 1053 "syntax.act"

    (ZIe) = end_try_stmt ( (ZId), 0 ) ;
#line 2026 "syntax4.c"
		}
		/* END OF ACTION: stmt_try_end */
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZOe = ZIe;
}

void
ZRdesignator(OFFSET ZIb, TYPE ZIs, OFFSET *ZOa, TYPE *ZOt)
{
	OFFSET ZIa;
	TYPE ZIt;

	switch (CURRENT_TERMINAL) {
	case 46:
		{
			ADVANCE_LEXER;
			ZRmember_Hdesignator (ZIb, ZIs, &ZIa, &ZIt);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 66:
		{
			EXP ZIe;

			/* BEGINNING OF INLINE: open-square */
			{
				{
					switch (CURRENT_TERMINAL) {
					case 66:
						break;
					default:
						goto ZL1;
					}
					ADVANCE_LEXER;
				}
			}
			/* END OF INLINE: open-square */
			ZRconstant_Hexpression (&ZIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: offset_index */
			{
#line 1884 "syntax.act"

    OFFSET off = offset_index ( (ZIs), (ZIe), &(ZIt) ) ;
    (ZIa) = offset_add ( (ZIb), off ) ;
#line 2083 "syntax4.c"
			}
			/* END OF ACTION: offset_index */
			/* BEGINNING OF INLINE: close-square */
			{
				{
					switch (CURRENT_TERMINAL) {
					case 40:
						break;
					default:
						goto ZL1;
					}
					ADVANCE_LEXER;
				}
			}
			/* END OF INLINE: close-square */
		}
		break;
	case 355:
		return;
	default:
		goto ZL1;
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZOa = ZIa;
	*ZOt = ZIt;
}

void
ZR1327(TYPE *ZIs, BASE_TYPE *ZObt, TYPE *ZOt, CV_SPEC *ZOcv)
{
	BASE_TYPE ZIbt;
	TYPE ZIt;
	CV_SPEC ZIcv;

	if ((CURRENT_TERMINAL) == 355) {
		return;
	}
	{
		IDENTIFIER ZIid;
		QUALIFIER ZIqu;
		int ZIi;
		IDENTIFIER ZIp;
		IDENTIFIER ZIe;

		/* BEGINNING OF ACTION: is_enum_spec */
		{
#line 2089 "syntax.act"

    /* Resolve enum-specifiers from elaborated-type-specifiers */
    (ZI0) = predict_class ( 0 ) ;
#line 2138 "syntax4.c"
		}
		/* END OF ACTION: is_enum_spec */
		if (!ZI0)
			goto ZL2;
		/* BEGINNING OF ACTION: declarator_start */
		{
#line 1704 "syntax.act"

    crt_templ_qualifier = 0 ;
#line 2148 "syntax4.c"
		}
		/* END OF ACTION: declarator_start */
		ZR871 (&ZIid);
		if ((CURRENT_TERMINAL) == 355) {
			RESTORE_LEXER;
			goto ZL1;
		}
		/* BEGINNING OF ACTION: qual_get */
		{
#line 536 "syntax.act"

    (ZIqu) = crt_id_qualifier ;
    (ZIi) = crt_templ_qualifier ;
#line 2162 "syntax4.c"
		}
		/* END OF ACTION: qual_get */
		/* BEGINNING OF ACTION: type_enum_begin */
		{
#line 1522 "syntax.act"

    IDENTIFIER id = constr_name ( last_namespace, (ZIid) ) ;
    (ZIp) = begin_enum_defn ( id, (*ZIs) ) ;
    no_type_defns++ ;
#line 2172 "syntax4.c"
		}
		/* END OF ACTION: type_enum_begin */
		/* BEGINNING OF INLINE: open-brace */
		{
			{
				switch (CURRENT_TERMINAL) {
				case 64:
					break;
				default:
					goto ZL1;
				}
				ADVANCE_LEXER;
			}
		}
		/* END OF INLINE: open-brace */
		/* BEGINNING OF INLINE: 872 */
		{
			switch (CURRENT_TERMINAL) {
			case 1: case 2: case 3: case 4:
				{
					ZRenumerator_Hlist (ZIp);
					if ((CURRENT_TERMINAL) == 355) {
						RESTORE_LEXER;
						goto ZL1;
					}
				}
				break;
			default:
				break;
			}
		}
		/* END OF INLINE: 872 */
		/* BEGINNING OF INLINE: close-brace */
		{
			{
				switch (CURRENT_TERMINAL) {
				case 38:
					break;
				default:
					goto ZL1;
				}
				ADVANCE_LEXER;
			}
		}
		/* END OF INLINE: close-brace */
		/* BEGINNING OF ACTION: access_check */
		{
#line 1460 "syntax.act"

    if ( crt_access_list.pending ) {
	IGNORE report_access ( crt_func_id ) ;
    }
#line 2225 "syntax4.c"
		}
		/* END OF ACTION: access_check */
		/* BEGINNING OF ACTION: type_enum_end */
		{
#line 1528 "syntax.act"

    (ZIe) = end_enum_defn ( (ZIp) ) ;
#line 2233 "syntax4.c"
		}
		/* END OF ACTION: type_enum_end */
		/* BEGINNING OF ACTION: qual_set */
		{
#line 541 "syntax.act"

    crt_id_qualifier = (ZIqu) ;
    crt_templ_qualifier = (ZIi) ;
#line 2242 "syntax4.c"
		}
		/* END OF ACTION: qual_set */
		/* BEGINNING OF ACTION: type_name */
		{
#line 1285 "syntax.act"

    MAKE_type_pre ( cv_none, btype_alias, crt_id_qualifier, (ZIt) ) ;
    COPY_id ( type_name ( (ZIt) ), (ZIe) ) ;
    have_type_specifier = 1 ;
#line 2252 "syntax4.c"
		}
		/* END OF ACTION: type_name */
		/* BEGINNING OF ACTION: btype_none */
		{
#line 1252 "syntax.act"
 (ZIbt) = btype_none ; 
#line 2259 "syntax4.c"
		}
		/* END OF ACTION: btype_none */
		/* BEGINNING OF ACTION: cv_none */
		{
#line 1220 "syntax.act"
 (ZIcv) = cv_none ; 
#line 2266 "syntax4.c"
		}
		/* END OF ACTION: cv_none */
		goto ZL0;
	}
	/*UNREACHED*/
ZL2:;
	switch (CURRENT_TERMINAL) {
	case 1: case 2: case 3: case 4:
	case 7: case 8: case 9: case 83:
		{
			BASE_TYPE ZIkey;
			NAMESPACE ZIns;
			IDENTIFIER ZIaid;
			IDENTIFIER ZIid;

			/* BEGINNING OF ACTION: key_enum */
			{
#line 1437 "syntax.act"
 (ZIkey) = btype_enum ; 
#line 2286 "syntax4.c"
			}
			/* END OF ACTION: key_enum */
			/* BEGINNING OF ACTION: declarator_start */
			{
#line 1704 "syntax.act"

    crt_templ_qualifier = 0 ;
#line 2294 "syntax4.c"
			}
			/* END OF ACTION: declarator_start */
			ZRany_Hnested_Hname_Hopt (&ZIns);
			ZRany_Hclass_Hname (&ZIaid);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: namespace_id */
			{
#line 502 "syntax.act"

    (ZIid) = check_id ( (ZIns), (ZIaid), 0 ) ;
    last_namespace = (ZIns) ;
#line 2309 "syntax4.c"
			}
			/* END OF ACTION: namespace_id */
			/* BEGINNING OF ACTION: type_elaborate */
			{
#line 1291 "syntax.act"

    MAKE_type_pre ( cv_none, (ZIkey), crt_id_qualifier, (ZIt) ) ;
    COPY_id ( type_name ( (ZIt) ), (ZIid) ) ;
    if ( have_type_declaration == TYPE_DECL_NONE ) {
	have_type_declaration = TYPE_DECL_ELABORATE ;
    }
    have_type_specifier = 1 ;
#line 2322 "syntax4.c"
			}
			/* END OF ACTION: type_elaborate */
			/* BEGINNING OF ACTION: btype_none */
			{
#line 1252 "syntax.act"
 (ZIbt) = btype_none ; 
#line 2329 "syntax4.c"
			}
			/* END OF ACTION: btype_none */
			/* BEGINNING OF ACTION: cv_none */
			{
#line 1220 "syntax.act"
 (ZIcv) = cv_none ; 
#line 2336 "syntax4.c"
			}
			/* END OF ACTION: cv_none */
		}
		break;
	default:
		goto ZL1;
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZObt = ZIbt;
	*ZOt = ZIt;
	*ZOcv = ZIcv;
}

void
ZRrelational_Hexpression(EXP *ZO1221)
{
	EXP ZI1221;

	if ((CURRENT_TERMINAL) == 355) {
		return;
	}
	{
		EXP ZIe;

		ZRshift_Hexpression (&ZIe);
		ZR1222 (ZIe, &ZI1221);
		if ((CURRENT_TERMINAL) == 355) {
			RESTORE_LEXER;
			goto ZL1;
		}
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZO1221 = ZI1221;
}

void
ZRmember_Hdeclaration(TYPE ZIt, DECL_SPEC ZIds)
{
	if ((CURRENT_TERMINAL) == 355) {
		return;
	}
	{
		BASE_TYPE ZI1337;
		TYPE ZI1338;
		CV_SPEC ZI1339;
		DECL_SPEC ZI1340;
		BASE_TYPE ZIbt;
		TYPE ZIt1;
		CV_SPEC ZIcv1;
		DECL_SPEC ZIds1;
		DECL_SPEC ZIds2;

		/* BEGINNING OF ACTION: is_decl_specifier */
		{
#line 2077 "syntax.act"

    /* Resolve declaration-specifiers from other declarators */
    (ZI0) = predict_dspec ( 0 ) ;
#line 2403 "syntax4.c"
		}
		/* END OF ACTION: is_decl_specifier */
		if (!ZI0)
			goto ZL2;
		ZRdecl_Hspecifier (ZIt, &ZI1337, &ZI1338, &ZI1339, &ZI1340);
		ZR919 (&ZIt, &ZI1337, &ZI1338, &ZI1339, &ZI1340, &ZIbt, &ZIt1, &ZIcv1, &ZIds1);
		if ((CURRENT_TERMINAL) == 355) {
			RESTORE_LEXER;
			goto ZL1;
		}
		/* BEGINNING OF ACTION: dspec_join */
		{
#line 1560 "syntax.act"

    /* Combine two declaration specifiers */
    DECL_SPEC d = ( ( (ZIds) & (ZIds1) ) & dspec_duplicate ) ;
    if ( d ) report ( crt_loc, ERR_dcl_spec_dup ( d ) ) ;
    (ZIds2) = ( (ZIds) | (ZIds1) ) ;
#line 2422 "syntax4.c"
		}
		/* END OF ACTION: dspec_join */
		ZR1341 (&ZIt, &ZIbt, &ZIt1, &ZIcv1, &ZIds2);
		if ((CURRENT_TERMINAL) == 355) {
			RESTORE_LEXER;
			goto ZL1;
		}
		goto ZL0;
	}
	/*UNREACHED*/
ZL2:;
	switch (CURRENT_TERMINAL) {
	case 134: case 147:
		{
			ZRtemplate_Hmember_Hdecl (ZIt, ZIds);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 1: case 2: case 3: case 4:
	case 5: case 6: case 7: case 8:
	case 9: case 10: case 11: case 33:
	case 41: case 65: case 78: case 83:
	case 141:
		{
			BASE_TYPE ZIbt;
			TYPE ZIt1;
			CV_SPEC ZIcv1;
			DECL_SPEC ZIds1;
			DECL_SPEC ZIds2;
			TYPE ZIt2;
			DECL_SPEC ZIds3;
			TYPE ZIt3;
			ACCESS_LIST ZIr;
			int ZIf;
			IDENTIFIER ZId;

			/* BEGINNING OF ACTION: btype_none */
			{
#line 1252 "syntax.act"
 (ZIbt) = btype_none ; 
#line 2466 "syntax4.c"
			}
			/* END OF ACTION: btype_none */
			/* BEGINNING OF ACTION: type_none */
			{
#line 1276 "syntax.act"

    (ZIt1) = NULL_type ;
#line 2474 "syntax4.c"
			}
			/* END OF ACTION: type_none */
			/* BEGINNING OF ACTION: cv_none */
			{
#line 1220 "syntax.act"
 (ZIcv1) = cv_none ; 
#line 2481 "syntax4.c"
			}
			/* END OF ACTION: cv_none */
			/* BEGINNING OF ACTION: dspec_none */
			{
#line 1544 "syntax.act"
 (ZIds1) = dspec_none ; 
#line 2488 "syntax4.c"
			}
			/* END OF ACTION: dspec_none */
			/* BEGINNING OF ACTION: dspec_join */
			{
#line 1560 "syntax.act"

    /* Combine two declaration specifiers */
    DECL_SPEC d = ( ( (ZIds) & (ZIds1) ) & dspec_duplicate ) ;
    if ( d ) report ( crt_loc, ERR_dcl_spec_dup ( d ) ) ;
    (ZIds2) = ( (ZIds) | (ZIds1) ) ;
#line 2499 "syntax4.c"
			}
			/* END OF ACTION: dspec_join */
			/* BEGINNING OF ACTION: dspec_complete */
			{
#line 1571 "syntax.act"

    /* Complete a declaration specifier and a type */
    (ZIds3) = complete_dspec ( (ZIds2), (ZIbt), (ZIt1), (ZIcv1) ) ;
    (ZIt2) = complete_pre_type ( (ZIbt), (ZIt1), (ZIcv1), 0 ) ;
    have_type_specifier = 0 ;
#line 2510 "syntax4.c"
			}
			/* END OF ACTION: dspec_complete */
			/* BEGINNING OF ACTION: type_inject */
			{
#line 1393 "syntax.act"

    (ZIt3) = ( IS_NULL_type ( (ZIt) ) ? (ZIt2) : inject_pre_type ( (ZIt), (ZIt2), 1 ) ) ;
#line 2518 "syntax4.c"
			}
			/* END OF ACTION: type_inject */
			/* BEGINNING OF ACTION: access_return */
			{
#line 1480 "syntax.act"

    save_access ( &(ZIr) ) ;
#line 2526 "syntax4.c"
			}
			/* END OF ACTION: access_return */
			/* BEGINNING OF ACTION: bool_true */
			{
#line 2050 "syntax.act"
 (ZIf) = 1 ; 
#line 2533 "syntax4.c"
			}
			/* END OF ACTION: bool_true */
			/* BEGINNING OF ACTION: declarator_start */
			{
#line 1704 "syntax.act"

    crt_templ_qualifier = 0 ;
#line 2541 "syntax4.c"
			}
			/* END OF ACTION: declarator_start */
			ZRmember_Hdeclarator (ZIds3, ZIt3, ZIbt, ZIr, ZIf, &ZId);
			ZR1094 (&ZIbt, &ZIds3, &ZIt3, &ZIr, &ZId);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 154:
		{
			/* BEGINNING OF ACTION: template_check */
			{
#line 1859 "syntax.act"

    if ( !IS_NULL_type ( (ZIt) ) ) report ( crt_loc, ERR_temp_decl_bad () ) ;
    UNUSED ( (ZIds) ) ;
#line 2560 "syntax4.c"
			}
			/* END OF ACTION: template_check */
			ZRusing_Hdeclaration ();
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 77:
		{
			TYPE ZIt1;
			BASE_TYPE ZIbt;
			CV_SPEC ZIcv1;

			/* BEGINNING OF ACTION: type_none */
			{
#line 1276 "syntax.act"

    (ZIt1) = NULL_type ;
#line 2581 "syntax4.c"
			}
			/* END OF ACTION: type_none */
			/* BEGINNING OF ACTION: btype_none */
			{
#line 1252 "syntax.act"
 (ZIbt) = btype_none ; 
#line 2588 "syntax4.c"
			}
			/* END OF ACTION: btype_none */
			/* BEGINNING OF ACTION: cv_none */
			{
#line 1220 "syntax.act"
 (ZIcv1) = cv_none ; 
#line 2595 "syntax4.c"
			}
			/* END OF ACTION: cv_none */
			/* BEGINNING OF ACTION: declare_member_empty */
			{
#line 1671 "syntax.act"

    IGNORE empty_decl ( (ZIds), (ZIt), (ZIbt), (ZIt1), (ZIcv1), last_lex_token, 1 ) ;
    have_type_declaration = TYPE_DECL_NONE ;
    have_func_declarator = 0 ;
    have_type_specifier = 0 ;
#line 2606 "syntax4.c"
			}
			/* END OF ACTION: declare_member_empty */
			ADVANCE_LEXER;
		}
		break;
	default:
		goto ZL1;
	}
	return;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
}

void
ZR1328(int *ZOt)
{
	int ZIt;

	switch (CURRENT_TERMINAL) {
	case 1: case 2: case 3: case 4:
	case 7: case 8: case 9: case 83:
	case 142: case 143: case 144: case 155:
		{
			ZRbase_Hspecifier_Hlist ();
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: bool_true */
			{
#line 2050 "syntax.act"
 (ZIt) = 1 ; 
#line 2641 "syntax4.c"
			}
			/* END OF ACTION: bool_true */
		}
		break;
	default:
		{
			/* BEGINNING OF ACTION: bool_false */
			{
#line 2049 "syntax.act"
 (ZIt) = 0 ; 
#line 2652 "syntax4.c"
			}
			/* END OF ACTION: bool_false */
		}
		break;
	case 355:
		return;
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZOt = ZIt;
}

void
ZRfor_Hend_Hstatement(EXP *ZOe)
{
	EXP ZIe;

	switch (CURRENT_TERMINAL) {
	case 1: case 2: case 3: case 5:
	case 6: case 7: case 8: case 9:
	case 17: case 18: case 19: case 20:
	case 21: case 22: case 23: case 25:
	case 33: case 43: case 59: case 61:
	case 62: case 65: case 69: case 71:
	case 78: case 83: case 85: case 97:
	case 102: case 106: case 110: case 111:
	case 114: case 115: case 116: case 122:
	case 123: case 127: case 130: case 131:
	case 132: case 135: case 140: case 141:
	case 145: case 146: case 148: case 149:
	case 150: case 152: case 156: case 170:
	case 185: case 206: case 210: case 255:
	case 286: case 298: case 299: case 324:
	case 330: case 346:
		{
			EXP ZIa;
			EXP ZIb;

			ZRexpression (&ZIa);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: stmt_exp */
			{
#line 950 "syntax.act"

    (ZIb) = make_exp_stmt ( (ZIa) ) ;
#line 2704 "syntax4.c"
			}
			/* END OF ACTION: stmt_exp */
			/* BEGINNING OF ACTION: bind_temporary */
			{
#line 1085 "syntax.act"

    (ZIe) = bind_temporary ( (ZIb) ) ;
#line 2712 "syntax4.c"
			}
			/* END OF ACTION: bind_temporary */
		}
		break;
	default:
		{
			/* BEGINNING OF ACTION: exp_none */
			{
#line 579 "syntax.act"

    (ZIe) = NULL_exp ;
#line 2724 "syntax4.c"
			}
			/* END OF ACTION: exp_none */
		}
		break;
	case 355:
		return;
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZOe = ZIe;
}

void
ZR1329(int *ZOv)
{
	int ZIv;

	switch (CURRENT_TERMINAL) {
	case 155:
		{
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: bool_true */
			{
#line 2050 "syntax.act"
 (ZIv) = 1 ; 
#line 2753 "syntax4.c"
			}
			/* END OF ACTION: bool_true */
		}
		break;
	default:
		{
			/* BEGINNING OF ACTION: bool_false */
			{
#line 2049 "syntax.act"
 (ZIv) = 0 ; 
#line 2764 "syntax4.c"
			}
			/* END OF ACTION: bool_false */
		}
		break;
	case 355:
		return;
	}
	*ZOv = ZIv;
}

void
ZR1202(EXP ZI1200, EXP *ZO1201)
{
	EXP ZI1201;

ZL2_1202:;
	switch (CURRENT_TERMINAL) {
	case 67:
		{
			EXP ZIb;
			EXP ZIe;

			/* BEGINNING OF INLINE: or */
			{
				{
					switch (CURRENT_TERMINAL) {
					case 67:
						break;
					default:
						goto ZL1;
					}
					ADVANCE_LEXER;
				}
			}
			/* END OF INLINE: or */
			ZRexclusive_Hor_Hexpression (&ZIb);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: exp_or */
			{
#line 760 "syntax.act"

    (ZIe) = make_or_exp ( (ZI1200), (ZIb) ) ;
#line 2810 "syntax4.c"
			}
			/* END OF ACTION: exp_or */
			/* BEGINNING OF INLINE: 1202 */
			ZI1200 = ZIe;
			goto ZL2_1202;
			/* END OF INLINE: 1202 */
		}
		/*UNREACHED*/
	default:
		{
			ZI1201 = ZI1200;
		}
		break;
	case 355:
		return;
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZO1201 = ZI1201;
}

void
ZRnew_Htype_Hid(TYPE *ZOt, int *ZOn)
{
	TYPE ZIt;
	int ZIn;

	if ((CURRENT_TERMINAL) == 355) {
		return;
	}
	{
		int ZIn1;
		BASE_TYPE ZIbt;
		TYPE ZIp;
		CV_SPEC ZIcv;
		TYPE ZIs;
		TYPE ZIq;

		/* BEGINNING OF ACTION: no_type_defns */
		{
#line 2014 "syntax.act"

    (ZIn1) = no_type_defns ;
#line 2857 "syntax4.c"
		}
		/* END OF ACTION: no_type_defns */
		ZRtype_Hspecifier_Hseq (&ZIbt, &ZIp, &ZIcv);
		if ((CURRENT_TERMINAL) == 355) {
			RESTORE_LEXER;
			goto ZL1;
		}
		/* BEGINNING OF ACTION: type_complete */
		{
#line 1321 "syntax.act"

    (ZIs) = complete_pre_type ( (ZIbt), (ZIp), (ZIcv), 1 ) ;
    have_type_specifier = 0 ;
#line 2871 "syntax4.c"
		}
		/* END OF ACTION: type_complete */
		ZRnew_Hdeclarator_Hopt (&ZIq);
		if ((CURRENT_TERMINAL) == 355) {
			RESTORE_LEXER;
			goto ZL1;
		}
		/* BEGINNING OF ACTION: type_inject */
		{
#line 1393 "syntax.act"

    (ZIt) = ( IS_NULL_type ( (ZIq) ) ? (ZIs) : inject_pre_type ( (ZIq), (ZIs), 1 ) ) ;
#line 2884 "syntax4.c"
		}
		/* END OF ACTION: type_inject */
		/* BEGINNING OF ACTION: diff_type_defns */
		{
#line 2022 "syntax.act"

    (ZIn) = no_type_defns - (ZIn1) ;
#line 2892 "syntax4.c"
		}
		/* END OF ACTION: diff_type_defns */
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZOt = ZIt;
	*ZOn = ZIn;
}

void
ZRand_Hexpression(EXP *ZO1209)
{
	EXP ZI1209;

	if ((CURRENT_TERMINAL) == 355) {
		return;
	}
	{
		EXP ZIe;

		ZRmaxmin_Hexpression (&ZIe);
		ZR1210 (ZIe, &ZI1209);
		if ((CURRENT_TERMINAL) == 355) {
			RESTORE_LEXER;
			goto ZL1;
		}
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZO1209 = ZI1209;
}

void
ZR1330(DECL_SPEC *ZOa)
{
	DECL_SPEC ZIa;

	switch (CURRENT_TERMINAL) {
	case 142: case 143: case 144:
		{
			ZRaccess_Hspecifier (&ZIa);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	default:
		{
			/* BEGINNING OF ACTION: access_none */
			{
#line 1452 "syntax.act"
 (ZIa) = dspec_none ; 
#line 2952 "syntax4.c"
			}
			/* END OF ACTION: access_none */
		}
		break;
	case 355:
		return;
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZOa = ZIa;
}

void
parse_exp(EXP *ZOe)
{
	EXP ZIe;

	if ((CURRENT_TERMINAL) == 355) {
		return;
	}
	{
		ZRassignment_Hexpression (&ZIe);
		if ((CURRENT_TERMINAL) == 355) {
			RESTORE_LEXER;
			goto ZL1;
		}
	}
	goto ZL0;
ZL1:;
	{
		/* BEGINNING OF ACTION: error_syntax */
		{
#line 1980 "syntax.act"

    /* Syntax errors */
    ERROR err = ERR_lex_parse ( crt_token ) ;
    report ( crt_loc, err ) ;
    have_syntax_error = 1 ;
#line 2994 "syntax4.c"
		}
		/* END OF ACTION: error_syntax */
		/* BEGINNING OF ACTION: exp_none */
		{
#line 579 "syntax.act"

    (ZIe) = NULL_exp ;
#line 3002 "syntax4.c"
		}
		/* END OF ACTION: exp_none */
	}
ZL0:;
	*ZOe = ZIe;
}

void
ZR1077(BASE_TYPE *ZIbt, DECL_SPEC *ZIds3, TYPE *ZIt3, ACCESS_LIST *ZIr, int *ZIc, IDENTIFIER *ZId)
{
	if ((CURRENT_TERMINAL) == 355) {
		return;
	}
	{
		int ZIb;
		EXP ZIe;

		/* BEGINNING OF ACTION: is_function */
		{
#line 2072 "syntax.act"

    /* Resolve function definitions from other declarations */
    (ZI0) = is_function_next ;
#line 3026 "syntax4.c"
		}
		/* END OF ACTION: is_function */
		if (!ZI0)
			goto ZL2;
		/* BEGINNING OF ACTION: initialiser_bad */
		{
#line 1774 "syntax.act"

    if ( (*ZIc) ) report ( crt_loc, ERR_dcl_init_bad () ) ;
#line 3036 "syntax4.c"
		}
		/* END OF ACTION: initialiser_bad */
		/* BEGINNING OF ACTION: access_free */
		{
#line 1484 "syntax.act"

    free_access ( &(*ZIr) ) ;
#line 3044 "syntax4.c"
		}
		/* END OF ACTION: access_free */
		/* BEGINNING OF ACTION: function_begin */
		{
#line 1150 "syntax.act"

    (ZIb) = in_class_defn ;
    in_class_defn = 0 ;
    in_function_defn++ ;
    really_in_function_defn++ ;
    begin_function ( (*ZId) ) ;
#line 3056 "syntax4.c"
		}
		/* END OF ACTION: function_begin */
		ZRfunction_Hdefinition_Hbody (&ZIe);
		if ((CURRENT_TERMINAL) == 355) {
			RESTORE_LEXER;
			goto ZL1;
		}
		/* BEGINNING OF ACTION: function_end */
		{
#line 1158 "syntax.act"

    IGNORE end_function ( (*ZId), (ZIe) ) ;
    in_class_defn = (ZIb) ;
    in_function_defn-- ;
    really_in_function_defn-- ;
#line 3072 "syntax4.c"
		}
		/* END OF ACTION: function_end */
		/* BEGINNING OF ACTION: declarator_end */
		{
#line 1711 "syntax.act"

    end_declarator ( (*ZId), 1 ) ;
#line 3080 "syntax4.c"
		}
		/* END OF ACTION: declarator_end */
		/* BEGINNING OF ACTION: rescan_token */
		{
#line 2147 "syntax.act"

    RESCAN_LEXER ;
#line 3088 "syntax4.c"
		}
		/* END OF ACTION: rescan_token */
		goto ZL0;
	}
	/*UNREACHED*/
ZL2:;
	{
		SID_LIST_EXP ZIp;
		EXP ZIe;

		/* BEGINNING OF ACTION: is_true */
		{
#line 2062 "syntax.act"

    (ZI0) = (*ZIc) ;
#line 3104 "syntax4.c"
		}
		/* END OF ACTION: is_true */
		if (!ZI0)
			goto ZL3;
		/* BEGINNING OF ACTION: rescan_init */
		{
#line 2159 "syntax.act"

    if ( crt_lex_token == lex_open_Hinit ) {
	crt_lex_token = lex_open_Hround ;
    } else {
	RESCAN_LEXER ;
    }
#line 3118 "syntax4.c"
		}
		/* END OF ACTION: rescan_init */
		ZRinitialiser_Hexp_Hlist (*ZId, &ZIp);
		if ((CURRENT_TERMINAL) == 355) {
			RESTORE_LEXER;
			goto ZL1;
		}
		/* BEGINNING OF ACTION: exp_initialiser */
		{
#line 700 "syntax.act"

    MAKE_exp_initialiser ( type_void, (ZIp), NULL_list ( OFFSET ), 0, 0, 0, (ZIe) ) ;
#line 3131 "syntax4.c"
		}
		/* END OF ACTION: exp_initialiser */
		switch (CURRENT_TERMINAL) {
		case 39:
			break;
		default:
			goto ZL1;
		}
		ADVANCE_LEXER;
		/* BEGINNING OF ACTION: initialise_id */
		{
#line 1760 "syntax.act"

    int def = init_object ( (*ZId), (ZIe) ) ;
    if ( do_dump ) dump_declare ( (*ZId), &decl_loc, def ) ;
#line 3147 "syntax4.c"
		}
		/* END OF ACTION: initialise_id */
		/* BEGINNING OF ACTION: access_check_decl */
		{
#line 1471 "syntax.act"

    if ( crt_access_list.pending ) {
	IGNORE report_access ( (*ZId) ) ;
    }
#line 3157 "syntax4.c"
		}
		/* END OF ACTION: access_check_decl */
		/* BEGINNING OF ACTION: declarator_end */
		{
#line 1711 "syntax.act"

    end_declarator ( (*ZId), 1 ) ;
#line 3165 "syntax4.c"
		}
		/* END OF ACTION: declarator_end */
		ZR1078 (ZIbt, ZIds3, ZIt3, ZIr);
		if ((CURRENT_TERMINAL) == 355) {
			RESTORE_LEXER;
			goto ZL1;
		}
		/* BEGINNING OF ACTION: access_free */
		{
#line 1484 "syntax.act"

    free_access ( &(*ZIr) ) ;
#line 3178 "syntax4.c"
		}
		/* END OF ACTION: access_free */
		switch (CURRENT_TERMINAL) {
		case 77:
			break;
		default:
			goto ZL1;
		}
		ADVANCE_LEXER;
		goto ZL0;
	}
	/*UNREACHED*/
ZL3:;
	switch (CURRENT_TERMINAL) {
	case 36:
		{
			EXP ZIe;

			ADVANCE_LEXER;
			ZRinitialiser_Hclause (*ZId, &ZIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: initialise_id */
			{
#line 1760 "syntax.act"

    int def = init_object ( (*ZId), (ZIe) ) ;
    if ( do_dump ) dump_declare ( (*ZId), &decl_loc, def ) ;
#line 3209 "syntax4.c"
			}
			/* END OF ACTION: initialise_id */
			/* BEGINNING OF ACTION: access_check_decl */
			{
#line 1471 "syntax.act"

    if ( crt_access_list.pending ) {
	IGNORE report_access ( (*ZId) ) ;
    }
#line 3219 "syntax4.c"
			}
			/* END OF ACTION: access_check_decl */
			/* BEGINNING OF ACTION: declarator_end */
			{
#line 1711 "syntax.act"

    end_declarator ( (*ZId), 1 ) ;
#line 3227 "syntax4.c"
			}
			/* END OF ACTION: declarator_end */
			ZR1078 (ZIbt, ZIds3, ZIt3, ZIr);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: access_free */
			{
#line 1484 "syntax.act"

    free_access ( &(*ZIr) ) ;
#line 3240 "syntax4.c"
			}
			/* END OF ACTION: access_free */
			switch (CURRENT_TERMINAL) {
			case 77:
				break;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
		}
		break;
	case 42: case 77:
		{
			EXP ZIe;

			/* BEGINNING OF ACTION: exp_none */
			{
#line 579 "syntax.act"

    (ZIe) = NULL_exp ;
#line 3261 "syntax4.c"
			}
			/* END OF ACTION: exp_none */
			/* BEGINNING OF ACTION: initialise_id */
			{
#line 1760 "syntax.act"

    int def = init_object ( (*ZId), (ZIe) ) ;
    if ( do_dump ) dump_declare ( (*ZId), &decl_loc, def ) ;
#line 3270 "syntax4.c"
			}
			/* END OF ACTION: initialise_id */
			/* BEGINNING OF ACTION: access_check_decl */
			{
#line 1471 "syntax.act"

    if ( crt_access_list.pending ) {
	IGNORE report_access ( (*ZId) ) ;
    }
#line 3280 "syntax4.c"
			}
			/* END OF ACTION: access_check_decl */
			/* BEGINNING OF ACTION: declarator_end */
			{
#line 1711 "syntax.act"

    end_declarator ( (*ZId), 1 ) ;
#line 3288 "syntax4.c"
			}
			/* END OF ACTION: declarator_end */
			ZR1078 (ZIbt, ZIds3, ZIt3, ZIr);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: access_free */
			{
#line 1484 "syntax.act"

    free_access ( &(*ZIr) ) ;
#line 3301 "syntax4.c"
			}
			/* END OF ACTION: access_free */
			switch (CURRENT_TERMINAL) {
			case 77:
				break;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
		}
		break;
	default:
		goto ZL1;
	}
	return;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
}

void
ZRdeclaration_Hnonempty(TYPE ZIt, DECL_SPEC ZIds, EXP *ZOe)
{
	EXP ZIe;

	if ((CURRENT_TERMINAL) == 355) {
		return;
	}
	{
		BASE_TYPE ZI1250;
		TYPE ZI1251;
		CV_SPEC ZI1252;
		DECL_SPEC ZI1253;
		BASE_TYPE ZIbt;
		TYPE ZIt1;
		CV_SPEC ZIcv1;
		DECL_SPEC ZIds1;
		DECL_SPEC ZIds2;

		/* BEGINNING OF ACTION: is_decl_specifier */
		{
#line 2077 "syntax.act"

    /* Resolve declaration-specifiers from other declarators */
    (ZI0) = predict_dspec ( 0 ) ;
#line 3348 "syntax4.c"
		}
		/* END OF ACTION: is_decl_specifier */
		if (!ZI0)
			goto ZL2;
		ZRdecl_Hspecifier (ZIt, &ZI1250, &ZI1251, &ZI1252, &ZI1253);
		ZR919 (&ZIt, &ZI1250, &ZI1251, &ZI1252, &ZI1253, &ZIbt, &ZIt1, &ZIcv1, &ZIds1);
		if ((CURRENT_TERMINAL) == 355) {
			RESTORE_LEXER;
			goto ZL1;
		}
		/* BEGINNING OF ACTION: dspec_join */
		{
#line 1560 "syntax.act"

    /* Combine two declaration specifiers */
    DECL_SPEC d = ( ( (ZIds) & (ZIds1) ) & dspec_duplicate ) ;
    if ( d ) report ( crt_loc, ERR_dcl_spec_dup ( d ) ) ;
    (ZIds2) = ( (ZIds) | (ZIds1) ) ;
#line 3367 "syntax4.c"
		}
		/* END OF ACTION: dspec_join */
		ZR1254 (&ZIt, &ZIbt, &ZIt1, &ZIcv1, &ZIds2);
		if ((CURRENT_TERMINAL) == 355) {
			RESTORE_LEXER;
			goto ZL1;
		}
		/* BEGINNING OF ACTION: exp_none */
		{
#line 579 "syntax.act"

    (ZIe) = NULL_exp ;
#line 3380 "syntax4.c"
		}
		/* END OF ACTION: exp_none */
		goto ZL0;
	}
	/*UNREACHED*/
ZL2:;
	switch (CURRENT_TERMINAL) {
	case 105:
		{
			ZRlinkage_Hspecification (ZIt, ZIds, &ZIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 134: case 147:
		{
			ZRtemplate_Hdeclaration (ZIt, ZIds, &ZIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 1: case 2: case 3: case 4:
	case 5: case 6: case 7: case 8:
	case 9: case 10: case 11: case 33:
	case 65: case 78: case 83: case 141:
		{
			BASE_TYPE ZIbt;
			TYPE ZIt1;
			CV_SPEC ZIcv1;
			DECL_SPEC ZIds1;
			DECL_SPEC ZIds2;
			TYPE ZIt2;
			DECL_SPEC ZIds3;
			TYPE ZIt3;
			ACCESS_LIST ZIr;
			TYPE ZIs;
			IDENTIFIER ZIid;
			int ZIc;
			IDENTIFIER ZId;

			/* BEGINNING OF ACTION: btype_none */
			{
#line 1252 "syntax.act"
 (ZIbt) = btype_none ; 
#line 3429 "syntax4.c"
			}
			/* END OF ACTION: btype_none */
			/* BEGINNING OF ACTION: type_none */
			{
#line 1276 "syntax.act"

    (ZIt1) = NULL_type ;
#line 3437 "syntax4.c"
			}
			/* END OF ACTION: type_none */
			/* BEGINNING OF ACTION: cv_none */
			{
#line 1220 "syntax.act"
 (ZIcv1) = cv_none ; 
#line 3444 "syntax4.c"
			}
			/* END OF ACTION: cv_none */
			/* BEGINNING OF ACTION: dspec_none */
			{
#line 1544 "syntax.act"
 (ZIds1) = dspec_none ; 
#line 3451 "syntax4.c"
			}
			/* END OF ACTION: dspec_none */
			/* BEGINNING OF ACTION: dspec_join */
			{
#line 1560 "syntax.act"

    /* Combine two declaration specifiers */
    DECL_SPEC d = ( ( (ZIds) & (ZIds1) ) & dspec_duplicate ) ;
    if ( d ) report ( crt_loc, ERR_dcl_spec_dup ( d ) ) ;
    (ZIds2) = ( (ZIds) | (ZIds1) ) ;
#line 3462 "syntax4.c"
			}
			/* END OF ACTION: dspec_join */
			/* BEGINNING OF ACTION: dspec_complete */
			{
#line 1571 "syntax.act"

    /* Complete a declaration specifier and a type */
    (ZIds3) = complete_dspec ( (ZIds2), (ZIbt), (ZIt1), (ZIcv1) ) ;
    (ZIt2) = complete_pre_type ( (ZIbt), (ZIt1), (ZIcv1), 0 ) ;
    have_type_specifier = 0 ;
#line 3473 "syntax4.c"
			}
			/* END OF ACTION: dspec_complete */
			/* BEGINNING OF ACTION: type_inject */
			{
#line 1393 "syntax.act"

    (ZIt3) = ( IS_NULL_type ( (ZIt) ) ? (ZIt2) : inject_pre_type ( (ZIt), (ZIt2), 1 ) ) ;
#line 3481 "syntax4.c"
			}
			/* END OF ACTION: type_inject */
			/* BEGINNING OF ACTION: access_return */
			{
#line 1480 "syntax.act"

    save_access ( &(ZIr) ) ;
#line 3489 "syntax4.c"
			}
			/* END OF ACTION: access_return */
			/* BEGINNING OF ACTION: declarator_start */
			{
#line 1704 "syntax.act"

    crt_templ_qualifier = 0 ;
#line 3497 "syntax4.c"
			}
			/* END OF ACTION: declarator_start */
			ZRdeclarator (ZIt3, &ZIs, &ZIid, &ZIc);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: declare_id */
			{
#line 1608 "syntax.act"

    if ( type_tag ( (ZIs) ) == type_func_tag ) {
	/* Look ahead for function definitions */
	int def = predict_func_defn () ;
	if ( def & !have_func_declarator ) adjust_param ( (ZIs) ) ;
	(ZId) = make_func_decl ( (ZIds3), (ZIs), (ZIid), def ) ;
	is_function_next = def ;
    } else {
	int def = predict_obj_defn () ;
	(ZId) = make_object_decl ( (ZIds3), (ZIs), (ZIid), def ) ;
	is_function_next = 0 ;
    }
    if ( IS_id_type_alias ( (ZId) ) ) {
	BASE_TYPE bs = DEREF_btype ( id_type_alias_rep ( (ZId) ) ) ;
	bs |= (ZIbt) ;
	COPY_btype ( id_type_alias_rep ( (ZId) ), bs ) ;
    }
    have_type_declaration = TYPE_DECL_NONE ;
    have_func_declarator = 0 ;
#line 3527 "syntax4.c"
			}
			/* END OF ACTION: declare_id */
			/* BEGINNING OF ACTION: access_check_ret */
			{
#line 1476 "syntax.act"

    IGNORE clear_access ( (ZId), &(ZIr) ) ;
#line 3535 "syntax4.c"
			}
			/* END OF ACTION: access_check_ret */
			/* BEGINNING OF ACTION: access_check_decl */
			{
#line 1471 "syntax.act"

    if ( crt_access_list.pending ) {
	IGNORE report_access ( (ZId) ) ;
    }
#line 3545 "syntax4.c"
			}
			/* END OF ACTION: access_check_decl */
			ZR1077 (&ZIbt, &ZIds3, &ZIt3, &ZIr, &ZIc, &ZId);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: exp_none */
			{
#line 579 "syntax.act"

    (ZIe) = NULL_exp ;
#line 3558 "syntax4.c"
			}
			/* END OF ACTION: exp_none */
		}
		break;
	case 126: case 139: case 154:
		{
			/* BEGINNING OF ACTION: template_check */
			{
#line 1859 "syntax.act"

    if ( !IS_NULL_type ( (ZIt) ) ) report ( crt_loc, ERR_temp_decl_bad () ) ;
    UNUSED ( (ZIds) ) ;
#line 3571 "syntax4.c"
			}
			/* END OF ACTION: template_check */
			ZRdeclaration_Hother (&ZIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	default:
		goto ZL1;
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZOe = ZIe;
}

void
ZR1078(BASE_TYPE *ZIbt, DECL_SPEC *ZIds3, TYPE *ZIt3, ACCESS_LIST *ZIr)
{
	switch (CURRENT_TERMINAL) {
	case 42:
		{
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: declarator_start */
			{
#line 1704 "syntax.act"

    crt_templ_qualifier = 0 ;
#line 3604 "syntax4.c"
			}
			/* END OF ACTION: declarator_start */
			ZRinit_Hdeclarator_Hlist (*ZIds3, *ZIbt, *ZIt3, *ZIr);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 355:
		return;
	default:
		break;
	}
	return;
ZL1:;
	SAVE_LEXER (355);
	return;
}

void
ZRthrow_Hexpression(EXP *ZOe)
{
	EXP ZIe;

	if ((CURRENT_TERMINAL) == 355) {
		return;
	}
	{
		EXP ZIa;

		switch (CURRENT_TERMINAL) {
		case 149:
			break;
		default:
			goto ZL1;
		}
		ADVANCE_LEXER;
		/* BEGINNING OF INLINE: 638 */
		{
			{
				TYPE ZIt;
				int ZIn;

				/* BEGINNING OF ACTION: is_type_id_false */
				{
#line 2114 "syntax.act"

    /* Resolve type-ids from expressions */
    (ZI0) = predict_typeid ( 0 ) ;
#line 3655 "syntax4.c"
				}
				/* END OF ACTION: is_type_id_false */
				if (!ZI0)
					goto ZL3;
				ZRtype_Hid (&ZIt, &ZIn);
				if ((CURRENT_TERMINAL) == 355) {
					RESTORE_LEXER;
					goto ZL1;
				}
				/* BEGINNING OF ACTION: exp_throw_type */
				{
#line 839 "syntax.act"

    (ZIa) = make_throw_arg ( (ZIt), (ZIn) ) ;
#line 3670 "syntax4.c"
				}
				/* END OF ACTION: exp_throw_type */
				goto ZL2;
			}
			/*UNREACHED*/
		ZL3:;
			switch (CURRENT_TERMINAL) {
			case 1: case 2: case 3: case 5:
			case 6: case 7: case 8: case 9:
			case 17: case 18: case 19: case 20:
			case 21: case 22: case 23: case 25:
			case 33: case 43: case 59: case 61:
			case 62: case 65: case 69: case 71:
			case 78: case 83: case 85: case 97:
			case 102: case 106: case 110: case 111:
			case 114: case 115: case 116: case 122:
			case 123: case 127: case 130: case 131:
			case 132: case 135: case 140: case 141:
			case 145: case 146: case 148: case 149:
			case 150: case 152: case 156: case 170:
			case 185: case 206: case 210: case 255:
			case 286: case 299: case 330:
				{
					ZRassignment_Hexpression (&ZIa);
					if ((CURRENT_TERMINAL) == 355) {
						RESTORE_LEXER;
						goto ZL1;
					}
				}
				break;
			default:
				{
					/* BEGINNING OF ACTION: exp_none */
					{
#line 579 "syntax.act"

    (ZIa) = NULL_exp ;
#line 3708 "syntax4.c"
					}
					/* END OF ACTION: exp_none */
				}
				break;
			}
		ZL2:;
		}
		/* END OF INLINE: 638 */
		/* BEGINNING OF ACTION: exp_throw */
		{
#line 835 "syntax.act"

    (ZIe) = make_throw_exp ( (ZIa), 1 ) ;
#line 3722 "syntax4.c"
		}
		/* END OF ACTION: exp_throw */
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZOe = ZIe;
}

void
ZR1206(EXP ZI1204, EXP *ZO1205)
{
	EXP ZI1205;

ZL2_1206:;
	switch (CURRENT_TERMINAL) {
	case 80:
		{
			EXP ZIb;
			EXP ZIe;

			/* BEGINNING OF INLINE: xor */
			{
				{
					switch (CURRENT_TERMINAL) {
					case 80:
						break;
					default:
						goto ZL1;
					}
					ADVANCE_LEXER;
				}
			}
			/* END OF INLINE: xor */
			ZRand_Hexpression (&ZIb);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: exp_xor */
			{
#line 863 "syntax.act"

    (ZIe) = make_xor_exp ( (ZI1204), (ZIb) ) ;
#line 3769 "syntax4.c"
			}
			/* END OF ACTION: exp_xor */
			/* BEGINNING OF INLINE: 1206 */
			ZI1204 = ZIe;
			goto ZL2_1206;
			/* END OF INLINE: 1206 */
		}
		/*UNREACHED*/
	default:
		{
			ZI1205 = ZI1204;
		}
		break;
	case 355:
		return;
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZO1205 = ZI1205;
}

void
parse_stmt(EXP *ZOe)
{
	EXP ZIe;

	if ((CURRENT_TERMINAL) == 355) {
		return;
	}
	{
		DECL_SPEC ZIds;
		TYPE ZIt;
		EXP ZIa;

		/* BEGINNING OF ACTION: is_decl_statement */
		{
#line 2084 "syntax.act"

    /* Resolve declaration-statements from expression-statements */
    int b = predict_decl () ;
    if ( b ) in_declaration++ ;
    (ZI0) = b ;
#line 3815 "syntax4.c"
		}
		/* END OF ACTION: is_decl_statement */
		if (!ZI0)
			goto ZL2;
		/* BEGINNING OF ACTION: dspec_none */
		{
#line 1544 "syntax.act"
 (ZIds) = dspec_none ; 
#line 3824 "syntax4.c"
		}
		/* END OF ACTION: dspec_none */
		/* BEGINNING OF ACTION: type_none */
		{
#line 1276 "syntax.act"

    (ZIt) = NULL_type ;
#line 3832 "syntax4.c"
		}
		/* END OF ACTION: type_none */
		ZRdeclaration_Hnonempty (ZIt, ZIds, &ZIa);
		if ((CURRENT_TERMINAL) == 355) {
			RESTORE_LEXER;
			goto ZL1;
		}
		/* BEGINNING OF ACTION: stmt_decl */
		{
#line 929 "syntax.act"

    (ZIe) = (ZIa) ;
    in_declaration-- ;
#line 3846 "syntax4.c"
		}
		/* END OF ACTION: stmt_decl */
		/* BEGINNING OF ACTION: stmt_label_clear */
		{
#line 1018 "syntax.act"

    unreached_fall = 1 ;
#line 3854 "syntax4.c"
		}
		/* END OF ACTION: stmt_label_clear */
		goto ZL0;
	}
	/*UNREACHED*/
ZL2:;
	switch (CURRENT_TERMINAL) {
	case 170:
		{
			int ZIop;
			EXP ZI1454;
			EXP ZI1453;
			EXP ZI1452;
			EXP ZI1451;
			EXP ZI1450;
			EXP ZI1449;
			EXP ZI1448;
			EXP ZI1447;
			EXP ZI1446;
			EXP ZI1445;
			EXP ZI1444;
			EXP ZI1443;
			EXP ZI1265;
			EXP ZI1289;
			EXP ZIa;
			int ZIr;

			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: lex_alignof */
			{
#line 396 "syntax.act"
 (ZIop) = lex_alignof ; 
#line 3887 "syntax4.c"
			}
			/* END OF ACTION: lex_alignof */
			ZRsizeof_Hexpression (ZIop, &ZI1454);
			ZR1238 (ZI1454, &ZI1453);
			ZR1234 (ZI1453, &ZI1452);
			ZR1230 (ZI1452, &ZI1451);
			ZR1226 (ZI1451, &ZI1450);
			ZR1222 (ZI1450, &ZI1449);
			ZR1218 (ZI1449, &ZI1448);
			ZR1214 (ZI1448, &ZI1447);
			ZR1210 (ZI1447, &ZI1446);
			ZR1206 (ZI1446, &ZI1445);
			ZR1202 (ZI1445, &ZI1444);
			ZR1198 (ZI1444, &ZI1443);
			ZR1194 (ZI1443, &ZI1265);
			ZR1266 (&ZI1265, &ZI1289);
			ZR1291 (&ZI1289, &ZIa);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: reach_check */
			{
#line 1121 "syntax.act"

    (ZIr) = unreached_code ;
    if ( (ZIr) ) {
	if ( !unreached_last ) {
	    report ( crt_loc, ERR_stmt_stmt_unreach () ) ;
	    unreached_last = 1 ;
	}
    } else {
	unreached_last = 0 ;
    }
#line 3922 "syntax4.c"
			}
			/* END OF ACTION: reach_check */
			/* BEGINNING OF ACTION: stmt_exp */
			{
#line 950 "syntax.act"

    (ZIe) = make_exp_stmt ( (ZIa) ) ;
#line 3930 "syntax4.c"
			}
			/* END OF ACTION: stmt_exp */
			/* BEGINNING OF ACTION: stmt_label_clear */
			{
#line 1018 "syntax.act"

    unreached_fall = 1 ;
#line 3938 "syntax4.c"
			}
			/* END OF ACTION: stmt_label_clear */
			switch (CURRENT_TERMINAL) {
			case 77:
				break;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
		}
		break;
	case 83:
		{
			ADVANCE_LEXER;
			ZR1477 (&ZIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 23:
		{
			EXP ZI1281;
			EXP ZI1454;
			EXP ZI1453;
			EXP ZI1452;
			EXP ZI1451;
			EXP ZI1450;
			EXP ZI1449;
			EXP ZI1448;
			EXP ZI1447;
			EXP ZI1446;
			EXP ZI1445;
			EXP ZI1444;
			EXP ZI1443;
			EXP ZI1265;
			EXP ZI1289;
			EXP ZIa;
			int ZIr;

			/* BEGINNING OF EXTRACT: complex-exp */
			{
#line 355 "syntax.act"

    IDENTIFIER id = crt_token->pp_data.tok.id ;
    PPTOKEN *args = crt_token->pp_data.tok.args ;
    ZI1281 = parse_exp_token ( id, args ) ;
    RESCAN_LEXER ;
#line 3988 "syntax4.c"
			}
			/* END OF EXTRACT: complex-exp */
			ADVANCE_LEXER;
			ZR1242 (ZI1281, &ZI1454);
			ZR1238 (ZI1454, &ZI1453);
			ZR1234 (ZI1453, &ZI1452);
			ZR1230 (ZI1452, &ZI1451);
			ZR1226 (ZI1451, &ZI1450);
			ZR1222 (ZI1450, &ZI1449);
			ZR1218 (ZI1449, &ZI1448);
			ZR1214 (ZI1448, &ZI1447);
			ZR1210 (ZI1447, &ZI1446);
			ZR1206 (ZI1446, &ZI1445);
			ZR1202 (ZI1445, &ZI1444);
			ZR1198 (ZI1444, &ZI1443);
			ZR1194 (ZI1443, &ZI1265);
			ZR1266 (&ZI1265, &ZI1289);
			ZR1291 (&ZI1289, &ZIa);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: reach_check */
			{
#line 1121 "syntax.act"

    (ZIr) = unreached_code ;
    if ( (ZIr) ) {
	if ( !unreached_last ) {
	    report ( crt_loc, ERR_stmt_stmt_unreach () ) ;
	    unreached_last = 1 ;
	}
    } else {
	unreached_last = 0 ;
    }
#line 4024 "syntax4.c"
			}
			/* END OF ACTION: reach_check */
			/* BEGINNING OF ACTION: stmt_exp */
			{
#line 950 "syntax.act"

    (ZIe) = make_exp_stmt ( (ZIa) ) ;
#line 4032 "syntax4.c"
			}
			/* END OF ACTION: stmt_exp */
			/* BEGINNING OF ACTION: stmt_label_clear */
			{
#line 1018 "syntax.act"

    unreached_fall = 1 ;
#line 4040 "syntax4.c"
			}
			/* END OF ACTION: stmt_label_clear */
			switch (CURRENT_TERMINAL) {
			case 77:
				break;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
		}
		break;
	case 24:
		{
			EXP ZIa;

			/* BEGINNING OF EXTRACT: complex-stmt */
			{
#line 362 "syntax.act"

    IDENTIFIER id = crt_token->pp_data.tok.id ;
    PPTOKEN *args = crt_token->pp_data.tok.args ;
    ZIa = parse_exp_token ( id, args ) ;
    RESCAN_LEXER ;
#line 4064 "syntax4.c"
			}
			/* END OF EXTRACT: complex-stmt */
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: stmt_exp */
			{
#line 950 "syntax.act"

    (ZIe) = make_exp_stmt ( (ZIa) ) ;
#line 4073 "syntax4.c"
			}
			/* END OF ACTION: stmt_exp */
		}
		break;
	case 25:
		{
			TYPE ZI1267;
			BASE_TYPE ZIbt;
			CV_SPEC ZIcv;
			TYPE ZIt;
			SID_LIST_EXP ZIp;
			EXP ZI1284;
			EXP ZI1454;
			EXP ZI1453;
			EXP ZI1452;
			EXP ZI1451;
			EXP ZI1450;
			EXP ZI1449;
			EXP ZI1448;
			EXP ZI1447;
			EXP ZI1446;
			EXP ZI1445;
			EXP ZI1444;
			EXP ZI1443;
			EXP ZI1265;
			EXP ZI1289;
			EXP ZIa;
			int ZIr;

			/* BEGINNING OF EXTRACT: complex-type */
			{
#line 369 "syntax.act"

    IDENTIFIER id = crt_token->pp_data.tok.id ;
    PPTOKEN *args = crt_token->pp_data.tok.args ;
    ZI1267 = parse_type_token ( id, args ) ;
    have_type_declaration = TYPE_DECL_NONE ;
    have_type_specifier = 1 ;
    RESCAN_LEXER ;
#line 4113 "syntax4.c"
			}
			/* END OF EXTRACT: complex-type */
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: btype_none */
			{
#line 1252 "syntax.act"
 (ZIbt) = btype_none ; 
#line 4121 "syntax4.c"
			}
			/* END OF ACTION: btype_none */
			/* BEGINNING OF ACTION: cv_none */
			{
#line 1220 "syntax.act"
 (ZIcv) = cv_none ; 
#line 4128 "syntax4.c"
			}
			/* END OF ACTION: cv_none */
			/* BEGINNING OF ACTION: type_complete */
			{
#line 1321 "syntax.act"

    (ZIt) = complete_pre_type ( (ZIbt), (ZI1267), (ZIcv), 1 ) ;
    have_type_specifier = 0 ;
#line 4137 "syntax4.c"
			}
			/* END OF ACTION: type_complete */
			switch (CURRENT_TERMINAL) {
			case 65:
				break;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
			ZRexpression_Hlist_Hopt (&ZIp);
			switch (CURRENT_TERMINAL) {
			case 39:
				break;
			case 355:
				RESTORE_LEXER;
				goto ZL1;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: exp_func_cast */
			{
#line 680 "syntax.act"

    (ZI1284) = make_func_cast_exp ( (ZIt), (ZIp) ) ;
#line 4163 "syntax4.c"
			}
			/* END OF ACTION: exp_func_cast */
			ZR1242 (ZI1284, &ZI1454);
			ZR1238 (ZI1454, &ZI1453);
			ZR1234 (ZI1453, &ZI1452);
			ZR1230 (ZI1452, &ZI1451);
			ZR1226 (ZI1451, &ZI1450);
			ZR1222 (ZI1450, &ZI1449);
			ZR1218 (ZI1449, &ZI1448);
			ZR1214 (ZI1448, &ZI1447);
			ZR1210 (ZI1447, &ZI1446);
			ZR1206 (ZI1446, &ZI1445);
			ZR1202 (ZI1445, &ZI1444);
			ZR1198 (ZI1444, &ZI1443);
			ZR1194 (ZI1443, &ZI1265);
			ZR1266 (&ZI1265, &ZI1289);
			ZR1291 (&ZI1289, &ZIa);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: reach_check */
			{
#line 1121 "syntax.act"

    (ZIr) = unreached_code ;
    if ( (ZIr) ) {
	if ( !unreached_last ) {
	    report ( crt_loc, ERR_stmt_stmt_unreach () ) ;
	    unreached_last = 1 ;
	}
    } else {
	unreached_last = 0 ;
    }
#line 4198 "syntax4.c"
			}
			/* END OF ACTION: reach_check */
			/* BEGINNING OF ACTION: stmt_exp */
			{
#line 950 "syntax.act"

    (ZIe) = make_exp_stmt ( (ZIa) ) ;
#line 4206 "syntax4.c"
			}
			/* END OF ACTION: stmt_exp */
			/* BEGINNING OF ACTION: stmt_label_clear */
			{
#line 1018 "syntax.act"

    unreached_fall = 1 ;
#line 4214 "syntax4.c"
			}
			/* END OF ACTION: stmt_label_clear */
			switch (CURRENT_TERMINAL) {
			case 77:
				break;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
		}
		break;
	case 130:
		{
			TYPE ZIt;
			EXP ZI1463;
			int ZIn;
			EXP ZI1273;
			EXP ZI1454;
			EXP ZI1453;
			EXP ZI1452;
			EXP ZI1451;
			EXP ZI1450;
			EXP ZI1449;
			EXP ZI1448;
			EXP ZI1447;
			EXP ZI1446;
			EXP ZI1445;
			EXP ZI1444;
			EXP ZI1443;
			EXP ZI1265;
			EXP ZI1289;
			EXP ZIa;
			int ZIr;

			ADVANCE_LEXER;
			ZRcast_Hoperand (&ZIt, &ZI1463, &ZIn);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: exp_const_cast */
			{
#line 628 "syntax.act"

    /* n is the number of type definitions in t */
    (ZI1273) = make_const_cast_exp ( (ZIt), (ZI1463), (ZIn) ) ;
#line 4261 "syntax4.c"
			}
			/* END OF ACTION: exp_const_cast */
			ZR1242 (ZI1273, &ZI1454);
			ZR1238 (ZI1454, &ZI1453);
			ZR1234 (ZI1453, &ZI1452);
			ZR1230 (ZI1452, &ZI1451);
			ZR1226 (ZI1451, &ZI1450);
			ZR1222 (ZI1450, &ZI1449);
			ZR1218 (ZI1449, &ZI1448);
			ZR1214 (ZI1448, &ZI1447);
			ZR1210 (ZI1447, &ZI1446);
			ZR1206 (ZI1446, &ZI1445);
			ZR1202 (ZI1445, &ZI1444);
			ZR1198 (ZI1444, &ZI1443);
			ZR1194 (ZI1443, &ZI1265);
			ZR1266 (&ZI1265, &ZI1289);
			ZR1291 (&ZI1289, &ZIa);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: reach_check */
			{
#line 1121 "syntax.act"

    (ZIr) = unreached_code ;
    if ( (ZIr) ) {
	if ( !unreached_last ) {
	    report ( crt_loc, ERR_stmt_stmt_unreach () ) ;
	    unreached_last = 1 ;
	}
    } else {
	unreached_last = 0 ;
    }
#line 4296 "syntax4.c"
			}
			/* END OF ACTION: reach_check */
			/* BEGINNING OF ACTION: stmt_exp */
			{
#line 950 "syntax.act"

    (ZIe) = make_exp_stmt ( (ZIa) ) ;
#line 4304 "syntax4.c"
			}
			/* END OF ACTION: stmt_exp */
			/* BEGINNING OF ACTION: stmt_label_clear */
			{
#line 1018 "syntax.act"

    unreached_fall = 1 ;
#line 4312 "syntax4.c"
			}
			/* END OF ACTION: stmt_label_clear */
			switch (CURRENT_TERMINAL) {
			case 77:
				break;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
		}
		break;
	case 5:
		{
			IDENTIFIER ZIuid;
			IDENTIFIER ZIid;
			EXP ZI1285;
			EXP ZI1454;
			EXP ZI1453;
			EXP ZI1452;
			EXP ZI1451;
			EXP ZI1450;
			EXP ZI1449;
			EXP ZI1448;
			EXP ZI1447;
			EXP ZI1446;
			EXP ZI1445;
			EXP ZI1444;
			EXP ZI1443;
			EXP ZI1265;
			EXP ZI1289;
			EXP ZIa;
			int ZIr;

			/* BEGINNING OF EXTRACT: destructor-name */
			{
#line 233 "syntax.act"

    ZIuid = crt_token->pp_data.id.use ;
#line 4351 "syntax4.c"
			}
			/* END OF EXTRACT: destructor-name */
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: namespace_complex */
			{
#line 513 "syntax.act"

    (ZIid) = check_id ( NULL_nspace, (ZIuid), 0 ) ;
    crt_id_qualifier = qual_none ;
    last_namespace = crt_namespace ;
#line 4362 "syntax4.c"
			}
			/* END OF ACTION: namespace_complex */
			/* BEGINNING OF ACTION: exp_identifier */
			{
#line 684 "syntax.act"

    (ZI1285) = make_id_exp ( (ZIid) ) ;
#line 4370 "syntax4.c"
			}
			/* END OF ACTION: exp_identifier */
			ZR1242 (ZI1285, &ZI1454);
			ZR1238 (ZI1454, &ZI1453);
			ZR1234 (ZI1453, &ZI1452);
			ZR1230 (ZI1452, &ZI1451);
			ZR1226 (ZI1451, &ZI1450);
			ZR1222 (ZI1450, &ZI1449);
			ZR1218 (ZI1449, &ZI1448);
			ZR1214 (ZI1448, &ZI1447);
			ZR1210 (ZI1447, &ZI1446);
			ZR1206 (ZI1446, &ZI1445);
			ZR1202 (ZI1445, &ZI1444);
			ZR1198 (ZI1444, &ZI1443);
			ZR1194 (ZI1443, &ZI1265);
			ZR1266 (&ZI1265, &ZI1289);
			ZR1291 (&ZI1289, &ZIa);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: reach_check */
			{
#line 1121 "syntax.act"

    (ZIr) = unreached_code ;
    if ( (ZIr) ) {
	if ( !unreached_last ) {
	    report ( crt_loc, ERR_stmt_stmt_unreach () ) ;
	    unreached_last = 1 ;
	}
    } else {
	unreached_last = 0 ;
    }
#line 4405 "syntax4.c"
			}
			/* END OF ACTION: reach_check */
			/* BEGINNING OF ACTION: stmt_exp */
			{
#line 950 "syntax.act"

    (ZIe) = make_exp_stmt ( (ZIa) ) ;
#line 4413 "syntax4.c"
			}
			/* END OF ACTION: stmt_exp */
			/* BEGINNING OF ACTION: stmt_label_clear */
			{
#line 1018 "syntax.act"

    unreached_fall = 1 ;
#line 4421 "syntax4.c"
			}
			/* END OF ACTION: stmt_label_clear */
			switch (CURRENT_TERMINAL) {
			case 77:
				break;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
		}
		break;
	case 206:
		{
			EXP ZI1456;
			EXP ZI1454;
			EXP ZI1453;
			EXP ZI1452;
			EXP ZI1451;
			EXP ZI1450;
			EXP ZI1449;
			EXP ZI1448;
			EXP ZI1447;
			EXP ZI1446;
			EXP ZI1445;
			EXP ZI1444;
			EXP ZI1443;
			EXP ZI1265;
			EXP ZI1289;
			EXP ZIa;
			int ZIr;

			ADVANCE_LEXER;
			ZRcast_Hexpression (&ZI1456);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: exp_ignore */
			{
#line 688 "syntax.act"

    (ZI1454) = make_cast_exp ( type_void, (ZI1456), 0 ) ;
#line 4464 "syntax4.c"
			}
			/* END OF ACTION: exp_ignore */
			ZR1238 (ZI1454, &ZI1453);
			ZR1234 (ZI1453, &ZI1452);
			ZR1230 (ZI1452, &ZI1451);
			ZR1226 (ZI1451, &ZI1450);
			ZR1222 (ZI1450, &ZI1449);
			ZR1218 (ZI1449, &ZI1448);
			ZR1214 (ZI1448, &ZI1447);
			ZR1210 (ZI1447, &ZI1446);
			ZR1206 (ZI1446, &ZI1445);
			ZR1202 (ZI1445, &ZI1444);
			ZR1198 (ZI1444, &ZI1443);
			ZR1194 (ZI1443, &ZI1265);
			ZR1266 (&ZI1265, &ZI1289);
			ZR1291 (&ZI1289, &ZIa);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: reach_check */
			{
#line 1121 "syntax.act"

    (ZIr) = unreached_code ;
    if ( (ZIr) ) {
	if ( !unreached_last ) {
	    report ( crt_loc, ERR_stmt_stmt_unreach () ) ;
	    unreached_last = 1 ;
	}
    } else {
	unreached_last = 0 ;
    }
#line 4498 "syntax4.c"
			}
			/* END OF ACTION: reach_check */
			/* BEGINNING OF ACTION: stmt_exp */
			{
#line 950 "syntax.act"

    (ZIe) = make_exp_stmt ( (ZIa) ) ;
#line 4506 "syntax4.c"
			}
			/* END OF ACTION: stmt_exp */
			/* BEGINNING OF ACTION: stmt_label_clear */
			{
#line 1018 "syntax.act"

    unreached_fall = 1 ;
#line 4514 "syntax4.c"
			}
			/* END OF ACTION: stmt_label_clear */
			switch (CURRENT_TERMINAL) {
			case 77:
				break;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
		}
		break;
	case 132:
		{
			TYPE ZIt;
			EXP ZI1466;
			int ZIn;
			EXP ZI1276;
			EXP ZI1454;
			EXP ZI1453;
			EXP ZI1452;
			EXP ZI1451;
			EXP ZI1450;
			EXP ZI1449;
			EXP ZI1448;
			EXP ZI1447;
			EXP ZI1446;
			EXP ZI1445;
			EXP ZI1444;
			EXP ZI1443;
			EXP ZI1265;
			EXP ZI1289;
			EXP ZIa;
			int ZIr;

			ADVANCE_LEXER;
			ZRcast_Hoperand (&ZIt, &ZI1466, &ZIn);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: exp_dynamic_cast */
			{
#line 654 "syntax.act"

    /* n is the number of type definitions in t */
    (ZI1276) = make_dynamic_cast_exp ( (ZIt), (ZI1466), (ZIn) ) ;
#line 4561 "syntax4.c"
			}
			/* END OF ACTION: exp_dynamic_cast */
			ZR1242 (ZI1276, &ZI1454);
			ZR1238 (ZI1454, &ZI1453);
			ZR1234 (ZI1453, &ZI1452);
			ZR1230 (ZI1452, &ZI1451);
			ZR1226 (ZI1451, &ZI1450);
			ZR1222 (ZI1450, &ZI1449);
			ZR1218 (ZI1449, &ZI1448);
			ZR1214 (ZI1448, &ZI1447);
			ZR1210 (ZI1447, &ZI1446);
			ZR1206 (ZI1446, &ZI1445);
			ZR1202 (ZI1445, &ZI1444);
			ZR1198 (ZI1444, &ZI1443);
			ZR1194 (ZI1443, &ZI1265);
			ZR1266 (&ZI1265, &ZI1289);
			ZR1291 (&ZI1289, &ZIa);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: reach_check */
			{
#line 1121 "syntax.act"

    (ZIr) = unreached_code ;
    if ( (ZIr) ) {
	if ( !unreached_last ) {
	    report ( crt_loc, ERR_stmt_stmt_unreach () ) ;
	    unreached_last = 1 ;
	}
    } else {
	unreached_last = 0 ;
    }
#line 4596 "syntax4.c"
			}
			/* END OF ACTION: reach_check */
			/* BEGINNING OF ACTION: stmt_exp */
			{
#line 950 "syntax.act"

    (ZIe) = make_exp_stmt ( (ZIa) ) ;
#line 4604 "syntax4.c"
			}
			/* END OF ACTION: stmt_exp */
			/* BEGINNING OF ACTION: stmt_label_clear */
			{
#line 1018 "syntax.act"

    unreached_fall = 1 ;
#line 4612 "syntax4.c"
			}
			/* END OF ACTION: stmt_label_clear */
			switch (CURRENT_TERMINAL) {
			case 77:
				break;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
		}
		break;
	case 210:
		{
			EXP ZI1279;
			EXP ZI1454;
			EXP ZI1453;
			EXP ZI1452;
			EXP ZI1451;
			EXP ZI1450;
			EXP ZI1449;
			EXP ZI1448;
			EXP ZI1447;
			EXP ZI1446;
			EXP ZI1445;
			EXP ZI1444;
			EXP ZI1443;
			EXP ZI1265;
			EXP ZI1289;
			EXP ZIa;
			int ZIr;

			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: exp_ellipsis */
			{
#line 658 "syntax.act"

    (ZI1279) = make_ellipsis_exp () ;
#line 4650 "syntax4.c"
			}
			/* END OF ACTION: exp_ellipsis */
			ZR1242 (ZI1279, &ZI1454);
			ZR1238 (ZI1454, &ZI1453);
			ZR1234 (ZI1453, &ZI1452);
			ZR1230 (ZI1452, &ZI1451);
			ZR1226 (ZI1451, &ZI1450);
			ZR1222 (ZI1450, &ZI1449);
			ZR1218 (ZI1449, &ZI1448);
			ZR1214 (ZI1448, &ZI1447);
			ZR1210 (ZI1447, &ZI1446);
			ZR1206 (ZI1446, &ZI1445);
			ZR1202 (ZI1445, &ZI1444);
			ZR1198 (ZI1444, &ZI1443);
			ZR1194 (ZI1443, &ZI1265);
			ZR1266 (&ZI1265, &ZI1289);
			ZR1291 (&ZI1289, &ZIa);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: reach_check */
			{
#line 1121 "syntax.act"

    (ZIr) = unreached_code ;
    if ( (ZIr) ) {
	if ( !unreached_last ) {
	    report ( crt_loc, ERR_stmt_stmt_unreach () ) ;
	    unreached_last = 1 ;
	}
    } else {
	unreached_last = 0 ;
    }
#line 4685 "syntax4.c"
			}
			/* END OF ACTION: reach_check */
			/* BEGINNING OF ACTION: stmt_exp */
			{
#line 950 "syntax.act"

    (ZIe) = make_exp_stmt ( (ZIa) ) ;
#line 4693 "syntax4.c"
			}
			/* END OF ACTION: stmt_exp */
			/* BEGINNING OF ACTION: stmt_label_clear */
			{
#line 1018 "syntax.act"

    unreached_fall = 1 ;
#line 4701 "syntax4.c"
			}
			/* END OF ACTION: stmt_label_clear */
			switch (CURRENT_TERMINAL) {
			case 77:
				break;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
		}
		break;
	case 9:
		{
			NAMESPACE ZIns;

			/* BEGINNING OF EXTRACT: full-name */
			{
#line 266 "syntax.act"

    ZIns = crt_token->pp_data.ns ;
#line 4722 "syntax4.c"
			}
			/* END OF EXTRACT: full-name */
			ADVANCE_LEXER;
			ZR1476 (&ZIns, &ZIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 1:
		{
			IDENTIFIER ZI1467;

			/* BEGINNING OF EXTRACT: identifier */
			{
#line 217 "syntax.act"

    ZI1467 = crt_token->pp_data.id.use ;
#line 4742 "syntax4.c"
			}
			/* END OF EXTRACT: identifier */
			ADVANCE_LEXER;
			ZR1472 (&ZI1467, &ZIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 346:
		{
			ADVANCE_LEXER;
			ZR1441 (&ZIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 255:
		{
			EXP ZI1455;
			EXP ZI1454;
			EXP ZI1453;
			EXP ZI1452;
			EXP ZI1451;
			EXP ZI1450;
			EXP ZI1449;
			EXP ZI1448;
			EXP ZI1447;
			EXP ZI1446;
			EXP ZI1445;
			EXP ZI1444;
			EXP ZI1443;
			EXP ZI1265;
			EXP ZI1289;
			EXP ZIa;
			int ZIr;

			ADVANCE_LEXER;
			ZRcast_Hexpression (&ZI1455);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: exp_lit */
			{
#line 704 "syntax.act"

    (ZI1454) = make_lit_exp ( (ZI1455) ) ;
#line 4794 "syntax4.c"
			}
			/* END OF ACTION: exp_lit */
			ZR1238 (ZI1454, &ZI1453);
			ZR1234 (ZI1453, &ZI1452);
			ZR1230 (ZI1452, &ZI1451);
			ZR1226 (ZI1451, &ZI1450);
			ZR1222 (ZI1450, &ZI1449);
			ZR1218 (ZI1449, &ZI1448);
			ZR1214 (ZI1448, &ZI1447);
			ZR1210 (ZI1447, &ZI1446);
			ZR1206 (ZI1446, &ZI1445);
			ZR1202 (ZI1445, &ZI1444);
			ZR1198 (ZI1444, &ZI1443);
			ZR1194 (ZI1443, &ZI1265);
			ZR1266 (&ZI1265, &ZI1289);
			ZR1291 (&ZI1289, &ZIa);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: reach_check */
			{
#line 1121 "syntax.act"

    (ZIr) = unreached_code ;
    if ( (ZIr) ) {
	if ( !unreached_last ) {
	    report ( crt_loc, ERR_stmt_stmt_unreach () ) ;
	    unreached_last = 1 ;
	}
    } else {
	unreached_last = 0 ;
    }
#line 4828 "syntax4.c"
			}
			/* END OF ACTION: reach_check */
			/* BEGINNING OF ACTION: stmt_exp */
			{
#line 950 "syntax.act"

    (ZIe) = make_exp_stmt ( (ZIa) ) ;
#line 4836 "syntax4.c"
			}
			/* END OF ACTION: stmt_exp */
			/* BEGINNING OF ACTION: stmt_label_clear */
			{
#line 1018 "syntax.act"

    unreached_fall = 1 ;
#line 4844 "syntax4.c"
			}
			/* END OF ACTION: stmt_label_clear */
			switch (CURRENT_TERMINAL) {
			case 77:
				break;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
		}
		break;
	case 61:
		{
			EXP ZI1458;
			EXP ZI1454;
			EXP ZI1453;
			EXP ZI1452;
			EXP ZI1451;
			EXP ZI1450;
			EXP ZI1449;
			EXP ZI1448;
			EXP ZI1447;
			EXP ZI1446;
			EXP ZI1445;
			EXP ZI1444;
			EXP ZI1443;
			EXP ZI1265;
			EXP ZI1289;
			EXP ZIa;
			int ZIr;

			ADVANCE_LEXER;
			ZRcast_Hexpression (&ZI1458);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: exp_predec */
			{
#line 785 "syntax.act"

    (ZI1454) = make_prefix_exp ( lex_minus_Hminus, (ZI1458) ) ;
#line 4887 "syntax4.c"
			}
			/* END OF ACTION: exp_predec */
			ZR1238 (ZI1454, &ZI1453);
			ZR1234 (ZI1453, &ZI1452);
			ZR1230 (ZI1452, &ZI1451);
			ZR1226 (ZI1451, &ZI1450);
			ZR1222 (ZI1450, &ZI1449);
			ZR1218 (ZI1449, &ZI1448);
			ZR1214 (ZI1448, &ZI1447);
			ZR1210 (ZI1447, &ZI1446);
			ZR1206 (ZI1446, &ZI1445);
			ZR1202 (ZI1445, &ZI1444);
			ZR1198 (ZI1444, &ZI1443);
			ZR1194 (ZI1443, &ZI1265);
			ZR1266 (&ZI1265, &ZI1289);
			ZR1291 (&ZI1289, &ZIa);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: reach_check */
			{
#line 1121 "syntax.act"

    (ZIr) = unreached_code ;
    if ( (ZIr) ) {
	if ( !unreached_last ) {
	    report ( crt_loc, ERR_stmt_stmt_unreach () ) ;
	    unreached_last = 1 ;
	}
    } else {
	unreached_last = 0 ;
    }
#line 4921 "syntax4.c"
			}
			/* END OF ACTION: reach_check */
			/* BEGINNING OF ACTION: stmt_exp */
			{
#line 950 "syntax.act"

    (ZIe) = make_exp_stmt ( (ZIa) ) ;
#line 4929 "syntax4.c"
			}
			/* END OF ACTION: stmt_exp */
			/* BEGINNING OF ACTION: stmt_label_clear */
			{
#line 1018 "syntax.act"

    unreached_fall = 1 ;
#line 4937 "syntax4.c"
			}
			/* END OF ACTION: stmt_label_clear */
			switch (CURRENT_TERMINAL) {
			case 77:
				break;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
		}
		break;
	case 3:
		{
			IDENTIFIER ZI1471;

			/* BEGINNING OF EXTRACT: namespace-name */
			{
#line 225 "syntax.act"

    ZI1471 = crt_token->pp_data.id.use ;
#line 4958 "syntax4.c"
			}
			/* END OF EXTRACT: namespace-name */
			ADVANCE_LEXER;
			ZR1472 (&ZI1471, &ZIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 8:
		{
			NAMESPACE ZIns;

			/* BEGINNING OF EXTRACT: nested-name */
			{
#line 262 "syntax.act"

    ZIns = crt_token->pp_data.ns ;
#line 4978 "syntax4.c"
			}
			/* END OF EXTRACT: nested-name */
			ADVANCE_LEXER;
			ZR1475 (&ZIns, &ZIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 65:
		{
			EXP ZI1454;
			EXP ZI1453;
			EXP ZI1452;
			EXP ZI1451;
			EXP ZI1450;
			EXP ZI1449;
			EXP ZI1448;
			EXP ZI1447;
			EXP ZI1446;
			EXP ZI1445;
			EXP ZI1444;
			EXP ZI1443;
			EXP ZI1265;
			EXP ZI1289;
			EXP ZIa;
			int ZIr;

			ADVANCE_LEXER;
			ZR1288 (&ZI1454);
			ZR1238 (ZI1454, &ZI1453);
			ZR1234 (ZI1453, &ZI1452);
			ZR1230 (ZI1452, &ZI1451);
			ZR1226 (ZI1451, &ZI1450);
			ZR1222 (ZI1450, &ZI1449);
			ZR1218 (ZI1449, &ZI1448);
			ZR1214 (ZI1448, &ZI1447);
			ZR1210 (ZI1447, &ZI1446);
			ZR1206 (ZI1446, &ZI1445);
			ZR1202 (ZI1445, &ZI1444);
			ZR1198 (ZI1444, &ZI1443);
			ZR1194 (ZI1443, &ZI1265);
			ZR1266 (&ZI1265, &ZI1289);
			ZR1291 (&ZI1289, &ZIa);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: reach_check */
			{
#line 1121 "syntax.act"

    (ZIr) = unreached_code ;
    if ( (ZIr) ) {
	if ( !unreached_last ) {
	    report ( crt_loc, ERR_stmt_stmt_unreach () ) ;
	    unreached_last = 1 ;
	}
    } else {
	unreached_last = 0 ;
    }
#line 5041 "syntax4.c"
			}
			/* END OF ACTION: reach_check */
			/* BEGINNING OF ACTION: stmt_exp */
			{
#line 950 "syntax.act"

    (ZIe) = make_exp_stmt ( (ZIa) ) ;
#line 5049 "syntax4.c"
			}
			/* END OF ACTION: stmt_exp */
			/* BEGINNING OF ACTION: stmt_label_clear */
			{
#line 1018 "syntax.act"

    unreached_fall = 1 ;
#line 5057 "syntax4.c"
			}
			/* END OF ACTION: stmt_label_clear */
			switch (CURRENT_TERMINAL) {
			case 77:
				break;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
		}
		break;
	case 71:
		{
			EXP ZI1457;
			EXP ZI1454;
			EXP ZI1453;
			EXP ZI1452;
			EXP ZI1451;
			EXP ZI1450;
			EXP ZI1449;
			EXP ZI1448;
			EXP ZI1447;
			EXP ZI1446;
			EXP ZI1445;
			EXP ZI1444;
			EXP ZI1443;
			EXP ZI1265;
			EXP ZI1289;
			EXP ZIa;
			int ZIr;

			ADVANCE_LEXER;
			ZRcast_Hexpression (&ZI1457);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: exp_preinc */
			{
#line 789 "syntax.act"

    (ZI1454) = make_prefix_exp ( lex_plus_Hplus, (ZI1457) ) ;
#line 5100 "syntax4.c"
			}
			/* END OF ACTION: exp_preinc */
			ZR1238 (ZI1454, &ZI1453);
			ZR1234 (ZI1453, &ZI1452);
			ZR1230 (ZI1452, &ZI1451);
			ZR1226 (ZI1451, &ZI1450);
			ZR1222 (ZI1450, &ZI1449);
			ZR1218 (ZI1449, &ZI1448);
			ZR1214 (ZI1448, &ZI1447);
			ZR1210 (ZI1447, &ZI1446);
			ZR1206 (ZI1446, &ZI1445);
			ZR1202 (ZI1445, &ZI1444);
			ZR1198 (ZI1444, &ZI1443);
			ZR1194 (ZI1443, &ZI1265);
			ZR1266 (&ZI1265, &ZI1289);
			ZR1291 (&ZI1289, &ZIa);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: reach_check */
			{
#line 1121 "syntax.act"

    (ZIr) = unreached_code ;
    if ( (ZIr) ) {
	if ( !unreached_last ) {
	    report ( crt_loc, ERR_stmt_stmt_unreach () ) ;
	    unreached_last = 1 ;
	}
    } else {
	unreached_last = 0 ;
    }
#line 5134 "syntax4.c"
			}
			/* END OF ACTION: reach_check */
			/* BEGINNING OF ACTION: stmt_exp */
			{
#line 950 "syntax.act"

    (ZIe) = make_exp_stmt ( (ZIa) ) ;
#line 5142 "syntax4.c"
			}
			/* END OF ACTION: stmt_exp */
			/* BEGINNING OF ACTION: stmt_label_clear */
			{
#line 1018 "syntax.act"

    unreached_fall = 1 ;
#line 5150 "syntax4.c"
			}
			/* END OF ACTION: stmt_label_clear */
			switch (CURRENT_TERMINAL) {
			case 77:
				break;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
		}
		break;
	case 145:
		{
			TYPE ZIt;
			EXP ZI1464;
			int ZIn;
			EXP ZI1274;
			EXP ZI1454;
			EXP ZI1453;
			EXP ZI1452;
			EXP ZI1451;
			EXP ZI1450;
			EXP ZI1449;
			EXP ZI1448;
			EXP ZI1447;
			EXP ZI1446;
			EXP ZI1445;
			EXP ZI1444;
			EXP ZI1443;
			EXP ZI1265;
			EXP ZI1289;
			EXP ZIa;
			int ZIr;

			ADVANCE_LEXER;
			ZRcast_Hoperand (&ZIt, &ZI1464, &ZIn);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: exp_reinterpret_cast */
			{
#line 802 "syntax.act"

    /* n is the number of type definitions in t */
    (ZI1274) = make_reinterp_cast_exp ( (ZIt), (ZI1464), (ZIn) ) ;
#line 5197 "syntax4.c"
			}
			/* END OF ACTION: exp_reinterpret_cast */
			ZR1242 (ZI1274, &ZI1454);
			ZR1238 (ZI1454, &ZI1453);
			ZR1234 (ZI1453, &ZI1452);
			ZR1230 (ZI1452, &ZI1451);
			ZR1226 (ZI1451, &ZI1450);
			ZR1222 (ZI1450, &ZI1449);
			ZR1218 (ZI1449, &ZI1448);
			ZR1214 (ZI1448, &ZI1447);
			ZR1210 (ZI1447, &ZI1446);
			ZR1206 (ZI1446, &ZI1445);
			ZR1202 (ZI1445, &ZI1444);
			ZR1198 (ZI1444, &ZI1443);
			ZR1194 (ZI1443, &ZI1265);
			ZR1266 (&ZI1265, &ZI1289);
			ZR1291 (&ZI1289, &ZIa);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: reach_check */
			{
#line 1121 "syntax.act"

    (ZIr) = unreached_code ;
    if ( (ZIr) ) {
	if ( !unreached_last ) {
	    report ( crt_loc, ERR_stmt_stmt_unreach () ) ;
	    unreached_last = 1 ;
	}
    } else {
	unreached_last = 0 ;
    }
#line 5232 "syntax4.c"
			}
			/* END OF ACTION: reach_check */
			/* BEGINNING OF ACTION: stmt_exp */
			{
#line 950 "syntax.act"

    (ZIe) = make_exp_stmt ( (ZIa) ) ;
#line 5240 "syntax4.c"
			}
			/* END OF ACTION: stmt_exp */
			/* BEGINNING OF ACTION: stmt_label_clear */
			{
#line 1018 "syntax.act"

    unreached_fall = 1 ;
#line 5248 "syntax4.c"
			}
			/* END OF ACTION: stmt_label_clear */
			switch (CURRENT_TERMINAL) {
			case 77:
				break;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
		}
		break;
	case 77:
		{
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: stmt_none */
			{
#line 877 "syntax.act"

    (ZIe) = NULL_exp ;
#line 5268 "syntax4.c"
			}
			/* END OF ACTION: stmt_none */
		}
		break;
	case 116:
		{
			int ZIop;
			EXP ZI1454;
			EXP ZI1453;
			EXP ZI1452;
			EXP ZI1451;
			EXP ZI1450;
			EXP ZI1449;
			EXP ZI1448;
			EXP ZI1447;
			EXP ZI1446;
			EXP ZI1445;
			EXP ZI1444;
			EXP ZI1443;
			EXP ZI1265;
			EXP ZI1289;
			EXP ZIa;
			int ZIr;

			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: lex_sizeof */
			{
#line 403 "syntax.act"
 (ZIop) = lex_sizeof ; 
#line 5298 "syntax4.c"
			}
			/* END OF ACTION: lex_sizeof */
			ZRsizeof_Hexpression (ZIop, &ZI1454);
			ZR1238 (ZI1454, &ZI1453);
			ZR1234 (ZI1453, &ZI1452);
			ZR1230 (ZI1452, &ZI1451);
			ZR1226 (ZI1451, &ZI1450);
			ZR1222 (ZI1450, &ZI1449);
			ZR1218 (ZI1449, &ZI1448);
			ZR1214 (ZI1448, &ZI1447);
			ZR1210 (ZI1447, &ZI1446);
			ZR1206 (ZI1446, &ZI1445);
			ZR1202 (ZI1445, &ZI1444);
			ZR1198 (ZI1444, &ZI1443);
			ZR1194 (ZI1443, &ZI1265);
			ZR1266 (&ZI1265, &ZI1289);
			ZR1291 (&ZI1289, &ZIa);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: reach_check */
			{
#line 1121 "syntax.act"

    (ZIr) = unreached_code ;
    if ( (ZIr) ) {
	if ( !unreached_last ) {
	    report ( crt_loc, ERR_stmt_stmt_unreach () ) ;
	    unreached_last = 1 ;
	}
    } else {
	unreached_last = 0 ;
    }
#line 5333 "syntax4.c"
			}
			/* END OF ACTION: reach_check */
			/* BEGINNING OF ACTION: stmt_exp */
			{
#line 950 "syntax.act"

    (ZIe) = make_exp_stmt ( (ZIa) ) ;
#line 5341 "syntax4.c"
			}
			/* END OF ACTION: stmt_exp */
			/* BEGINNING OF ACTION: stmt_label_clear */
			{
#line 1018 "syntax.act"

    unreached_fall = 1 ;
#line 5349 "syntax4.c"
			}
			/* END OF ACTION: stmt_label_clear */
			switch (CURRENT_TERMINAL) {
			case 77:
				break;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
		}
		break;
	case 78:
		{
			EXP ZI1459;
			EXP ZI1454;
			EXP ZI1453;
			EXP ZI1452;
			EXP ZI1451;
			EXP ZI1450;
			EXP ZI1449;
			EXP ZI1448;
			EXP ZI1447;
			EXP ZI1446;
			EXP ZI1445;
			EXP ZI1444;
			EXP ZI1443;
			EXP ZI1265;
			EXP ZI1289;
			EXP ZIa;
			int ZIr;

			ADVANCE_LEXER;
			ZRcast_Hexpression (&ZI1459);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: exp_indir */
			{
#line 696 "syntax.act"

    (ZI1454) = make_indir_exp ( (ZI1459) ) ;
#line 5392 "syntax4.c"
			}
			/* END OF ACTION: exp_indir */
			ZR1238 (ZI1454, &ZI1453);
			ZR1234 (ZI1453, &ZI1452);
			ZR1230 (ZI1452, &ZI1451);
			ZR1226 (ZI1451, &ZI1450);
			ZR1222 (ZI1450, &ZI1449);
			ZR1218 (ZI1449, &ZI1448);
			ZR1214 (ZI1448, &ZI1447);
			ZR1210 (ZI1447, &ZI1446);
			ZR1206 (ZI1446, &ZI1445);
			ZR1202 (ZI1445, &ZI1444);
			ZR1198 (ZI1444, &ZI1443);
			ZR1194 (ZI1443, &ZI1265);
			ZR1266 (&ZI1265, &ZI1289);
			ZR1291 (&ZI1289, &ZIa);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: reach_check */
			{
#line 1121 "syntax.act"

    (ZIr) = unreached_code ;
    if ( (ZIr) ) {
	if ( !unreached_last ) {
	    report ( crt_loc, ERR_stmt_stmt_unreach () ) ;
	    unreached_last = 1 ;
	}
    } else {
	unreached_last = 0 ;
    }
#line 5426 "syntax4.c"
			}
			/* END OF ACTION: reach_check */
			/* BEGINNING OF ACTION: stmt_exp */
			{
#line 950 "syntax.act"

    (ZIe) = make_exp_stmt ( (ZIa) ) ;
#line 5434 "syntax4.c"
			}
			/* END OF ACTION: stmt_exp */
			/* BEGINNING OF ACTION: stmt_label_clear */
			{
#line 1018 "syntax.act"

    unreached_fall = 1 ;
#line 5442 "syntax4.c"
			}
			/* END OF ACTION: stmt_label_clear */
			switch (CURRENT_TERMINAL) {
			case 77:
				break;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
		}
		break;
	case 4:
		{
			IDENTIFIER ZI1473;

			/* BEGINNING OF EXTRACT: statement-name */
			{
#line 229 "syntax.act"

    ZI1473 = crt_token->pp_data.id.use ;
#line 5463 "syntax4.c"
			}
			/* END OF EXTRACT: statement-name */
			ADVANCE_LEXER;
			ZR1474 (&ZI1473, &ZIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 146:
		{
			TYPE ZIt;
			EXP ZI1465;
			int ZIn;
			EXP ZI1275;
			EXP ZI1454;
			EXP ZI1453;
			EXP ZI1452;
			EXP ZI1451;
			EXP ZI1450;
			EXP ZI1449;
			EXP ZI1448;
			EXP ZI1447;
			EXP ZI1446;
			EXP ZI1445;
			EXP ZI1444;
			EXP ZI1443;
			EXP ZI1265;
			EXP ZI1289;
			EXP ZIa;
			int ZIr;

			ADVANCE_LEXER;
			ZRcast_Hoperand (&ZIt, &ZI1465, &ZIn);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: exp_static_cast */
			{
#line 827 "syntax.act"

    (ZI1275) = make_static_cast_exp ( (ZIt), (ZI1465), (ZIn) ) ;
#line 5508 "syntax4.c"
			}
			/* END OF ACTION: exp_static_cast */
			ZR1242 (ZI1275, &ZI1454);
			ZR1238 (ZI1454, &ZI1453);
			ZR1234 (ZI1453, &ZI1452);
			ZR1230 (ZI1452, &ZI1451);
			ZR1226 (ZI1451, &ZI1450);
			ZR1222 (ZI1450, &ZI1449);
			ZR1218 (ZI1449, &ZI1448);
			ZR1214 (ZI1448, &ZI1447);
			ZR1210 (ZI1447, &ZI1446);
			ZR1206 (ZI1446, &ZI1445);
			ZR1202 (ZI1445, &ZI1444);
			ZR1198 (ZI1444, &ZI1443);
			ZR1194 (ZI1443, &ZI1265);
			ZR1266 (&ZI1265, &ZI1289);
			ZR1291 (&ZI1289, &ZIa);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: reach_check */
			{
#line 1121 "syntax.act"

    (ZIr) = unreached_code ;
    if ( (ZIr) ) {
	if ( !unreached_last ) {
	    report ( crt_loc, ERR_stmt_stmt_unreach () ) ;
	    unreached_last = 1 ;
	}
    } else {
	unreached_last = 0 ;
    }
#line 5543 "syntax4.c"
			}
			/* END OF ACTION: reach_check */
			/* BEGINNING OF ACTION: stmt_exp */
			{
#line 950 "syntax.act"

    (ZIe) = make_exp_stmt ( (ZIa) ) ;
#line 5551 "syntax4.c"
			}
			/* END OF ACTION: stmt_exp */
			/* BEGINNING OF ACTION: stmt_label_clear */
			{
#line 1018 "syntax.act"

    unreached_fall = 1 ;
#line 5559 "syntax4.c"
			}
			/* END OF ACTION: stmt_label_clear */
			switch (CURRENT_TERMINAL) {
			case 77:
				break;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
		}
		break;
	case 6:
		{
			IDENTIFIER ZIuid;
			IDENTIFIER ZIid;
			EXP ZI1285;
			EXP ZI1454;
			EXP ZI1453;
			EXP ZI1452;
			EXP ZI1451;
			EXP ZI1450;
			EXP ZI1449;
			EXP ZI1448;
			EXP ZI1447;
			EXP ZI1446;
			EXP ZI1445;
			EXP ZI1444;
			EXP ZI1443;
			EXP ZI1265;
			EXP ZI1289;
			EXP ZIa;
			int ZIr;

			/* BEGINNING OF EXTRACT: template-id */
			{
#line 239 "syntax.act"

    IDENTIFIER id = crt_token->pp_data.tok.id ;
    PPTOKEN *args = crt_token->pp_data.tok.args ;
    ZIuid = parse_id_template ( id, args, 0 ) ;
    crt_templ_qualifier = 1 ;
    RESCAN_LEXER ;
#line 5602 "syntax4.c"
			}
			/* END OF EXTRACT: template-id */
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: namespace_complex */
			{
#line 513 "syntax.act"

    (ZIid) = check_id ( NULL_nspace, (ZIuid), 0 ) ;
    crt_id_qualifier = qual_none ;
    last_namespace = crt_namespace ;
#line 5613 "syntax4.c"
			}
			/* END OF ACTION: namespace_complex */
			/* BEGINNING OF ACTION: exp_identifier */
			{
#line 684 "syntax.act"

    (ZI1285) = make_id_exp ( (ZIid) ) ;
#line 5621 "syntax4.c"
			}
			/* END OF ACTION: exp_identifier */
			ZR1242 (ZI1285, &ZI1454);
			ZR1238 (ZI1454, &ZI1453);
			ZR1234 (ZI1453, &ZI1452);
			ZR1230 (ZI1452, &ZI1451);
			ZR1226 (ZI1451, &ZI1450);
			ZR1222 (ZI1450, &ZI1449);
			ZR1218 (ZI1449, &ZI1448);
			ZR1214 (ZI1448, &ZI1447);
			ZR1210 (ZI1447, &ZI1446);
			ZR1206 (ZI1446, &ZI1445);
			ZR1202 (ZI1445, &ZI1444);
			ZR1198 (ZI1444, &ZI1443);
			ZR1194 (ZI1443, &ZI1265);
			ZR1266 (&ZI1265, &ZI1289);
			ZR1291 (&ZI1289, &ZIa);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: reach_check */
			{
#line 1121 "syntax.act"

    (ZIr) = unreached_code ;
    if ( (ZIr) ) {
	if ( !unreached_last ) {
	    report ( crt_loc, ERR_stmt_stmt_unreach () ) ;
	    unreached_last = 1 ;
	}
    } else {
	unreached_last = 0 ;
    }
#line 5656 "syntax4.c"
			}
			/* END OF ACTION: reach_check */
			/* BEGINNING OF ACTION: stmt_exp */
			{
#line 950 "syntax.act"

    (ZIe) = make_exp_stmt ( (ZIa) ) ;
#line 5664 "syntax4.c"
			}
			/* END OF ACTION: stmt_exp */
			/* BEGINNING OF ACTION: stmt_label_clear */
			{
#line 1018 "syntax.act"

    unreached_fall = 1 ;
#line 5672 "syntax4.c"
			}
			/* END OF ACTION: stmt_label_clear */
			switch (CURRENT_TERMINAL) {
			case 77:
				break;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
		}
		break;
	case 7:
		{
			IDENTIFIER ZItid;
			IDENTIFIER ZIid;
			TYPE ZI1267;
			BASE_TYPE ZIbt;
			CV_SPEC ZIcv;
			TYPE ZIt;
			SID_LIST_EXP ZIp;
			EXP ZI1283;
			EXP ZI1454;
			EXP ZI1453;
			EXP ZI1452;
			EXP ZI1451;
			EXP ZI1450;
			EXP ZI1449;
			EXP ZI1448;
			EXP ZI1447;
			EXP ZI1446;
			EXP ZI1445;
			EXP ZI1444;
			EXP ZI1443;
			EXP ZI1265;
			EXP ZI1289;
			EXP ZIa;
			int ZIr;

			/* BEGINNING OF EXTRACT: template-type */
			{
#line 247 "syntax.act"

    IDENTIFIER id = crt_token->pp_data.tok.id ;
    PPTOKEN *args = crt_token->pp_data.tok.args ;
    ZItid = parse_type_template ( id, args, 0 ) ;
    crt_templ_qualifier = 1 ;
    RESCAN_LEXER ;
#line 5720 "syntax4.c"
			}
			/* END OF EXTRACT: template-type */
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: namespace_simple */
			{
#line 507 "syntax.act"

    (ZIid) = (ZItid) ;
    crt_id_qualifier = qual_none ;
    last_namespace = crt_namespace ;
#line 5731 "syntax4.c"
			}
			/* END OF ACTION: namespace_simple */
			/* BEGINNING OF ACTION: type_name */
			{
#line 1285 "syntax.act"

    MAKE_type_pre ( cv_none, btype_alias, crt_id_qualifier, (ZI1267) ) ;
    COPY_id ( type_name ( (ZI1267) ), (ZIid) ) ;
    have_type_specifier = 1 ;
#line 5741 "syntax4.c"
			}
			/* END OF ACTION: type_name */
			/* BEGINNING OF ACTION: btype_none */
			{
#line 1252 "syntax.act"
 (ZIbt) = btype_none ; 
#line 5748 "syntax4.c"
			}
			/* END OF ACTION: btype_none */
			/* BEGINNING OF ACTION: cv_none */
			{
#line 1220 "syntax.act"
 (ZIcv) = cv_none ; 
#line 5755 "syntax4.c"
			}
			/* END OF ACTION: cv_none */
			/* BEGINNING OF ACTION: type_complete */
			{
#line 1321 "syntax.act"

    (ZIt) = complete_pre_type ( (ZIbt), (ZI1267), (ZIcv), 1 ) ;
    have_type_specifier = 0 ;
#line 5764 "syntax4.c"
			}
			/* END OF ACTION: type_complete */
			switch (CURRENT_TERMINAL) {
			case 65:
				break;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
			ZRexpression_Hlist_Hopt (&ZIp);
			switch (CURRENT_TERMINAL) {
			case 39:
				break;
			case 355:
				RESTORE_LEXER;
				goto ZL1;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: exp_func_cast */
			{
#line 680 "syntax.act"

    (ZI1283) = make_func_cast_exp ( (ZIt), (ZIp) ) ;
#line 5790 "syntax4.c"
			}
			/* END OF ACTION: exp_func_cast */
			ZR1242 (ZI1283, &ZI1454);
			ZR1238 (ZI1454, &ZI1453);
			ZR1234 (ZI1453, &ZI1452);
			ZR1230 (ZI1452, &ZI1451);
			ZR1226 (ZI1451, &ZI1450);
			ZR1222 (ZI1450, &ZI1449);
			ZR1218 (ZI1449, &ZI1448);
			ZR1214 (ZI1448, &ZI1447);
			ZR1210 (ZI1447, &ZI1446);
			ZR1206 (ZI1446, &ZI1445);
			ZR1202 (ZI1445, &ZI1444);
			ZR1198 (ZI1444, &ZI1443);
			ZR1194 (ZI1443, &ZI1265);
			ZR1266 (&ZI1265, &ZI1289);
			ZR1291 (&ZI1289, &ZIa);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: reach_check */
			{
#line 1121 "syntax.act"

    (ZIr) = unreached_code ;
    if ( (ZIr) ) {
	if ( !unreached_last ) {
	    report ( crt_loc, ERR_stmt_stmt_unreach () ) ;
	    unreached_last = 1 ;
	}
    } else {
	unreached_last = 0 ;
    }
#line 5825 "syntax4.c"
			}
			/* END OF ACTION: reach_check */
			/* BEGINNING OF ACTION: stmt_exp */
			{
#line 950 "syntax.act"

    (ZIe) = make_exp_stmt ( (ZIa) ) ;
#line 5833 "syntax4.c"
			}
			/* END OF ACTION: stmt_exp */
			/* BEGINNING OF ACTION: stmt_label_clear */
			{
#line 1018 "syntax.act"

    unreached_fall = 1 ;
#line 5841 "syntax4.c"
			}
			/* END OF ACTION: stmt_label_clear */
			switch (CURRENT_TERMINAL) {
			case 77:
				break;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
		}
		break;
	case 148:
		{
			EXP ZI1278;
			EXP ZI1454;
			EXP ZI1453;
			EXP ZI1452;
			EXP ZI1451;
			EXP ZI1450;
			EXP ZI1449;
			EXP ZI1448;
			EXP ZI1447;
			EXP ZI1446;
			EXP ZI1445;
			EXP ZI1444;
			EXP ZI1443;
			EXP ZI1265;
			EXP ZI1289;
			EXP ZIa;
			int ZIr;

			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: exp_this */
			{
#line 831 "syntax.act"

    (ZI1278) = make_this_exp () ;
#line 5879 "syntax4.c"
			}
			/* END OF ACTION: exp_this */
			ZR1242 (ZI1278, &ZI1454);
			ZR1238 (ZI1454, &ZI1453);
			ZR1234 (ZI1453, &ZI1452);
			ZR1230 (ZI1452, &ZI1451);
			ZR1226 (ZI1451, &ZI1450);
			ZR1222 (ZI1450, &ZI1449);
			ZR1218 (ZI1449, &ZI1448);
			ZR1214 (ZI1448, &ZI1447);
			ZR1210 (ZI1447, &ZI1446);
			ZR1206 (ZI1446, &ZI1445);
			ZR1202 (ZI1445, &ZI1444);
			ZR1198 (ZI1444, &ZI1443);
			ZR1194 (ZI1443, &ZI1265);
			ZR1266 (&ZI1265, &ZI1289);
			ZR1291 (&ZI1289, &ZIa);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: reach_check */
			{
#line 1121 "syntax.act"

    (ZIr) = unreached_code ;
    if ( (ZIr) ) {
	if ( !unreached_last ) {
	    report ( crt_loc, ERR_stmt_stmt_unreach () ) ;
	    unreached_last = 1 ;
	}
    } else {
	unreached_last = 0 ;
    }
#line 5914 "syntax4.c"
			}
			/* END OF ACTION: reach_check */
			/* BEGINNING OF ACTION: stmt_exp */
			{
#line 950 "syntax.act"

    (ZIe) = make_exp_stmt ( (ZIa) ) ;
#line 5922 "syntax4.c"
			}
			/* END OF ACTION: stmt_exp */
			/* BEGINNING OF ACTION: stmt_label_clear */
			{
#line 1018 "syntax.act"

    unreached_fall = 1 ;
#line 5930 "syntax4.c"
			}
			/* END OF ACTION: stmt_label_clear */
			switch (CURRENT_TERMINAL) {
			case 77:
				break;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
		}
		break;
	case 2:
		{
			IDENTIFIER ZI1469;

			/* BEGINNING OF EXTRACT: type-name */
			{
#line 221 "syntax.act"

    ZI1469 = crt_token->pp_data.id.use ;
#line 5951 "syntax4.c"
			}
			/* END OF EXTRACT: type-name */
			ADVANCE_LEXER;
			ZR1470 (&ZI1469, &ZIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 152:
		{
			int ZIop;
			EXP ZI1272;
			EXP ZI1454;
			EXP ZI1453;
			EXP ZI1452;
			EXP ZI1451;
			EXP ZI1450;
			EXP ZI1449;
			EXP ZI1448;
			EXP ZI1447;
			EXP ZI1446;
			EXP ZI1445;
			EXP ZI1444;
			EXP ZI1443;
			EXP ZI1265;
			EXP ZI1289;
			EXP ZIa;
			int ZIr;

			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: lex_typeid */
			{
#line 404 "syntax.act"
 (ZIop) = lex_typeid ; 
#line 5988 "syntax4.c"
			}
			/* END OF ACTION: lex_typeid */
			ZRtypeid_Hexpression (ZIop, &ZI1272);
			ZR1242 (ZI1272, &ZI1454);
			ZR1238 (ZI1454, &ZI1453);
			ZR1234 (ZI1453, &ZI1452);
			ZR1230 (ZI1452, &ZI1451);
			ZR1226 (ZI1451, &ZI1450);
			ZR1222 (ZI1450, &ZI1449);
			ZR1218 (ZI1449, &ZI1448);
			ZR1214 (ZI1448, &ZI1447);
			ZR1210 (ZI1447, &ZI1446);
			ZR1206 (ZI1446, &ZI1445);
			ZR1202 (ZI1445, &ZI1444);
			ZR1198 (ZI1444, &ZI1443);
			ZR1194 (ZI1443, &ZI1265);
			ZR1266 (&ZI1265, &ZI1289);
			ZR1291 (&ZI1289, &ZIa);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: reach_check */
			{
#line 1121 "syntax.act"

    (ZIr) = unreached_code ;
    if ( (ZIr) ) {
	if ( !unreached_last ) {
	    report ( crt_loc, ERR_stmt_stmt_unreach () ) ;
	    unreached_last = 1 ;
	}
    } else {
	unreached_last = 0 ;
    }
#line 6024 "syntax4.c"
			}
			/* END OF ACTION: reach_check */
			/* BEGINNING OF ACTION: stmt_exp */
			{
#line 950 "syntax.act"

    (ZIe) = make_exp_stmt ( (ZIa) ) ;
#line 6032 "syntax4.c"
			}
			/* END OF ACTION: stmt_exp */
			/* BEGINNING OF ACTION: stmt_label_clear */
			{
#line 1018 "syntax.act"

    unreached_fall = 1 ;
#line 6040 "syntax4.c"
			}
			/* END OF ACTION: stmt_label_clear */
			switch (CURRENT_TERMINAL) {
			case 77:
				break;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
		}
		break;
	case 330:
		{
			int ZIop;
			EXP ZI1271;
			EXP ZI1454;
			EXP ZI1453;
			EXP ZI1452;
			EXP ZI1451;
			EXP ZI1450;
			EXP ZI1449;
			EXP ZI1448;
			EXP ZI1447;
			EXP ZI1446;
			EXP ZI1445;
			EXP ZI1444;
			EXP ZI1443;
			EXP ZI1265;
			EXP ZI1289;
			EXP ZIa;
			int ZIr;

			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: lex_vtable */
			{
#line 405 "syntax.act"
 (ZIop) = lex_vtable ; 
#line 6078 "syntax4.c"
			}
			/* END OF ACTION: lex_vtable */
			ZRtypeid_Hexpression (ZIop, &ZI1271);
			ZR1242 (ZI1271, &ZI1454);
			ZR1238 (ZI1454, &ZI1453);
			ZR1234 (ZI1453, &ZI1452);
			ZR1230 (ZI1452, &ZI1451);
			ZR1226 (ZI1451, &ZI1450);
			ZR1222 (ZI1450, &ZI1449);
			ZR1218 (ZI1449, &ZI1448);
			ZR1214 (ZI1448, &ZI1447);
			ZR1210 (ZI1447, &ZI1446);
			ZR1206 (ZI1446, &ZI1445);
			ZR1202 (ZI1445, &ZI1444);
			ZR1198 (ZI1444, &ZI1443);
			ZR1194 (ZI1443, &ZI1265);
			ZR1266 (&ZI1265, &ZI1289);
			ZR1291 (&ZI1289, &ZIa);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: reach_check */
			{
#line 1121 "syntax.act"

    (ZIr) = unreached_code ;
    if ( (ZIr) ) {
	if ( !unreached_last ) {
	    report ( crt_loc, ERR_stmt_stmt_unreach () ) ;
	    unreached_last = 1 ;
	}
    } else {
	unreached_last = 0 ;
    }
#line 6114 "syntax4.c"
			}
			/* END OF ACTION: reach_check */
			/* BEGINNING OF ACTION: stmt_exp */
			{
#line 950 "syntax.act"

    (ZIe) = make_exp_stmt ( (ZIa) ) ;
#line 6122 "syntax4.c"
			}
			/* END OF ACTION: stmt_exp */
			/* BEGINNING OF ACTION: stmt_label_clear */
			{
#line 1018 "syntax.act"

    unreached_fall = 1 ;
#line 6130 "syntax4.c"
			}
			/* END OF ACTION: stmt_label_clear */
			switch (CURRENT_TERMINAL) {
			case 77:
				break;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
		}
		break;
	case 33:
		{
			EXP ZI1460;
			EXP ZI1454;
			EXP ZI1453;
			EXP ZI1452;
			EXP ZI1451;
			EXP ZI1450;
			EXP ZI1449;
			EXP ZI1448;
			EXP ZI1447;
			EXP ZI1446;
			EXP ZI1445;
			EXP ZI1444;
			EXP ZI1443;
			EXP ZI1265;
			EXP ZI1289;
			EXP ZIa;
			int ZIr;

			/* BEGINNING OF INLINE: and */
			{
				{
					switch (CURRENT_TERMINAL) {
					case 33:
						break;
					default:
						goto ZL1;
					}
					ADVANCE_LEXER;
				}
			}
			/* END OF INLINE: and */
			ZRcast_Hexpression (&ZI1460);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: exp_ref */
			{
#line 797 "syntax.act"

    (ZI1454) = make_ref_exp ( (ZI1460), 0 ) ;
#line 6185 "syntax4.c"
			}
			/* END OF ACTION: exp_ref */
			ZR1238 (ZI1454, &ZI1453);
			ZR1234 (ZI1453, &ZI1452);
			ZR1230 (ZI1452, &ZI1451);
			ZR1226 (ZI1451, &ZI1450);
			ZR1222 (ZI1450, &ZI1449);
			ZR1218 (ZI1449, &ZI1448);
			ZR1214 (ZI1448, &ZI1447);
			ZR1210 (ZI1447, &ZI1446);
			ZR1206 (ZI1446, &ZI1445);
			ZR1202 (ZI1445, &ZI1444);
			ZR1198 (ZI1444, &ZI1443);
			ZR1194 (ZI1443, &ZI1265);
			ZR1266 (&ZI1265, &ZI1289);
			ZR1291 (&ZI1289, &ZIa);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: reach_check */
			{
#line 1121 "syntax.act"

    (ZIr) = unreached_code ;
    if ( (ZIr) ) {
	if ( !unreached_last ) {
	    report ( crt_loc, ERR_stmt_stmt_unreach () ) ;
	    unreached_last = 1 ;
	}
    } else {
	unreached_last = 0 ;
    }
#line 6219 "syntax4.c"
			}
			/* END OF ACTION: reach_check */
			/* BEGINNING OF ACTION: stmt_exp */
			{
#line 950 "syntax.act"

    (ZIe) = make_exp_stmt ( (ZIa) ) ;
#line 6227 "syntax4.c"
			}
			/* END OF ACTION: stmt_exp */
			/* BEGINNING OF ACTION: stmt_label_clear */
			{
#line 1018 "syntax.act"

    unreached_fall = 1 ;
#line 6235 "syntax4.c"
			}
			/* END OF ACTION: stmt_label_clear */
			switch (CURRENT_TERMINAL) {
			case 77:
				break;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
		}
		break;
	case 97: case 102: case 106: case 110:
	case 111: case 114: case 115: case 122:
	case 123: case 127: case 156: case 185:
	case 286: case 299:
		{
			BASE_TYPE ZIbt;
			TYPE ZI1267;
			CV_SPEC ZIcv;
			TYPE ZIt;
			SID_LIST_EXP ZIp;
			EXP ZI1282;
			EXP ZI1454;
			EXP ZI1453;
			EXP ZI1452;
			EXP ZI1451;
			EXP ZI1450;
			EXP ZI1449;
			EXP ZI1448;
			EXP ZI1447;
			EXP ZI1446;
			EXP ZI1445;
			EXP ZI1444;
			EXP ZI1443;
			EXP ZI1265;
			EXP ZI1289;
			EXP ZIa;
			int ZIr;

			ZRbase_Htype_Hspecifier (&ZIbt);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: type_pre */
			{
#line 1280 "syntax.act"

    (ZI1267) = NULL_type ;
    have_type_specifier = 1 ;
#line 6286 "syntax4.c"
			}
			/* END OF ACTION: type_pre */
			/* BEGINNING OF ACTION: cv_none */
			{
#line 1220 "syntax.act"
 (ZIcv) = cv_none ; 
#line 6293 "syntax4.c"
			}
			/* END OF ACTION: cv_none */
			/* BEGINNING OF ACTION: type_complete */
			{
#line 1321 "syntax.act"

    (ZIt) = complete_pre_type ( (ZIbt), (ZI1267), (ZIcv), 1 ) ;
    have_type_specifier = 0 ;
#line 6302 "syntax4.c"
			}
			/* END OF ACTION: type_complete */
			switch (CURRENT_TERMINAL) {
			case 65:
				break;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
			ZRexpression_Hlist_Hopt (&ZIp);
			switch (CURRENT_TERMINAL) {
			case 39:
				break;
			case 355:
				RESTORE_LEXER;
				goto ZL1;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: exp_func_cast */
			{
#line 680 "syntax.act"

    (ZI1282) = make_func_cast_exp ( (ZIt), (ZIp) ) ;
#line 6328 "syntax4.c"
			}
			/* END OF ACTION: exp_func_cast */
			ZR1242 (ZI1282, &ZI1454);
			ZR1238 (ZI1454, &ZI1453);
			ZR1234 (ZI1453, &ZI1452);
			ZR1230 (ZI1452, &ZI1451);
			ZR1226 (ZI1451, &ZI1450);
			ZR1222 (ZI1450, &ZI1449);
			ZR1218 (ZI1449, &ZI1448);
			ZR1214 (ZI1448, &ZI1447);
			ZR1210 (ZI1447, &ZI1446);
			ZR1206 (ZI1446, &ZI1445);
			ZR1202 (ZI1445, &ZI1444);
			ZR1198 (ZI1444, &ZI1443);
			ZR1194 (ZI1443, &ZI1265);
			ZR1266 (&ZI1265, &ZI1289);
			ZR1291 (&ZI1289, &ZIa);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: reach_check */
			{
#line 1121 "syntax.act"

    (ZIr) = unreached_code ;
    if ( (ZIr) ) {
	if ( !unreached_last ) {
	    report ( crt_loc, ERR_stmt_stmt_unreach () ) ;
	    unreached_last = 1 ;
	}
    } else {
	unreached_last = 0 ;
    }
#line 6363 "syntax4.c"
			}
			/* END OF ACTION: reach_check */
			/* BEGINNING OF ACTION: stmt_exp */
			{
#line 950 "syntax.act"

    (ZIe) = make_exp_stmt ( (ZIa) ) ;
#line 6371 "syntax4.c"
			}
			/* END OF ACTION: stmt_exp */
			/* BEGINNING OF ACTION: stmt_label_clear */
			{
#line 1018 "syntax.act"

    unreached_fall = 1 ;
#line 6379 "syntax4.c"
			}
			/* END OF ACTION: stmt_label_clear */
			switch (CURRENT_TERMINAL) {
			case 77:
				break;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
		}
		break;
	case 64:
		{
			ZRcompound_Hstatement (&ZIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 289: case 323:
		{
			ZRcontrol_Hstatement (&ZIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 96: case 100: case 223:
		{
			ZRfall_Hcheck ();
			ZR1442 (&ZIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 298: case 324:
		{
			EXP ZI1436;
			EXP ZIa;
			int ZIr;

			ZRflow_Hexpression (&ZI1436);
			ZR1438 (&ZI1436, &ZIa);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: reach_check */
			{
#line 1121 "syntax.act"

    (ZIr) = unreached_code ;
    if ( (ZIr) ) {
	if ( !unreached_last ) {
	    report ( crt_loc, ERR_stmt_stmt_unreach () ) ;
	    unreached_last = 1 ;
	}
    } else {
	unreached_last = 0 ;
    }
#line 6444 "syntax4.c"
			}
			/* END OF ACTION: reach_check */
			/* BEGINNING OF ACTION: stmt_exp */
			{
#line 950 "syntax.act"

    (ZIe) = make_exp_stmt ( (ZIa) ) ;
#line 6452 "syntax4.c"
			}
			/* END OF ACTION: stmt_exp */
			/* BEGINNING OF ACTION: stmt_label_clear */
			{
#line 1018 "syntax.act"

    unreached_fall = 1 ;
#line 6460 "syntax4.c"
			}
			/* END OF ACTION: stmt_label_clear */
			switch (CURRENT_TERMINAL) {
			case 77:
				break;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
		}
		break;
	case 101: case 107: case 125:
		{
			ZRiteration_Hstatement (&ZIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 95: case 99: case 108: case 113:
		{
			ZRjump_Hstatement (&ZIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 17: case 18: case 19: case 20:
	case 21: case 22: case 135: case 150:
		{
			EXP ZI1277;
			EXP ZI1454;
			EXP ZI1453;
			EXP ZI1452;
			EXP ZI1451;
			EXP ZI1450;
			EXP ZI1449;
			EXP ZI1448;
			EXP ZI1447;
			EXP ZI1446;
			EXP ZI1445;
			EXP ZI1444;
			EXP ZI1443;
			EXP ZI1265;
			EXP ZI1289;
			EXP ZIa;
			int ZIr;

			ZRliteral (&ZI1277);
			ZR1242 (ZI1277, &ZI1454);
			ZR1238 (ZI1454, &ZI1453);
			ZR1234 (ZI1453, &ZI1452);
			ZR1230 (ZI1452, &ZI1451);
			ZR1226 (ZI1451, &ZI1450);
			ZR1222 (ZI1450, &ZI1449);
			ZR1218 (ZI1449, &ZI1448);
			ZR1214 (ZI1448, &ZI1447);
			ZR1210 (ZI1447, &ZI1446);
			ZR1206 (ZI1446, &ZI1445);
			ZR1202 (ZI1445, &ZI1444);
			ZR1198 (ZI1444, &ZI1443);
			ZR1194 (ZI1443, &ZI1265);
			ZR1266 (&ZI1265, &ZI1289);
			ZR1291 (&ZI1289, &ZIa);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: reach_check */
			{
#line 1121 "syntax.act"

    (ZIr) = unreached_code ;
    if ( (ZIr) ) {
	if ( !unreached_last ) {
	    report ( crt_loc, ERR_stmt_stmt_unreach () ) ;
	    unreached_last = 1 ;
	}
    } else {
	unreached_last = 0 ;
    }
#line 6544 "syntax4.c"
			}
			/* END OF ACTION: reach_check */
			/* BEGINNING OF ACTION: stmt_exp */
			{
#line 950 "syntax.act"

    (ZIe) = make_exp_stmt ( (ZIa) ) ;
#line 6552 "syntax4.c"
			}
			/* END OF ACTION: stmt_exp */
			/* BEGINNING OF ACTION: stmt_label_clear */
			{
#line 1018 "syntax.act"

    unreached_fall = 1 ;
#line 6560 "syntax4.c"
			}
			/* END OF ACTION: stmt_label_clear */
			switch (CURRENT_TERMINAL) {
			case 77:
				break;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
		}
		break;
	case 62:
		{
			EXP ZI1461;
			EXP ZI1454;
			EXP ZI1453;
			EXP ZI1452;
			EXP ZI1451;
			EXP ZI1450;
			EXP ZI1449;
			EXP ZI1448;
			EXP ZI1447;
			EXP ZI1446;
			EXP ZI1445;
			EXP ZI1444;
			EXP ZI1443;
			EXP ZI1265;
			EXP ZI1289;
			EXP ZIa;
			int ZIr;

			/* BEGINNING OF INLINE: not */
			{
				{
					switch (CURRENT_TERMINAL) {
					case 62:
						break;
					default:
						goto ZL1;
					}
					ADVANCE_LEXER;
				}
			}
			/* END OF INLINE: not */
			ZRcast_Hexpression (&ZI1461);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: exp_not */
			{
#line 756 "syntax.act"

    (ZI1454) = make_not_exp ( (ZI1461) ) ;
#line 6615 "syntax4.c"
			}
			/* END OF ACTION: exp_not */
			ZR1238 (ZI1454, &ZI1453);
			ZR1234 (ZI1453, &ZI1452);
			ZR1230 (ZI1452, &ZI1451);
			ZR1226 (ZI1451, &ZI1450);
			ZR1222 (ZI1450, &ZI1449);
			ZR1218 (ZI1449, &ZI1448);
			ZR1214 (ZI1448, &ZI1447);
			ZR1210 (ZI1447, &ZI1446);
			ZR1206 (ZI1446, &ZI1445);
			ZR1202 (ZI1445, &ZI1444);
			ZR1198 (ZI1444, &ZI1443);
			ZR1194 (ZI1443, &ZI1265);
			ZR1266 (&ZI1265, &ZI1289);
			ZR1291 (&ZI1289, &ZIa);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: reach_check */
			{
#line 1121 "syntax.act"

    (ZIr) = unreached_code ;
    if ( (ZIr) ) {
	if ( !unreached_last ) {
	    report ( crt_loc, ERR_stmt_stmt_unreach () ) ;
	    unreached_last = 1 ;
	}
    } else {
	unreached_last = 0 ;
    }
#line 6649 "syntax4.c"
			}
			/* END OF ACTION: reach_check */
			/* BEGINNING OF ACTION: stmt_exp */
			{
#line 950 "syntax.act"

    (ZIe) = make_exp_stmt ( (ZIa) ) ;
#line 6657 "syntax4.c"
			}
			/* END OF ACTION: stmt_exp */
			/* BEGINNING OF ACTION: stmt_label_clear */
			{
#line 1018 "syntax.act"

    unreached_fall = 1 ;
#line 6665 "syntax4.c"
			}
			/* END OF ACTION: stmt_label_clear */
			switch (CURRENT_TERMINAL) {
			case 77:
				break;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
		}
		break;
	case 141:
		{
			IDENTIFIER ZIuid;
			IDENTIFIER ZIid;
			EXP ZI1285;
			EXP ZI1454;
			EXP ZI1453;
			EXP ZI1452;
			EXP ZI1451;
			EXP ZI1450;
			EXP ZI1449;
			EXP ZI1448;
			EXP ZI1447;
			EXP ZI1446;
			EXP ZI1445;
			EXP ZI1444;
			EXP ZI1443;
			EXP ZI1265;
			EXP ZI1289;
			EXP ZIa;
			int ZIr;

			parse_operator (&ZIuid);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: namespace_complex */
			{
#line 513 "syntax.act"

    (ZIid) = check_id ( NULL_nspace, (ZIuid), 0 ) ;
    crt_id_qualifier = qual_none ;
    last_namespace = crt_namespace ;
#line 6711 "syntax4.c"
			}
			/* END OF ACTION: namespace_complex */
			/* BEGINNING OF ACTION: exp_identifier */
			{
#line 684 "syntax.act"

    (ZI1285) = make_id_exp ( (ZIid) ) ;
#line 6719 "syntax4.c"
			}
			/* END OF ACTION: exp_identifier */
			ZR1242 (ZI1285, &ZI1454);
			ZR1238 (ZI1454, &ZI1453);
			ZR1234 (ZI1453, &ZI1452);
			ZR1230 (ZI1452, &ZI1451);
			ZR1226 (ZI1451, &ZI1450);
			ZR1222 (ZI1450, &ZI1449);
			ZR1218 (ZI1449, &ZI1448);
			ZR1214 (ZI1448, &ZI1447);
			ZR1210 (ZI1447, &ZI1446);
			ZR1206 (ZI1446, &ZI1445);
			ZR1202 (ZI1445, &ZI1444);
			ZR1198 (ZI1444, &ZI1443);
			ZR1194 (ZI1443, &ZI1265);
			ZR1266 (&ZI1265, &ZI1289);
			ZR1291 (&ZI1289, &ZIa);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: reach_check */
			{
#line 1121 "syntax.act"

    (ZIr) = unreached_code ;
    if ( (ZIr) ) {
	if ( !unreached_last ) {
	    report ( crt_loc, ERR_stmt_stmt_unreach () ) ;
	    unreached_last = 1 ;
	}
    } else {
	unreached_last = 0 ;
    }
#line 6754 "syntax4.c"
			}
			/* END OF ACTION: reach_check */
			/* BEGINNING OF ACTION: stmt_exp */
			{
#line 950 "syntax.act"

    (ZIe) = make_exp_stmt ( (ZIa) ) ;
#line 6762 "syntax4.c"
			}
			/* END OF ACTION: stmt_exp */
			/* BEGINNING OF ACTION: stmt_label_clear */
			{
#line 1018 "syntax.act"

    unreached_fall = 1 ;
#line 6770 "syntax4.c"
			}
			/* END OF ACTION: stmt_label_clear */
			switch (CURRENT_TERMINAL) {
			case 77:
				break;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
		}
		break;
	case 26: case 109: case 119:
		{
			ZRselection_Hstatement (&ZIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 149:
		{
			EXP ZI1289;
			EXP ZIa;
			int ZIr;

			ZRthrow_Hexpression (&ZI1289);
			ZR1291 (&ZI1289, &ZIa);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: reach_check */
			{
#line 1121 "syntax.act"

    (ZIr) = unreached_code ;
    if ( (ZIr) ) {
	if ( !unreached_last ) {
	    report ( crt_loc, ERR_stmt_stmt_unreach () ) ;
	    unreached_last = 1 ;
	}
    } else {
	unreached_last = 0 ;
    }
#line 6816 "syntax4.c"
			}
			/* END OF ACTION: reach_check */
			/* BEGINNING OF ACTION: stmt_exp */
			{
#line 950 "syntax.act"

    (ZIe) = make_exp_stmt ( (ZIa) ) ;
#line 6824 "syntax4.c"
			}
			/* END OF ACTION: stmt_exp */
			/* BEGINNING OF ACTION: stmt_label_clear */
			{
#line 1018 "syntax.act"

    unreached_fall = 1 ;
#line 6832 "syntax4.c"
			}
			/* END OF ACTION: stmt_label_clear */
			switch (CURRENT_TERMINAL) {
			case 77:
				break;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
		}
		break;
	case 151:
		{
			ZRtry_Hblock (&ZIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 131: case 140:
		{
			int ZIb;
			EXP ZI1454;
			EXP ZI1453;
			EXP ZI1452;
			EXP ZI1451;
			EXP ZI1450;
			EXP ZI1449;
			EXP ZI1448;
			EXP ZI1447;
			EXP ZI1446;
			EXP ZI1445;
			EXP ZI1444;
			EXP ZI1443;
			EXP ZI1265;
			EXP ZI1289;
			EXP ZIa;
			int ZIr;

			/* BEGINNING OF ACTION: bool_false */
			{
#line 2049 "syntax.act"
 (ZIb) = 0 ; 
#line 6877 "syntax4.c"
			}
			/* END OF ACTION: bool_false */
			ZR1432 (&ZIb, &ZI1454);
			ZR1238 (ZI1454, &ZI1453);
			ZR1234 (ZI1453, &ZI1452);
			ZR1230 (ZI1452, &ZI1451);
			ZR1226 (ZI1451, &ZI1450);
			ZR1222 (ZI1450, &ZI1449);
			ZR1218 (ZI1449, &ZI1448);
			ZR1214 (ZI1448, &ZI1447);
			ZR1210 (ZI1447, &ZI1446);
			ZR1206 (ZI1446, &ZI1445);
			ZR1202 (ZI1445, &ZI1444);
			ZR1198 (ZI1444, &ZI1443);
			ZR1194 (ZI1443, &ZI1265);
			ZR1266 (&ZI1265, &ZI1289);
			ZR1291 (&ZI1289, &ZIa);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: reach_check */
			{
#line 1121 "syntax.act"

    (ZIr) = unreached_code ;
    if ( (ZIr) ) {
	if ( !unreached_last ) {
	    report ( crt_loc, ERR_stmt_stmt_unreach () ) ;
	    unreached_last = 1 ;
	}
    } else {
	unreached_last = 0 ;
    }
#line 6912 "syntax4.c"
			}
			/* END OF ACTION: reach_check */
			/* BEGINNING OF ACTION: stmt_exp */
			{
#line 950 "syntax.act"

    (ZIe) = make_exp_stmt ( (ZIa) ) ;
#line 6920 "syntax4.c"
			}
			/* END OF ACTION: stmt_exp */
			/* BEGINNING OF ACTION: stmt_label_clear */
			{
#line 1018 "syntax.act"

    unreached_fall = 1 ;
#line 6928 "syntax4.c"
			}
			/* END OF ACTION: stmt_label_clear */
			switch (CURRENT_TERMINAL) {
			case 77:
				break;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
		}
		break;
	case 43: case 59: case 69: case 85:
		{
			int ZIop;
			EXP ZI1462;
			EXP ZI1454;
			EXP ZI1453;
			EXP ZI1452;
			EXP ZI1451;
			EXP ZI1450;
			EXP ZI1449;
			EXP ZI1448;
			EXP ZI1447;
			EXP ZI1446;
			EXP ZI1445;
			EXP ZI1444;
			EXP ZI1443;
			EXP ZI1265;
			EXP ZI1289;
			EXP ZIa;
			int ZIr;

			/* BEGINNING OF ACTION: lex_crt */
			{
#line 389 "syntax.act"
 (ZIop) = crt_lex_token ; 
#line 6965 "syntax4.c"
			}
			/* END OF ACTION: lex_crt */
			ZRunary_Hoperator ();
			ZRcast_Hexpression (&ZI1462);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: exp_unary */
			{
#line 855 "syntax.act"

    (ZI1454) = make_uminus_exp ( (ZIop), (ZI1462) ) ;
#line 6979 "syntax4.c"
			}
			/* END OF ACTION: exp_unary */
			ZR1238 (ZI1454, &ZI1453);
			ZR1234 (ZI1453, &ZI1452);
			ZR1230 (ZI1452, &ZI1451);
			ZR1226 (ZI1451, &ZI1450);
			ZR1222 (ZI1450, &ZI1449);
			ZR1218 (ZI1449, &ZI1448);
			ZR1214 (ZI1448, &ZI1447);
			ZR1210 (ZI1447, &ZI1446);
			ZR1206 (ZI1446, &ZI1445);
			ZR1202 (ZI1445, &ZI1444);
			ZR1198 (ZI1444, &ZI1443);
			ZR1194 (ZI1443, &ZI1265);
			ZR1266 (&ZI1265, &ZI1289);
			ZR1291 (&ZI1289, &ZIa);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: reach_check */
			{
#line 1121 "syntax.act"

    (ZIr) = unreached_code ;
    if ( (ZIr) ) {
	if ( !unreached_last ) {
	    report ( crt_loc, ERR_stmt_stmt_unreach () ) ;
	    unreached_last = 1 ;
	}
    } else {
	unreached_last = 0 ;
    }
#line 7013 "syntax4.c"
			}
			/* END OF ACTION: reach_check */
			/* BEGINNING OF ACTION: stmt_exp */
			{
#line 950 "syntax.act"

    (ZIe) = make_exp_stmt ( (ZIa) ) ;
#line 7021 "syntax4.c"
			}
			/* END OF ACTION: stmt_exp */
			/* BEGINNING OF ACTION: stmt_label_clear */
			{
#line 1018 "syntax.act"

    unreached_fall = 1 ;
#line 7029 "syntax4.c"
			}
			/* END OF ACTION: stmt_label_clear */
			switch (CURRENT_TERMINAL) {
			case 77:
				break;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
		}
		break;
	default:
		goto ZL1;
	}
	goto ZL0;
ZL1:;
	{
		/* BEGINNING OF ACTION: error_syntax */
		{
#line 1980 "syntax.act"

    /* Syntax errors */
    ERROR err = ERR_lex_parse ( crt_token ) ;
    report ( crt_loc, err ) ;
    have_syntax_error = 1 ;
#line 7055 "syntax4.c"
		}
		/* END OF ACTION: error_syntax */
		/* BEGINNING OF ACTION: exp_none */
		{
#line 579 "syntax.act"

    (ZIe) = NULL_exp ;
#line 7063 "syntax4.c"
		}
		/* END OF ACTION: exp_none */
	}
ZL0:;
	*ZOe = ZIe;
}

/* END OF FILE */
