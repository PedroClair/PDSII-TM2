CC = g++
CFLAGS = -std=c++11 -Wall -g
TARGET = prog

BUILD = ./build
SRC = ./src
INCLUDE = ./include

test:
	g++ -std=c++11 -Wall -g test.cpp -o progTeste

build: ${BUILD}/${TARGET}

${BUILD}/${TARGET}: ${BUILD}/bin/persona.o ${BUILD}/bin/aluno.o ${BUILD}/bin/ponto3d.o ${BUILD}/bin/main.o
	${CC} ${CFLAGS} ${BUILD}/bin/aluno.o ${BUILD}/bin/ponto3d.o ${BUILD}/bin/persona.o ${BUILD}/bin/main.o -o ${BUILD}/${TARGET}

${BUILD}/bin/persona.o: ${INCLUDE}/Personagem/persona.hpp ${SRC}/Personagem/persona.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/Personagem/ -c ${SRC}/Personagem/persona.cpp -o ${BUILD}/bin/persona.o

${BUILD}/bin/aluno.o: ${INCLUDE}/Personagem/aluno.hpp ${SRC}/Personagem/aluno.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/Personagem/ -c ${SRC}/Personagem/aluno.cpp -o ${BUILD}/bin/aluno.o

${BUILD}/bin/ponto3d.o: ${INCLUDE}/Mapa/ponto3d.hpp ${SRC}/Mapa/ponto3d.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/Mapa/ -c ${SRC}/Mapa/ponto3d.cpp -o ${BUILD}/bin/ponto3d.o

${BUILD}/bin/main.o: ${INCLUDE}/Personagem/persona.hpp ${INCLUDE}/Personagem/aluno.hpp ${INCLUDE}/Mapa/ponto3d.hpp ${SRC}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/Mapa/ -I ${INCLUDE}/Personagem/ -c ${SRC}/main.cpp -o ${BUILD}/bin/main.o

run:
	${BUILD}/${TARGET}