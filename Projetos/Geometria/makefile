CC = g++
CFLAGS = -std=c++20 -Wall -g
TARGET = programa

BUILD_OBJ = ./build/obj
BUILD_APP = ./build/app
INCLUDE = ./include
SRC = ./src

${BUILD_APP}/${TARGET}: ${BUILD_OBJ}/programa.o ${BUILD_OBJ}/ponto.o
	${CC} ${CFLAGS} ${BUILD_OBJ}/*.o -o ${BUILD_APP}/${TARGET}

${BUILD_OBJ}/programa.o: ${INCLUDE}/ponto.hpp ${SRC}/programa.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/programa.cpp -o ${BUILD_OBJ}/programa.o

${BUILD_OBJ}/ponto.o: ${INCLUDE}/ponto.hpp ${SRC}/ponto.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/ponto.cpp -o ${BUILD_OBJ}/ponto.o