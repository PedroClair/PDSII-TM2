CC = g++
CFLAGS = -std=c++11 -Wall -g
TARGET = programa

BUILD = ./build
SRC = ./src
INCLUDE = ./include

${BUILD}/${TARGET}: ${BUILD}/ola.o ${BUILD}/aluno.o ${BUILD}/circunferencia.o ${BUILD}/main.o
	${CC} ${CFLAGS} ${BUILD}/aluno.o ${BUILD}/circunferencia.o ${BUILD}/ola.o ${BUILD}/main.o -o ${BUILD}/${TARGET}

${BUILD}/ola.o: ${INCLUDE}/ola.hpp ${SRC}/ola.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/ola.cpp -o ${BUILD}/ola.o

${BUILD}/aluno.o: ${INCLUDE}/aluno.hpp ${SRC}/aluno.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/aluno.cpp -o ${BUILD}/aluno.o

${BUILD}/circunferencia.o: ${INCLUDE}/circunferencia.hpp ${SRC}/circunferencia.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/circunferencia.cpp -o ${BUILD}/circunferencia.o

${BUILD}/main.o: ${INCLUDE}/ola.hpp ${INCLUDE}/aluno.hpp ${INCLUDE}/circunferencia.hpp main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c main.cpp -o ${BUILD}/main.o
