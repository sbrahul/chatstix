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
CND_CONF=Release
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/main.o \
	${OBJECTDIR}/src/CStixThreadFns.o \
	${OBJECTDIR}/src/CStixUtil.o \
	${OBJECTDIR}/src/CStixSystem.o \
	${OBJECTDIR}/src/CStixSemaphore.o \
	${OBJECTDIR}/src/CStixSocket.o \
	${OBJECTDIR}/src/CStixGlobals.o \
	${OBJECTDIR}/src/CStixMessageQ.o \
	${OBJECTDIR}/src/CStixThread.o

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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-Release.mk dist/Release/GNU-Linux-x86/classtester

dist/Release/GNU-Linux-x86/classtester: ${OBJECTFILES}
	${MKDIR} -p dist/Release/GNU-Linux-x86
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/classtester ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/src/main.o: nbproject/Makefile-${CND_CONF}.mk src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/main.o src/main.cpp

${OBJECTDIR}/src/CStixThreadFns.o: nbproject/Makefile-${CND_CONF}.mk src/CStixThreadFns.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/CStixThreadFns.o src/CStixThreadFns.cpp

${OBJECTDIR}/src/CStixUtil.o: nbproject/Makefile-${CND_CONF}.mk src/CStixUtil.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/CStixUtil.o src/CStixUtil.cpp

${OBJECTDIR}/src/CStixSystem.o: nbproject/Makefile-${CND_CONF}.mk src/CStixSystem.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/CStixSystem.o src/CStixSystem.cpp

${OBJECTDIR}/src/CStixSemaphore.o: nbproject/Makefile-${CND_CONF}.mk src/CStixSemaphore.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/CStixSemaphore.o src/CStixSemaphore.cpp

${OBJECTDIR}/src/CStixSocket.o: nbproject/Makefile-${CND_CONF}.mk src/CStixSocket.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/CStixSocket.o src/CStixSocket.cpp

${OBJECTDIR}/src/CStixGlobals.o: nbproject/Makefile-${CND_CONF}.mk src/CStixGlobals.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/CStixGlobals.o src/CStixGlobals.cpp

${OBJECTDIR}/src/CStixMessageQ.o: nbproject/Makefile-${CND_CONF}.mk src/CStixMessageQ.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/CStixMessageQ.o src/CStixMessageQ.cpp

${OBJECTDIR}/src/CStixThread.o: nbproject/Makefile-${CND_CONF}.mk src/CStixThread.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/CStixThread.o src/CStixThread.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf:
	${RM} -r build/Release
	${RM} dist/Release/GNU-Linux-x86/classtester

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
