# TenDRA make build infrastructure
#
# $Id$

.if !defined(_TENDRA_WORK_SID_MK_)
_TENDRA_WORK_SID_MK_=1

.include <tendra.base.mk>
.include <tendra.functions.mk>

.if !defined(SYNTAX)
.BEGIN:
	@${ECHO} '$${SYNTAX} must be set'
	@${EXIT} 1;
.endif


ACTIONS?=	${SYNTAX:S/.sid$/.act/}

.if defined(SIDOPTS)
. if "${SIDOPTS:M*split*:N*nosplit*}" != ""
SIDSPLIT?=	@
. endif
.endif


# TODO: really sid ought to delete its own output on error.
.for src in ${SYNTAX}
${src:R}${SIDSPLIT}.c ${src:R}.h: ${src} ${ACTIONS:M${src:R}.act}
	@${CONDCREATE} "${OBJ_SDIR}"
	@${ECHO} "==> Translating ${WRKDIR}/${src}"
	${SID} ${SIDOPTS} ${.ALLSRC} ${src:R}${SIDSPLIT}.c ${src:R}.h \
		|| ( ${REMOVE} ${src:R}${SIDSPLIT:S/@/*/}.c ${src:R}.h; ${EXIT} 1 )
.endfor



#
# User-facing targets
#

.for src in ${SYNTAX}
regen:: ${src:R}${SIDSPLIT}.c ${src:R}.h
.endfor


regen-clean::
.for src in ${SYNTAX}
	${REMOVE} ${src:R}${SIDSPLIT:S/@/*/}.c ${src:R}.h
.endfor


install::



.endif	# !defined(_TENDRA_WORK_TPL_MK_)