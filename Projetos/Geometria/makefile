CC = g++
CFLAGS = -std=c++20 -Wall -g
TARGET = programa

BUILD_OBJ = ./build/obj
BUILD_APP = ./build/app
INCLUDE = ./include
SRC = ./src

${TARGET}: main.o ponto.o
	${CC} ${CFLAGS} ${BUILD_OBJ}/*.o -o ${BUILD_APP}/${TARGET}

main.o: ${INCLUDE}/ponto.hpp ${SRC}/main.cpp
	${CC} ${CFLAGS} -c ${SRC}/main.cpp -o ${BUILD_OBJ}/main.o

ponto.o: ${INCLUDE}/ponto.hpp ${SRC}/ponto.cpp
	${CC} ${CFLAGS} -c ${SRC}/ponto.cpp -o ${BUILD_OBJ}/ponto.o