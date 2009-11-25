#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Debug
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/chatstixmain.o \
	${OBJECTDIR}/src/globals.o \
	${OBJECTDIR}/src/otherfns.o \
	${OBJECTDIR}/src/sockutils.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lpthread

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-Debug.mk dist/Debug/GNU-Linux-x86/chatstixsrv

dist/Debug/GNU-Linux-x86/chatstixsrv: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/GNU-Linux-x86
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/chatstixsrv ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/src/chatstixmain.o: nbproject/Makefile-${CND_CONF}.mk src/chatstixmain.c 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.c) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/chatstixmain.o src/chatstixmain.c

${OBJECTDIR}/src/globals.o: nbproject/Makefile-${CND_CONF}.mk src/globals.c 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.c) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/globals.o src/globals.c

${OBJECTDIR}/src/otherfns.o: nbproject/Makefile-${CND_CONF}.mk src/otherfns.c 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.c) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/otherfns.o src/otherfns.c

${OBJECTDIR}/src/sockutils.o: nbproject/Makefile-${CND_CONF}.mk src/sockutils.c 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.c) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/sockutils.o src/sockutils.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf:
	${RM} -r build/Debug
	${RM} dist/Debug/GNU-Linux-x86/chatstixsrv

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
