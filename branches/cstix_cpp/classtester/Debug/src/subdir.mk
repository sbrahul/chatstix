################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CStixCallbacks.cpp \
../src/CStixChatRoom.cpp \
../src/CStixCmdlineProgramExternalizer.cpp \
../src/CStixCommunications.cpp \
../src/CStixException.cpp \
../src/CStixGlobals.cpp \
../src/CStixMemorySubsystem.cpp \
../src/CStixMessage.cpp \
../src/CStixMessageParser.cpp \
../src/CStixMessageQ.cpp \
../src/CStixRoomManager.cpp \
../src/CStixSemaphore.cpp \
../src/CStixServer.cpp \
../src/CStixSocket.cpp \
../src/CStixSystem.cpp \
../src/CStixThread.cpp \
../src/CStixThreadFns.cpp \
../src/CStixUser.cpp \
../src/CStixUserManager.cpp \
../src/CStixUtil.cpp \
../src/CStixWindowsDebugHelper.cpp \
../src/main.cpp 

OBJS += \
./src/CStixCallbacks.o \
./src/CStixChatRoom.o \
./src/CStixCmdlineProgramExternalizer.o \
./src/CStixCommunications.o \
./src/CStixException.o \
./src/CStixGlobals.o \
./src/CStixMemorySubsystem.o \
./src/CStixMessage.o \
./src/CStixMessageParser.o \
./src/CStixMessageQ.o \
./src/CStixRoomManager.o \
./src/CStixSemaphore.o \
./src/CStixServer.o \
./src/CStixSocket.o \
./src/CStixSystem.o \
./src/CStixThread.o \
./src/CStixThreadFns.o \
./src/CStixUser.o \
./src/CStixUserManager.o \
./src/CStixUtil.o \
./src/CStixWindowsDebugHelper.o \
./src/main.o 

CPP_DEPS += \
./src/CStixCallbacks.d \
./src/CStixChatRoom.d \
./src/CStixCmdlineProgramExternalizer.d \
./src/CStixCommunications.d \
./src/CStixException.d \
./src/CStixGlobals.d \
./src/CStixMemorySubsystem.d \
./src/CStixMessage.d \
./src/CStixMessageParser.d \
./src/CStixMessageQ.d \
./src/CStixRoomManager.d \
./src/CStixSemaphore.d \
./src/CStixServer.d \
./src/CStixSocket.d \
./src/CStixSystem.d \
./src/CStixThread.d \
./src/CStixThreadFns.d \
./src/CStixUser.d \
./src/CStixUserManager.d \
./src/CStixUtil.d \
./src/CStixWindowsDebugHelper.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


