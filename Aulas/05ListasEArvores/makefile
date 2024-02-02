# Makefile Structured
CC = g++
CFLAGS = -std=c++11 -Wall
TARGET = programa

BUILD = ./build
BUILD_BIN = ${BUILD}/bin
BUILD_LIB = ${BUILD}/lib
INCLUDE = ./include
SRC = ./src

${BUILD}/${TARGET}: ${BUILD_BIN}/main.o ${BUILD_BIN}/list.o ${BUILD_BIN}/listD.o ${BUILD_BIN}/BST.o
	${CC} ${CFLAGS} ${BUILD_BIN}/*.o -o ${BUILD}/${TARGET}
	${BUILD}/${TARGET}

${BUILD_BIN}/main.o: ${INCLUDE}/lista/*.hpp ${INCLUDE}/arvore/*.hpp ${SRC}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/lista/ -I ${INCLUDE}/arvore/ -c ${SRC}/main.cpp -o ${BUILD_BIN}/main.o

${BUILD_BIN}/list.o: ${INCLUDE}/lista/list.hpp ${SRC}/lista/list.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/lista/ -c ${SRC}/lista/list.cpp -o ${BUILD_BIN}/list.o

${BUILD_BIN}/listD.o: ${INCLUDE}/lista/listD.hpp ${SRC}/lista/listD.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/lista/ -c ${SRC}/lista/listD.cpp -o ${BUILD_BIN}/listD.o

${BUILD_BIN}/BST.o: ${INCLUDE}/arvore/BST.hpp ${SRC}/arvore/BST.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/arvore/ -c ${SRC}/arvore/BST.cpp -o ${BUILD_BIN}/BST.o


# CMD step by step
# g++ -std=c++20 -Wall -I include/lista/ -c src/lista/list.cpp -o build/bin/list.o
# g++ -std=c++20 -Wall -I include/lista/ -c src/main.cpp -o build/bin/main.o
# g++ -std=c++20 -Wall build/bin/*.o -o build/programa
# .\build\programa.exe

# build/programa: Generalization
# 	g++ -std=c++20 -Wall -I include/lista/ src/main.cpp src/lista/list.cpp -o build/programa
# 	build/programa

# Makefile Structured without tags
# program: main.o list.o
# 	g++ -std=c++20 -Wall build/bin/*.o -o build/programa
# 	.\build\programa.exe

# main.o: 
# 	g++ -std=c++20 -Wall -I include/lista/ -c src/main.cpp -o build/bin/main.o

# list.o:
# 	g++ -std=c++20 -Wall -I include/lista/ -c src/lista/list.cpp -o build/bin/list.o