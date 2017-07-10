MODULES = GoGameState Coordinate
HDRSRC  = ${MODULES:=.h}
CPPSRC  = ${MODULES:=.cpp} TestGoState.cpp
OBJECTS = ${CPPSRC:.cpp=.o}
EXECBIN = test
SFMLO 	= -F /Library/Frameworks -framework OpenGL -framework SFML -framework SFML-window
SFMLC 	= -F /Library/Frameworks

CPP = g++ -g -O0 -Wall -Wextra -std=gnu++14

all: ${EXECBIN}

${EXECBIN} : ${OBJECTS}
	${CPP} -o ${EXECBIN} ${OBJECTS} ${SFMLO}
	@rm *.o

${OBJECTS} : ${CPPSRC}
	${CPP} -c ${CPPSRC} ${SFMLC}
