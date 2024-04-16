CC = g++
CFLAGS = -std=c++11 -Wall -g
TARGET = programa

BUILD = ./build
SRC = ./src
INCLUDE = ./include

${BUILD}/${TARGET}: ${BUILD}/pagamento_multas.o ${BUILD}/biblioteca.o ${BUILD}/chat.o ${BUILD}/notificacoes.o ${BUILD}/renovacao.o ${BUILD}/main.o 
	${CC} ${CFLAGS} ${BUILD}/pagamento_multas.o ${BUILD}/biblioteca.o ${BUILD}/chat.o ${BUILD}/notificacoes.o ${BUILD}/renovacao.o ${BUILD}/main.o -o ${BUILD}/${TARGET}

${BUILD}/pagamento_multas.o: ${INCLUDE}/pagamento_multas.hpp ${SRC}/pagamento_multas.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/pagamento_multas.cpp -o ${BUILD}/pagamento_multas.o

${BUILD}/biblioteca.o: ${INCLUDE}/biblioteca.hpp ${SRC}/biblioteca.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/biblioteca.cpp -o ${BUILD}/biblioteca.o

${BUILD}/chat.o: ${INCLUDE}/chat.hpp ${SRC}/chat.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/chat.cpp -o ${BUILD}/chat.o

${BUILD}/notificacoes.o: ${INCLUDE}/notificacoes.hpp ${SRC}/notificacoes.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/notificacoes.cpp -o ${BUILD}/notificacoes.o

${BUILD}/renovacao.o: ${INCLUDE}/renovacao.hpp ${SRC}/renovacao.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/renovacao.cpp -o ${BUILD}/renovacao.o

${BUILD}/main.o: ${INCLUDE}/pagamento_multas.hpp ${INCLUDE}/biblioteca.hpp ${INCLUDE}/chat.hpp ${INCLUDE}/notificacoes.hpp ${INCLUDE}/renovacao.hpp main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c main.cpp -o ${BUILD}/main.o