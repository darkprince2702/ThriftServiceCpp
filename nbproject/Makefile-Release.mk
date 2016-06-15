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
	${OBJECTDIR}/HashMap.o \
	${OBJECTDIR}/HashMapModel.o \
	${OBJECTDIR}/LevelDB.o \
	${OBJECTDIR}/LevelDBModel.o \
	${OBJECTDIR}/Memcached.o \
	${OBJECTDIR}/MemcachedModel.o \
	${OBJECTDIR}/ProfileService.o \
	${OBJECTDIR}/ProfileServiceConstants.o \
	${OBJECTDIR}/ProfileServiceServer.o \
	${OBJECTDIR}/ProfileServiceTypes.o


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

${OBJECTDIR}/HashMap.o: HashMap.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HashMap.o HashMap.cpp

${OBJECTDIR}/HashMapModel.o: HashMapModel.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/HashMapModel.o HashMapModel.cpp

${OBJECTDIR}/LevelDB.o: LevelDB.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LevelDB.o LevelDB.cpp

${OBJECTDIR}/LevelDBModel.o: LevelDBModel.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LevelDBModel.o LevelDBModel.cpp

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

${OBJECTDIR}/ProfileServiceConstants.o: ProfileServiceConstants.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ProfileServiceConstants.o ProfileServiceConstants.cpp

${OBJECTDIR}/ProfileServiceServer.o: ProfileServiceServer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ProfileServiceServer.o ProfileServiceServer.cpp

${OBJECTDIR}/ProfileServiceTypes.o: ProfileServiceTypes.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ProfileServiceTypes.o ProfileServiceTypes.cpp

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
