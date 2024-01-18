CC = g++
CFLAGS = -std=c++20 -Wall
TARGET = program

BUILD_DIR = ./build
INCLUDE_DIR = ./include
SRC_DIR = ./src

${BUILD_DIR}/${TARGET}: ${BUILD_DIR}/main.o ${BUILD_DIR}/memory.o
	${CC} ${CFLAGS} -o ${BUILD_DIR}/${TARGET} ${BUILD_DIR}/main.o ${BUILD_DIR}/memory.o
	${BUILD_DIR}/${TARGET}

${BUILD_DIR}/main.o: ${INCLUDE_DIR}/memory.hpp ${SRC_DIR}/memory.cpp ${SRC_DIR}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/main.cpp -o  ${BUILD_DIR}/main.o

${BUILD_DIR}/memory.o:  ${INCLUDE_DIR}/memory.hpp ${SRC_DIR}/memory.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/memory.cpp -o  ${BUILD_DIR}/memory.o

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