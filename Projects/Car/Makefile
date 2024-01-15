CC=g++
CFLAGS=-std=c++11 -Wall
TARGET=program

BUILD_DIR = ./build
SRC_DIR = ./src
INCLUDE_DIR = ./include

${BUILD_DIR}/${TARGET}: ${BUILD_DIR}/Ferrari.o ${BUILD_DIR}/Ford.o ${BUILD_DIR}/main.o
	${CC} ${CFLAGS} -o ${BUILD_DIR}/${TARGET} ${BUILD_DIR}/*.o

${BUILD_DIR}/Ferrari.o: ${INCLUDE_DIR}/automovel/Ferrari.hpp ${SRC_DIR}/automovel/Ferrari.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/automovel/ -c ${SRC_DIR}/automovel/Ferrari.cpp -o ${BUILD_DIR}/Ferrari.o

${BUILD_DIR}/Ford.o: ${INCLUDE_DIR}/automovel/Ford.hpp ${SRC_DIR}/automovel/Ford.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/automovel/ -c ${SRC_DIR}/automovel/Ford.cpp -o ${BUILD_DIR}/Ford.o

${BUILD_DIR}/main.o: ${INCLUDE_DIR}/automovel/Ferrari.hpp ${INCLUDE_DIR}/automovel/Ford.hpp ${SRC_DIR}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/automovel/ -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o

# Rule for cleaning files generated during compilation.
# Call 'make clean' to use it
clean:
	rm -f ${BUILD_DIR}/*