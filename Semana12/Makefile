CC = g++
CFLAGS = -std=c++11
CFLAGS_DEBUG = -std=c++11 -Wall -g
TARGET = prog

BUILD = ./build
SRC = ./src
INCLUDE = ./include

#PROGRAMA
${BUILD}/${TARGET}: ${BUILD}/bin/persona.o ${BUILD}/bin/pessoa.o ${BUILD}/bin/aluno.o ${BUILD}/bin/animal.o ${BUILD}/bin/cachorro.o ${BUILD}/bin/pato.o ${BUILD}/bin/gato.o ${BUILD}/bin/ponto3d.o ${BUILD}/bin/main.o
	${CC} ${CFLAGS} ${BUILD}/bin/persona.o ${BUILD}/bin/pessoa.o ${BUILD}/bin/aluno.o ${BUILD}/bin/animal.o ${BUILD}/bin/cachorro.o ${BUILD}/bin/pato.o ${BUILD}/bin/gato.o ${BUILD}/bin/ponto3d.o ${BUILD}/bin/main.o -o ${BUILD}/${TARGET}

#PERSONAGEM
${BUILD}/bin/persona.o: ${INCLUDE}/Personagem/persona.hpp ${SRC}/Personagem/persona.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/Personagem/ -c ${SRC}/Personagem/persona.cpp -o ${BUILD}/bin/persona.o

${BUILD}/bin/pessoa.o: ${INCLUDE}/Personagem/pessoa.hpp ${INCLUDE}/Personagem/persona.hpp ${SRC}/Personagem/pessoa.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/Personagem/ -c ${SRC}/Personagem/pessoa.cpp -o ${BUILD}/bin/pessoa.o

${BUILD}/bin/aluno.o: ${INCLUDE}/Personagem/aluno.hpp ${INCLUDE}/Personagem/Persona.hpp ${SRC}/Personagem/aluno.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/Personagem/ -c ${SRC}/Personagem/aluno.cpp -o ${BUILD}/bin/aluno.o

${BUILD}/bin/animal.o: ${INCLUDE}/Personagem/animal.hpp ${SRC}/Personagem/animal.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/Personagem/ -c ${SRC}/Personagem/animal.cpp -o ${BUILD}/bin/animal.o

${BUILD}/bin/cachorro.o: ${INCLUDE}/Personagem/cachorro.hpp ${INCLUDE}/Personagem/animal.hpp ${SRC}/Personagem/cachorro.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/Personagem/ -c ${SRC}/Personagem/cachorro.cpp -o ${BUILD}/bin/cachorro.o

${BUILD}/bin/pato.o: ${INCLUDE}/Personagem/pato.hpp ${INCLUDE}/Personagem/animal.hpp ${SRC}/Personagem/pato.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/Personagem/ -c ${SRC}/Personagem/pato.cpp -o ${BUILD}/bin/pato.o

${BUILD}/bin/gato.o: ${INCLUDE}/Personagem/gato.hpp ${INCLUDE}/Personagem/gato.hpp ${INCLUDE}/Personagem/animal.hpp ${SRC}/Personagem/gato.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/Personagem/ -c ${SRC}/Personagem/gato.cpp -o ${BUILD}/bin/gato.o


#MAPA
${BUILD}/bin/ponto3d.o: ${INCLUDE}/Mapa/ponto3d.hpp ${SRC}/Mapa/ponto3d.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/Mapa/ -c ${SRC}/Mapa/ponto3d.cpp -o ${BUILD}/bin/ponto3d.o

#MAIN
${BUILD}/bin/main.o: ${INCLUDE}/Personagem/persona.hpp ${INCLUDE}/Personagem/pessoa.hpp ${INCLUDE}/Personagem/aluno.hpp ${INCLUDE}/Personagem/animal.hpp ${INCLUDE}/Personagem/cachorro.hpp ${INCLUDE}/Personagem/pato.hpp ${INCLUDE}/Personagem/gato.hpp ${INCLUDE}/Mapa/ponto3d.hpp ${SRC}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/Mapa/ -I ${INCLUDE}/Personagem/ -c ${SRC}/main.cpp -o ${BUILD}/bin/main.o

builder:
	if not exist build mkdir build
	if not exist build\bin mkdir build\bin

run:
	${BUILD}/${TARGET}

clean:
	del build\*.exe
	del build\bin\*.o

test:
	g++ -std=c++11 -Wall -g test.cpp -o progTeste
	.\progTeste.exe

cleanTest:
	del progTeste.exe