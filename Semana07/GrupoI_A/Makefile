CC = g++
CFLAGS = -std=c++11 -Wall -g
TARGET = programa

BUILD = ./build
SRC = ./src
INCLUDE = ./include

${BUILD}/${TARGET}: ${BUILD}/Usuario.o ${BUILD}/PrestadorDeServicos.o ${BUILD}/Prestadores.o ${BUILD}/Sistema.o  ${BUILD}/main.o
	${CC} ${CFLAGS} ${BUILD}/PrestadorDeServicos.o ${BUILD}/auxiliares.o  ${BUILD}/Prestadores.o ${BUILD}/Sistema.o ${BUILD}/Usuario.o ${BUILD}/main.o -o ${BUILD}/${TARGET}

${BUILD}/Usuario.o: ${INCLUDE}/Usuario.hpp ${SRC}/Usuario.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/Usuario.cpp -o ${BUILD}/Usuario.o

${BUILD}/PrestadorDeServicos.o: ${INCLUDE}/PrestadorDeServicos.hpp ${SRC}/PrestadorDeServicos.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/PrestadorDeServicos.cpp -o ${BUILD}/PrestadorDeServicos.o

${BUILD}/Prestadores.o: ${BUILD}/auxiliares.o ${INCLUDE}/Prestadores.hpp ${SRC}/Prestadores.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/Prestadores.cpp -o ${BUILD}/Prestadores.o

${BUILD}/auxiliares.o: ${INCLUDE}/auxiliares.hpp ${SRC}/auxiliares.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/auxiliares.cpp -o ${BUILD}/auxiliares.o

${BUILD}/Sistema.o: ${INCLUDE}/Sistema.hpp ${SRC}/Sistema.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/Sistema.cpp -o ${BUILD}/Sistema.o

${BUILD}/main.o: ${INCLUDE}/Usuario.hpp ${INCLUDE}/PrestadorDeServicos.hpp ./main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c main.cpp -o ${BUILD}/main.o