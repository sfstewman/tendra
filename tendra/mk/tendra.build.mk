# TenDRA make build infrastructure
#
# $Id$

# STANDARD DIRECTORIES
#
# These directories are used to configure where the release is to be
# installed:
#
#       BASE_DIR        gives the directory in which the source has been
#                       installed (i.e. the directory containing this script).
#
#       PUBLIC_BIN      gives the directory in which the public executables
#                       (tcc, tchk and tspec) are to be installed.  If
#                       PUBLIC_BIN is left blank then the public executables
#                       will be installed in the private executables
#                       directory.
#
#       INSTALL_DIR     gives the directory in which the configuration files,
#                       include files, private executables, libraries etc.
#                       are to be installed.
#
#       COMMON_DIR      gives the sub-directory of INSTALL_DIR in which the
#                       target independent components are to be installed.
#
#       MACH_DIR        gives the sub-directory of INSTALL_DIR in which the
#                       target dependent components are to be installed.
#
#       MAN_DIR         gives the directory in which the manual pages are
#                       to be installed.
#
#       OBJ_DIR         gives the working directory in which binary object
#                       files etc. created during the build process will
#                       be stored.
#
#	OBJ_SDIR	gives the full path to the working directory and the
#			sub-directory of the current source directory.
#
#       TMP_DIR         gives a temporary directory, used both by this
#                       script and by tcc (so make sure that there is
#                       plenty of free space).

BASE_DIR = ${.CURDIR:C/\/(mk|src).*//}
PUBLIC_BIN = /usr/local/bin
INSTALL_DIR = /usr/local/lib/TenDRA
COMMON_DIR = ${INSTALL_DIR}/lib
MACH_DIR = ${INSTALL_DIR}/machines
MAN_DIR = /usr/local/man
OBJ_DIR = ${BASE_DIR}/obj
OBJ_SDIR = ${OBJ_DIR}${.CURDIR:C/${BASE_DIR}//}
TMP_DIR = /var/tmp

PREFIX ?= /usr/local
BINDIR ?= /bin

# Binary paths

SHELL = /bin/sh

ENV ?=		/usr/bin/env

COPY ?=		${ENV} cp
ECHO ?=		${ENV} echo
ECHODIR ?=	${ENV} echo
INSTALL ?=	${ENV} install
MKDIR ?=	${ENV} mkdir
MOVE ?=		${ENV} mv
REMOVE ?=	${ENV} rm -f

# Build infrastructure framework

.if !target(.MAIN)
.MAIN: all
.endif

.SUFFIXES: .o .c .sid

.c.o:
	@${ECHO} Compiling ${.IMPSRC}...
	${CC} ${CCOPTS} -c ${.IMPSRC} -o ${OBJ_SDIR}/${.TARGET}

.o:
	@${ECHO} Linking ${.IMPSRC}...
	${LD} ${LDOPTS} -o ${OBJ_SDIR}/${PROG} ${OBJS} ${LIBS}

.sid.c:
	@${ECHO} Transforming ${.IMPSRC} and ${.IMPSRC:S/.sid/.act/}...
	${SID} ${SIDOPTS} ${.IMPSRC} ${.IMPSRC:S/.sid/.act/} ${.TARGET}\
		${.TARGET:S/.c/.h/}

OBJS=  ${SRCS:S/.c/.o/}

all:
.if defined(PROG)
	@${MAKE} _OBJDIR
	@env MAKEOBJDIR=${OBJ_SDIR} ${MAKE} ${PROG}
.endif

${PROG}: ${OBJS}
	@${ECHO} Linking ${PROG}...
	${LD} ${LDOPTS} -o ${PROG} ${OBJS} ${LIBS}

clean:
.if defined(PROG)
	cd ${OBJ_SDIR}; \
		${REMOVE} ${PROG} ${PROG}.core core ${OBJS}
.endif
.if defined(CLEAN_EXTRA)
	${REMOVE} ${CLEAN_EXTRA}
.endif

install:
.if defined(PROG)
	cd ${OBJ_SDIR};
.if !exists(${PREFIX}${BINDIR})
	${MKDIR} -p ${PREFIX}${BINDIR}
.endif
		${INSTALL} -m 755 ${OBJ_SDIR}/${PROG} ${PREFIX}${BINDIR}/${PROG}
.endif

_OBJDIR:
.if !exists(${OBJ_SDIR})
	@mkdir -p ${OBJ_SDIR}
	@${ECHODIR} ${OBJ_SDIR} created for ${.CURDIR}
.endif

_SUBDIR: .USE
.if defined(SUBDIR) && !empty(SUBDIR)
.for entry in ${SUBDIR}
		@${ECHODIR} "Entering ${DIRPREFIX}${entry}"
		@${ECHODIR} "..Executing within ${entry}: ${MAKE} ${.TARGET}"
		@cd ${.CURDIR}/${entry}; \
			${MAKE} ${.TARGET} DIRPREFIX=${DIRPREFIX}${entry}/
.endfor
.endif

.for target in all clean install
${target}: _SUBDIR
.endfor
