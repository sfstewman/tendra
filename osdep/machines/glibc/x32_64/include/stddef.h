/* $Id$ */

#ifndef __HACKED_STDDEF_H
#define __HACKED_STDDEF_H

/*
 * glibc does not provide this header; it is expected to be provided by gcc.
 * The definitions here must be compatible.
 */

#if defined(_GLIBC2_19)

#define NULL 0

typedef unsigned int size_t;

typedef int ptrdiff_t;

typedef long int wchar_t;

#pragma TenDRA begin
#pragma TenDRA keyword __literal for keyword literal
#pragma TenDRA conversion analysis (pointer-int) off
#define offsetof(__s, __m) (__literal (size_t) &(((__s *) 0)->__m))
#pragma TenDRA end

#endif

#endif

