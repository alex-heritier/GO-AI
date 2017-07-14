MODULES = GoGameState Coordinate Utility GoView GoBoardView GoDataView
HDRSRC  = ${MODULES:=.h}
CPPSRC  = ${MODULES:=.cpp} TestGoState.cpp
OBJECTS = ${CPPSRC:.cpp=.o}
EXECBIN = go-ai
SFMLO 	= -F /Library/Frameworks -framework OpenGL -framework sfml -framework sfml-system -framework sfml-window -framework sfml-graphics
SFMLC 	= -I /usr/local/include/
CPP = g++ -g -O0 -Wall -Wextra -std=gnu++14

all: ${EXECBIN}

${EXECBIN} : ${OBJECTS}
	${CPP} -o ${EXECBIN} ${OBJECTS} ${SFMLO}
	@rm *.o

${OBJECTS} : ${CPPSRC}
	${CPP} -c ${CPPSRC} ${SFMLC}
