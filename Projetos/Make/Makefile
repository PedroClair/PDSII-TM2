CC=g++
CFLAGS=-std=c++20 -Wall
TARGET=program

BUILD_DIR = ./build
BUILD_BIN = ${BUILD_DIR}/bin
BUILD_LIB = ${BUILD_DIR}/lib
SRC_DIR = ./src
INCLUDE_DIR = ./include

#./build/program: ./build/Ferrari.o
${BUILD_DIR}/${TARGET}: ${BUILD_BIN}/Ferrari.o ${BUILD_BIN}/Ford.o ${BUILD_BIN}/main.o #./build/program: ./build/Ferrari.o 
	${CC} ${CFLAGS} -o ${BUILD_DIR}/${TARGET} ${BUILD_BIN}/*.o

${BUILD_BIN}/Ferrari.o: ${INCLUDE_DIR}/automovel/Ferrari.hpp ${SRC_DIR}/automovel/Ferrari.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/automovel/ -c ${SRC_DIR}/automovel/Ferrari.cpp -o ${BUILD_BIN}/Ferrari.o

${BUILD_BIN}/Ford.o: ${INCLUDE_DIR}/automovel/Ford.hpp ${SRC_DIR}/automovel/Ford.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/automovel/ -c ${SRC_DIR}/automovel/Ford.cpp -o ${BUILD_BIN}/Ford.o

${BUILD_BIN}/main.o: ${INCLUDE_DIR}/automovel/Ferrari.hpp ${INCLUDE_DIR}/automovel/Ford.hpp ${SRC_DIR}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/automovel/ -c ${SRC_DIR}/main.cpp -o ${BUILD_BIN}/main.o

# Rule for cleaning files generated during compilation.
# Call 'make clean' to use it
# clean:
# 	rm -r ${BUILD_DIR}/*.o