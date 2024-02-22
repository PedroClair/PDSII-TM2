CC = g++
CFLAGS = -std=c++20 -Wall -g #Compilador, avisos e depuração respectivamente
TARGET = program

BUILD_DIR = ./build
INCLUDE_DIR = ./include
SRC_DIR = ./src

${BUILD_DIR}/${TARGET}: ${BUILD_DIR}/circunferencia.o ${BUILD_DIR}/pontoV2.o ${BUILD_DIR}/classeTeste.o ${BUILD_DIR}/mathUtil.o ${BUILD_DIR}/estatico.o ${BUILD_DIR}/testObject.o ${BUILD_DIR}/ponto.o ${BUILD_DIR}/casa.o ${BUILD_DIR}/aluno.o ${BUILD_DIR}/compra.o ${BUILD_DIR}/funcionario.o ${BUILD_DIR}/intro.o ${BUILD_DIR}/memory.o  ${BUILD_DIR}/ponteiro.o ${BUILD_DIR}/ponto3d.o ${BUILD_DIR}/main.o
	${CC} ${CFLAGS} -o ${BUILD_DIR}/${TARGET} ${BUILD_DIR}/*.o

${BUILD_DIR}/circunferencia.o: ${BUILD_DIR}/pontoV2.o ${INCLUDE_DIR}/pooClasse/circunferencia.hpp ${SRC_DIR}/pooClasse/circunferencia.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/pooClasse/ -c ${SRC_DIR}/pooClasse/circunferencia.cpp -o  ${BUILD_DIR}/circunferencia.o

${BUILD_DIR}/pontoV2.o:  ${INCLUDE_DIR}/pooClasse/pontoV2.hpp ${SRC_DIR}/pooClasse/pontoV2.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/pooClasse/ -c ${SRC_DIR}/pooClasse/pontoV2.cpp -o  ${BUILD_DIR}/pontoV2.o

${BUILD_DIR}/classeTeste.o:  ${INCLUDE_DIR}/pooClasse/classeTeste.hpp ${SRC_DIR}/pooClasse/classeTeste.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/pooClasse/ -c ${SRC_DIR}/pooClasse/classeTeste.cpp -o  ${BUILD_DIR}/classeTeste.o

${BUILD_DIR}/mathUtil.o:  ${INCLUDE_DIR}/pooClasse/mathUtil.hpp ${SRC_DIR}/pooClasse/mathUtil.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/pooClasse/ -c ${SRC_DIR}/pooClasse/mathUtil.cpp -o  ${BUILD_DIR}/mathUtil.o

${BUILD_DIR}/estatico.o:  ${INCLUDE_DIR}/pooClasse/estatico.hpp ${SRC_DIR}/pooClasse/estatico.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/pooClasse/ -c ${SRC_DIR}/pooClasse/estatico.cpp -o  ${BUILD_DIR}/estatico.o

${BUILD_DIR}/testObject.o:  ${INCLUDE_DIR}/pooClasse/testObject.hpp ${SRC_DIR}/pooClasse/testObject.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/pooClasse/ -c ${SRC_DIR}/pooClasse/testObject.cpp -o  ${BUILD_DIR}/testObject.o

${BUILD_DIR}/ponto.o:  ${INCLUDE_DIR}/pooClasse/ponto.hpp ${SRC_DIR}/pooClasse/ponto.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/pooClasse/ -c ${SRC_DIR}/pooClasse/ponto.cpp -o  ${BUILD_DIR}/ponto.o

${BUILD_DIR}/casa.o:  ${INCLUDE_DIR}/pooClasse/casa.hpp ${SRC_DIR}/pooClasse/casa.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/pooClasse/ -c ${SRC_DIR}/pooClasse/casa.cpp -o  ${BUILD_DIR}/casa.o

${BUILD_DIR}/aluno.o:  ${INCLUDE_DIR}/basico/aluno.hpp ${SRC_DIR}/basico/aluno.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/basico/ -c ${SRC_DIR}/basico/aluno.cpp -o  ${BUILD_DIR}/aluno.o

${BUILD_DIR}/compra.o:  ${INCLUDE_DIR}/basico/compra.hpp ${SRC_DIR}/basico/compra.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/basico/ -c ${SRC_DIR}/basico/compra.cpp -o  ${BUILD_DIR}/compra.o

${BUILD_DIR}/funcionario.o:  ${INCLUDE_DIR}/basico/funcionario.hpp ${SRC_DIR}/basico/funcionario.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/basico/ -c ${SRC_DIR}/basico/funcionario.cpp -o  ${BUILD_DIR}/funcionario.o

${BUILD_DIR}/intro.o:  ${INCLUDE_DIR}/basico/intro.hpp ${SRC_DIR}/basico/intro.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/basico/ -c ${SRC_DIR}/basico/intro.cpp -o  ${BUILD_DIR}/intro.o

${BUILD_DIR}/memory.o:  ${INCLUDE_DIR}/basico/memory.hpp ${SRC_DIR}/basico/memory.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/basico/ -c ${SRC_DIR}/basico/memory.cpp -o  ${BUILD_DIR}/memory.o

${BUILD_DIR}/ponteiro.o:  ${INCLUDE_DIR}/basico/ponteiro.hpp ${SRC_DIR}/basico/ponteiro.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/basico/ -c ${SRC_DIR}/basico/ponteiro.cpp -o  ${BUILD_DIR}/ponteiro.o

${BUILD_DIR}/ponto3d.o:  ${INCLUDE_DIR}/basico/ponto3d.hpp ${SRC_DIR}/basico/ponto3d.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/basico/ -c ${SRC_DIR}/basico/ponto3d.cpp -o  ${BUILD_DIR}/ponto3d.o

${BUILD_DIR}/main.o: main.cpp #inserir os arquivos utilizados.
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/basico/ -I ${INCLUDE_DIR}/pooClasse/ -c main.cpp -o  ${BUILD_DIR}/main.o

#clean:
#	rm ./build/ -> a -> mkdir build