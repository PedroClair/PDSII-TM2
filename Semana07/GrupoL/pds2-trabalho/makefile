CC = g++
CFLAGS = -std=c++11 -Wall -g
TARGET = ControleFinanceiro

BUILD = ./build
SRC = ./src
INCLUDE = ./include

${BUILD}/${TARGET}: ${BUILD}/saldo.o ${BUILD}/main.o
	${CC} ${CFLAGS} ${BUILD}/saldo.o ${BUILD}/main.o -o ${BUILD}/${TARGET}

${BUILD}/saldo.o: ${INCLUDE}/saldo.hpp ${SRC}/saldo.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/saldo.cpp -o ${BUILD}/saldo.o

${BUILD}/main.o: ${INCLUDE}/saldo.hpp ${SRC}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/main.cpp -o ${BUILD}/main.o
