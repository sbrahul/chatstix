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
CC=gcc.exe
CCC=g++.exe
CXX=g++.exe
FC=gfortran.exe
AS=as.exe

# Macros
CND_PLATFORM=Cygwin-Windows
CND_CONF=Debug
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/CStixCmdlineProgramExternalizer.o \
	${OBJECTDIR}/src/CStixSystem.o \
	${OBJECTDIR}/src/CStixSemaphore.o \
	${OBJECTDIR}/src/CStixSocket.o \
	${OBJECTDIR}/src/CStixMessageQ.o \
	${OBJECTDIR}/src/CStixThread.o \
	${OBJECTDIR}/src/CStixChatRoom.o \
	${OBJECTDIR}/src/main.o \
	${OBJECTDIR}/src/CStixThreadFns.o \
	${OBJECTDIR}/src/CStixRoomManager.o \
	${OBJECTDIR}/src/CStixUtil.o \
	${OBJECTDIR}/src/CStixAbstractProgramExternalizer.o \
	${OBJECTDIR}/src/CStixException.o \
	${OBJECTDIR}/src/CStixGlobals.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-Wall
CXXFLAGS=-Wall

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lpthread

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-Debug.mk dist/Debug/Cygwin-Windows/classtester.exe

dist/Debug/Cygwin-Windows/classtester.exe: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/Cygwin-Windows
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/classtester ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/src/CStixCmdlineProgramExternalizer.o: nbproject/Makefile-${CND_CONF}.mk src/CStixCmdlineProgramExternalizer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/CStixCmdlineProgramExternalizer.o src/CStixCmdlineProgramExternalizer.cpp

${OBJECTDIR}/src/CStixSystem.o: nbproject/Makefile-${CND_CONF}.mk src/CStixSystem.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/CStixSystem.o src/CStixSystem.cpp

${OBJECTDIR}/src/CStixSemaphore.o: nbproject/Makefile-${CND_CONF}.mk src/CStixSemaphore.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/CStixSemaphore.o src/CStixSemaphore.cpp

${OBJECTDIR}/src/CStixSocket.o: nbproject/Makefile-${CND_CONF}.mk src/CStixSocket.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/CStixSocket.o src/CStixSocket.cpp

${OBJECTDIR}/src/CStixMessageQ.o: nbproject/Makefile-${CND_CONF}.mk src/CStixMessageQ.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/CStixMessageQ.o src/CStixMessageQ.cpp

${OBJECTDIR}/src/CStixThread.o: nbproject/Makefile-${CND_CONF}.mk src/CStixThread.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/CStixThread.o src/CStixThread.cpp

${OBJECTDIR}/src/CStixChatRoom.o: nbproject/Makefile-${CND_CONF}.mk src/CStixChatRoom.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/CStixChatRoom.o src/CStixChatRoom.cpp

${OBJECTDIR}/src/main.o: nbproject/Makefile-${CND_CONF}.mk src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/main.o src/main.cpp

${OBJECTDIR}/src/CStixThreadFns.o: nbproject/Makefile-${CND_CONF}.mk src/CStixThreadFns.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/CStixThreadFns.o src/CStixThreadFns.cpp

${OBJECTDIR}/src/CStixRoomManager.o: nbproject/Makefile-${CND_CONF}.mk src/CStixRoomManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/CStixRoomManager.o src/CStixRoomManager.cpp

${OBJECTDIR}/src/CStixUtil.o: nbproject/Makefile-${CND_CONF}.mk src/CStixUtil.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/CStixUtil.o src/CStixUtil.cpp

${OBJECTDIR}/src/CStixAbstractProgramExternalizer.o: nbproject/Makefile-${CND_CONF}.mk src/CStixAbstractProgramExternalizer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/CStixAbstractProgramExternalizer.o src/CStixAbstractProgramExternalizer.cpp

${OBJECTDIR}/src/CStixException.o: nbproject/Makefile-${CND_CONF}.mk src/CStixException.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/CStixException.o src/CStixException.cpp

${OBJECTDIR}/src/CStixGlobals.o: nbproject/Makefile-${CND_CONF}.mk src/CStixGlobals.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/CStixGlobals.o src/CStixGlobals.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Debug
	${RM} dist/Debug/Cygwin-Windows/classtester.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
