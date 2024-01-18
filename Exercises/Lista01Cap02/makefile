CC = g++
CFLAGS = -std=c++20 -Wall
TARGET = program

BUILD_DIR = ./build
INCLUDE_DIR = ./include
SRC_DIR = ./src

${BUILD_DIR}/${TARGET}: ${BUILD_DIR}/compra.o ${BUILD_DIR}/main.o
	${CC} ${CFLAGS} -o ${BUILD_DIR}/${TARGET} ${BUILD_DIR}/*.o
	${BUILD_DIR}/${TARGET}

${BUILD_DIR}/compra.o: ${INCLUDE_DIR}/compra.hpp ${SRC_DIR}/compra.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/compra.cpp -o ${BUILD_DIR}/compra.o

${BUILD_DIR}/main.o: ${INCLUDE_DIR}/compra.hpp ${SRC_DIR}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o


# ./build/program: ./build/compra.o ./build/main.o
#	g++	-std=c++20 -Wall -o ./build/program ./build/*.o

# ./build/compra.o: ./include/compra.hpp ./src/compra.cpp
#	g++	-std=c++20 -Wall -I ./include -c ./src/compra.cpp -o ./build/compra.o

# ./build/main.o: ./include/compra.hpp ./src/main.cpp
#	g++	-std=c++20 -Wall -I ./include -c ./src/main.cpp -o ./build/main.o

# default
# (01) g++ -std=c++20 -Wall main.cpp -o program
# (02) g++ -std=c++20 -Wall memory.cpp main.cpp -o program
# (03) ----------------------------------------------------
# CC = g++
# CFLAGS = -std=c++20 -Wall -g
# TARGET = program

# ${TARGET}: main.o memory.o
# 	${CC} ${CFLAGS} -o ${TARGET} main.o memory.o
# 	${TARGET}

# main.o: memory.hpp memory.cpp
# 	${CC} ${CFLAGS} -c main.cpp

# memory.o: memory.hpp
# (03) -----------------------------------------------------

