CC = g++
CFLAGS = -std=c++11 -Wall -g
TARGET = programa

BUILD = ./build
SRC = ./src
INCLUDE = ./include

${BUILD}/${TARGET}: ${BUILD}/personagem.o ${BUILD}/ataques.o ${BUILD}/Campanha.o ${BUILD}/EscolhaClasse.o ${BUILD}/inventario.o ${BUILD}/main.o
	${CC} ${CFLAGS} ${BUILD}/personagem.o ${BUILD}/ataques.o ${BUILD}/Campanha.o ${BUILD}/EscolhaClasse.o ${BUILD}/inventario.o  ${BUILD}/main.o -o ${BUILD}/${TARGET}

${BUILD}/personagem.o: ${INCLUDE}/personagem.hpp ${SRC}/personagem.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/personagem.cpp -o ${BUILD}/personagem.o

${BUILD}/ataques.o: ${INCLUDE}/ataques.hpp ${SRC}/ataques.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/ataques.cpp -o ${BUILD}/ataques.o

${BUILD}/Campanha.o: ${INCLUDE}/Campanha.hpp ${SRC}/Campanha.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/Campanha.cpp -o ${BUILD}/Campanha.o

${BUILD}/EscolhaClasse.o: ${INCLUDE}/EscolhaClasse.hpp ${SRC}/EscolhaClasse.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/EscolhaClasse.cpp -o ${BUILD}/EscolhaClasse.o

${BUILD}/inventario.o: ${INCLUDE}/inventario.hpp ${SRC}/inventario.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/inventario.cpp -o ${BUILD}/inventario.o

${BUILD}/main.o: ${INCLUDE}/personagem.hpp ${INCLUDE}/ataques.hpp ${INCLUDE}/Campanha.hpp ${INCLUDE}/EscolhaClasse.hpp ${INCLUDE}/inventario.hpp main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c main.cpp -o ${BUILD}/main.o

