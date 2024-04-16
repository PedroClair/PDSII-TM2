CC = g++
CFLAGS = -std=c++11 -Wall -g
TARGET = program

BUILD = ./build
SRC = ./src
INCLUDE = ./include

${BUILD}/${TARGET}: ${BUILD}/BancoDeDados.o ${BUILD}/main.o
	${CC} ${CFLAGS} -l sqlite3 ${BUILD}/BancoDeDados.o ${BUILD}/main.o -o ${BUILD}/${TARGET}

${BUILD}/BancoDeDados.o: ${INCLUDE}/BancoDeDados.hpp ${SRC}/BancoDeDados.cpp
	${CC} ${CFLAGS} -l sqlite3 -I ${INCLUDE}/ -c ${SRC}/BancoDeDados.cpp -o ${BUILD}/BancoDeDados.o

${BUILD}/main.o: ${INCLUDE}/BancoDeDados.hpp main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c main.cpp -o ${BUILD}/main.o