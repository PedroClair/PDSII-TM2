CC = g++
CFLAGS = -std=c++20 -Wall -g
TARGET = programa

BUILD_DIR = ./build
BUILD_APP = ${BUILD_DIR}/app
BUILD_OBJ = ${BUILD_DIR}/obj
INCLUDE_DIR = ./include
SRC_DIR = ./src

${BUILD_APP}/${TARGET}: ${BUILD_OBJ}/main.o ${BUILD_OBJ}/circunferencia.o
	${CC} ${CFLAGS} ${BUILD_OBJ}/*.o -o ${BUILD_APP}/${TARGET}

${BUILD_OBJ}/main.o: ${INCLUDE_DIR}/circunferencia.hpp ${SRC_DIR}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/main.cpp -o ${BUILD_OBJ}/main.o

${BUILD_OBJ}/circunferencia.o: ${INCLUDE_DIR}/circunferencia.hpp ${SRC_DIR}/circunferencia.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/circunferencia.cpp -o ${BUILD_OBJ}/circunferencia.o

# g++ -std=c++20 -Wall -g -I ./include/ -c ./src/main.cpp -o ./build/main.o
# g++ -std=c++20 -Wall -g -I ./include/ -c ./src/circunferencia.cpp -o ./build/circunferencia.o
# g++ -std=c++20 -Wall -g ./build/*.o -o ./build/programa
# ./build/programa