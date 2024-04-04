CC = g++
CFLAGS = -std=c++11 -Wall -g
TARGET = programa

BUILD = ./build
SRC = ./src 
INCLUDE = ./include

${BUILD}/${TARGET}: ${BUILD}/ola.o ${BUILD}/aluno.o ${BUILD}/circunferencia.o ${BUILD}/main.o
	${CC} ${CFLAGS} ${BUILD}/aluno.o ${BUILD}/circunferencia.o ${BUILD}/ola.o ${BUILD}/main.o -o ${BUILD}/program

${BUILD}/ola.o:
	${CC} ${CFLAGS} ${SRC}/ola.cpp -o ${BUILD}/ola.o

${BUILD}/aluno.o:
	${CC} ${CFLAGS} -c aluno.cpp -o ${BUILD}/aluno.o

${BUILD}/circunferencia.o:
	${CC} ${CFLAGS} -c circunferencia.cpp -o ${BUILD}/circunferencia.o

${BUILD}/main.o:
	${CC} ${CFLAGS} -c main.cpp -o ${BUILD}/main.o
