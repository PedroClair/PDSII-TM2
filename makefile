CC = g++
CFLAGS = -std=c++20 -Wall -g #Compilador, avisos e depuração respectivamente
TARGET = program

BUILD_DIR = ./build
INCLUDE_DIR = ./include
SRC_DIR = ./src

${BUILD_DIR}/${TARGET}: ${BUILD_DIR}/aluno.o ${BUILD_DIR}/compra.o ${BUILD_DIR}/funcionario.o ${BUILD_DIR}/intro.o ${BUILD_DIR}/memory.o  ${BUILD_DIR}/ponteiro.o ${BUILD_DIR}/ponto3d.o ${BUILD_DIR}/main.o
	${CC} ${CFLAGS} -o ${BUILD_DIR}/${TARGET} ${BUILD_DIR}/*.o

${BUILD_DIR}/aluno.o:  ${INCLUDE_DIR}/aluno.hpp ${SRC_DIR}/aluno.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/aluno.cpp -o  ${BUILD_DIR}/aluno.o

${BUILD_DIR}/compra.o:  ${INCLUDE_DIR}/compra.hpp ${SRC_DIR}/compra.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/compra.cpp -o  ${BUILD_DIR}/compra.o

${BUILD_DIR}/funcionario.o:  ${INCLUDE_DIR}/funcionario.hpp ${SRC_DIR}/funcionario.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/funcionario.cpp -o  ${BUILD_DIR}/funcionario.o

${BUILD_DIR}/intro.o:  ${INCLUDE_DIR}/intro.hpp ${SRC_DIR}/intro.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/intro.cpp -o  ${BUILD_DIR}/intro.o

${BUILD_DIR}/memory.o:  ${INCLUDE_DIR}/memory.hpp ${SRC_DIR}/memory.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/memory.cpp -o  ${BUILD_DIR}/memory.o

${BUILD_DIR}/ponteiro.o:  ${INCLUDE_DIR}/ponteiro.hpp ${SRC_DIR}/ponteiro.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/ponteiro.cpp -o  ${BUILD_DIR}/ponteiro.o

${BUILD_DIR}/ponto3d.o:  ${INCLUDE_DIR}/ponto3d.hpp ${SRC_DIR}/ponto3d.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/ponto3d.cpp -o  ${BUILD_DIR}/ponto3d.o


${BUILD_DIR}/main.o: main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c main.cpp -o  ${BUILD_DIR}/main.o

