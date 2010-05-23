/*
    		 Crown Copyright (c) 1997
    
    This TenDRA(r) Computer Program is subject to Copyright
    owned by the United Kingdom Secretary of State for Defence
    acting through the Defence Evaluation and Research Agency
    (DERA).  It is made available to Recipients with a
    royalty-free licence for its use, reproduction, transfer
    to other parties and amendment for any purpose not excluding
    product development provided that any such use et cetera
    shall be deemed to be acceptance of the following conditions:-
    
        (1) Its Recipients shall ensure that this Notice is
        reproduced upon any copies or amended versions of it;
    
        (2) Any amended version of it shall be clearly marked to
        show both the nature of and the organisation responsible
        for the relevant amendment or amendments;
    
        (3) Its onward transfer from a recipient to another
        party shall be deemed to be that party's acceptance of
        these conditions;
    
        (4) DERA gives no warranty or assurance as to its
        quality or suitability for any purpose and DERA accepts
        no liability whatsoever in relation to any use to which
        it may be put.
*/
/*
    REPLACEMENT FLOAT HEADER FOR sunos/sparc

    The system does not provide a float.h header, so this is provided in its
    place.
*/

#ifndef __float_h
#define __float_h

#define FLT_RADIX	2
#define FLT_MANT_DIG	24
#define FLT_DIG		6
#define FLT_ROUNDS	1
#define FLT_MIN_EXP	(-125)
#define FLT_MIN_10_EXP	(-37)
#define FLT_MAX_EXP	128
#define FLT_MAX_10_EXP	38

#ifdef __STDC__
#define FLT_EPSILON	1.19209290e-07F
#define FLT_MIN		1.17549435e-38F
#define FLT_MAX		3.40282347e+38F
#else
#define FLT_EPSILON	1.19209290e-07
#define FLT_MIN		1.17549435e-38
#define FLT_MAX		3.40282347e+38
#endif

#define DBL_MANT_DIG	53
#define DBL_DIG		15
#define DBL_EPSILON	2.2204460492503131e-16
#define DBL_MIN_EXP	(-1021)
#define DBL_MIN		2.2250738585072014e-308
#define DBL_MIN_10_EXP	(-307)
#define DBL_MAX_EXP	1024
#define DBL_MAX		1.7976931348623157e+308
#define DBL_MAX_10_EXP	308

#define LDBL_MANT_DIG	DBL_MANT_DIG
#define LDBL_DIG	DBL_DIG
#define LDBL_EPSILON	DBL_EPSILON
#define LDBL_MIN	DBL_MIN
#define LDBL_MIN_EXP	DBL_MIN_EXP
#define LDBL_MIN_10_EXP	DBL_MIN_10_EXP
#define LDBL_MAX	DBL_MAX
#define LDBL_MAX_EXP	DBL_MAX_EXP
#define LDBL_MAX_10_EXP	DBL_MAX_10_EXP

#endif
