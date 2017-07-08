MODULES = GoGameState Coordinate
HDRSRC  = ${MODULES:=.h}
CPPSRC  = ${MODULES:=.cpp} TestGoState.cpp
OBJECTS = ${CPPSRC:.cpp=.o}
EXECBIN = test

CPP = g++ -g -O0 -Wall -Wextra -std=gnu++14

all: ${EXECBIN}

${EXECBIN} : ${OBJECTS}
	${CPP} -o ${EXECBIN} ${OBJECTS}

${OBJECTS} : ${CPPSRC}
	${CPP} -c ${CPPSRC}
