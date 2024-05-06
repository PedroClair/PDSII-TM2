CC = g++
CFLAGS = -std=c++11 -Wall -g
TARGET = programa

BUILD = ./build
SRC = ./src
INCLUDE = ./include

${BUILD}/${TARGET}: ${BUILD}/bin/persona.o ${BUILD}/bin/aluno.o ${BUILD}/bin/circunferencia.o ${BUILD}/bin/main.o
	${CC} ${CFLAGS} ${BUILD}/bin/aluno.o ${BUILD}/bin/circunferencia.o ${BUILD}/bin/persona.o ${BUILD}/bin/main.o -o ${BUILD}/${TARGET}

${BUILD}/bin/persona.o: ${INCLUDE}/Personagem/persona.hpp ${SRC}/Personagem/persona.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/Personagem/ -c ${SRC}/Personagem/persona.cpp -o ${BUILD}/bin/persona.o

${BUILD}/bin/aluno.o: ${INCLUDE}/Personagem/aluno.hpp ${SRC}/Personagem/aluno.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/Personagem/ -c ${SRC}/Personagem/aluno.cpp -o ${BUILD}/bin/aluno.o

${BUILD}/bin/circunferencia.o: ${INCLUDE}/Mapa/circunferencia.hpp ${SRC}/Mapa/circunferencia.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/Mapa/ -c ${SRC}/Mapa/circunferencia.cpp -o ${BUILD}/bin/circunferencia.o

${BUILD}/bin/main.o: ${INCLUDE}/Personagem/persona.hpp ${INCLUDE}/Personagem/aluno.hpp ${INCLUDE}/Mapa/circunferencia.hpp ${SRC}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/Mapa/ -I ${INCLUDE}/Personagem/ -c ${SRC}/main.cpp -o ${BUILD}/bin/main.o
