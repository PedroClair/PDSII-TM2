CC = g++
CFLAGS = -std=c++20 -Wall
TARGET = program

BUILD_DIR = ./build
INCLUDE_DIR = ./include
SRC_DIR = ./src

${BUILD_DIR}/${TARGET}: ${BUILD_DIR}/memory.o ${BUILD_DIR}/funcionario.o ${BUILD_DIR}/main.o
	${CC} ${CFLAGS} -o ${BUILD_DIR}/${TARGET} ${BUILD_DIR}/*.o

${BUILD_DIR}/memory.o:  ${INCLUDE_DIR}/memory.hpp ${SRC_DIR}/lista02/memory.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/lista02/memory.cpp -o  ${BUILD_DIR}/memory.o

${BUILD_DIR}/funcionario.o:  ${INCLUDE_DIR}/lista02/funcionario.hpp ${SRC_DIR}/lista02/funcionario.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/lista02/ -c ${SRC_DIR}/lista02/funcionario.cpp -o  ${BUILD_DIR}/funcionario.o

${BUILD_DIR}/main.o: ${INCLUDE_DIR}/lista02/memory.hpp ${INCLUDE_DIR}/lista02/funcionario.hpp ${SRC_DIR}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/lista02/ -c ${SRC_DIR}/main.cpp -o  ${BUILD_DIR}/main.o
