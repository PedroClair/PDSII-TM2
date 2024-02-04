CC = g++
CFLAGS = -std=c++20 -Wall -g
TARGET = program

BUILD = ./build
BUILD_BIN = ${BUILD}/bin
BUILD_LIB = ${BUILD}/lib
INCLUDE = ./include
SRC = ./src

${TARGET}: main.o ola.o
	${CC} ${CFLAGS} ${BUILD_BIN}/main.o ${BUILD_BIN}/ola.o -o  ${BUILD}/${TARGET}

main.o: ${INCLUDE}/ola.hpp ${SRC}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/main.cpp -o ${BUILD_BIN}/main.o

ola.o: ${INCLUDE}/ola.hpp ${SRC}/ola.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/ola.cpp -o ${BUILD_BIN}/ola.o