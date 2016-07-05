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
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Buffer.o \
	${OBJECTDIR}/Cache.o \
	${OBJECTDIR}/Database.o \
	${OBJECTDIR}/DatabaseModel.o \
	${OBJECTDIR}/DatabaseService.o \
	${OBJECTDIR}/DumpFile.o \
	${OBJECTDIR}/File.o \
	${OBJECTDIR}/HashMap.o \
	${OBJECTDIR}/HashMapModel.o \
	${OBJECTDIR}/LogFile.o \
	${OBJECTDIR}/Memcached.o \
	${OBJECTDIR}/MemcachedModel.o \
	${OBJECTDIR}/ProfileService.o \
	${OBJECTDIR}/ProfileServiceServer.o \
	${OBJECTDIR}/SaveFile.o \
	${OBJECTDIR}/Timer.o \
	${OBJECTDIR}/databaseservice_constants.o \
	${OBJECTDIR}/databaseservice_types.o \
	${OBJECTDIR}/profileservice_constants.o \
	${OBJECTDIR}/profileservice_types.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/thriftservicecpp

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/thriftservicecpp: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/thriftservicecpp ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Buffer.o: Buffer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Buffer.o Buffer.cpp

${OBJECTDIR}/Cache.o: Cache.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Cache.o Cache.cpp

${OBJECTDIR}/Database.o: Database.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Database.o Database.cpp

${OBJECTDIR}/DatabaseModel.o: DatabaseModel.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DatabaseModel.o DatabaseModel.cpp

${OBJECTDIR}/DatabaseService.o: DatabaseService.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DatabaseService.o DatabaseService.cpp

${OBJECTDIR}/DumpFile.o: DumpFile.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DumpFile.o DumpFile.cpp

${OBJECTDIR}/File.o: File.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/File.o File.cpp

${OBJECTDIR}/HashMap.o: HashMap.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HashMap.o HashMap.cpp

${OBJECTDIR}/HashMapModel.o: HashMapModel.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HashMapModel.o HashMapModel.cpp

${OBJECTDIR}/LogFile.o: LogFile.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LogFile.o LogFile.cpp

${OBJECTDIR}/Memcached.o: Memcached.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Memcached.o Memcached.cpp

${OBJECTDIR}/MemcachedModel.o: MemcachedModel.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MemcachedModel.o MemcachedModel.cpp

${OBJECTDIR}/ProfileService.o: ProfileService.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ProfileService.o ProfileService.cpp

${OBJECTDIR}/ProfileServiceServer.o: ProfileServiceServer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ProfileServiceServer.o ProfileServiceServer.cpp

${OBJECTDIR}/SaveFile.o: SaveFile.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SaveFile.o SaveFile.cpp

${OBJECTDIR}/Timer.o: Timer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Timer.o Timer.cpp

${OBJECTDIR}/databaseservice_constants.o: databaseservice_constants.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/databaseservice_constants.o databaseservice_constants.cpp

${OBJECTDIR}/databaseservice_types.o: databaseservice_types.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/databaseservice_types.o databaseservice_types.cpp

${OBJECTDIR}/profileservice_constants.o: profileservice_constants.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/profileservice_constants.o profileservice_constants.cpp

${OBJECTDIR}/profileservice_types.o: profileservice_types.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/profileservice_types.o profileservice_types.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/thriftservicecpp

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
