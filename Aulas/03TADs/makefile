CC = g++
CFLAGS = -std=c++20 -Wall
TARGET = programa

BUILD_DIR = ./build 
SRC_DIR = ./src 
INCLUDE_DIR = ./include 

${BUILD_DIR}/${TARGET}: ${BUILD_DIR}/circunferencia.o ${BUILD_DIR}/main.o
	${CC} ${CFLAGS} -o ${BUILD_DIR}/${TARGET} ${BUILD_DIR}/*.o

${BUILD_DIR}/circunferencia.o: ${INCLUDE_DIR}/circunferencia.hpp ${SRC_DIR}/circunferencia.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/circunferencia.cpp -o ${BUILD_DIR}/circunferencia.o

${BUILD_DIR}/main.o: ${INCLUDE_DIR}/circunferencia.hpp ${SRC_DIR}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o

