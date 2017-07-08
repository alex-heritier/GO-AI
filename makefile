MODULES = GoGameState
HDRSRC  = ${MODULES:=.h}
CPPSRC  = ${MODULES:=.c} test.cpp
OBJECTS = ${CPPSRC:.c=.o}
EXECBIN = test

CPP = g++ -g -O0 -Wall -Wextra -std=gnu++14

all: ${EXECBIN}

${EXECBIN} : ${OBJECTS}
	${CPP} -o ${EXECBIN} ${OBJECTS}

${OBJECTS} : ${CPPSRC}
	${CPP} -c $<
