CC = g++
CFLAGS = -std=c++11 -Wall -g
TARGET = program

BUILD = ./build

${TARGET}: 
	${CC} ${CFLAGS} ensaio.cpp -o ${BUILD}/${TARGET}
	${BUILD}/${TARGET}