CC=g++
CFLAGS=-std=c++20 -Wall

all: main
Ponto.o: Ponto.hpp Ponto.cpp
	${CC} ${CFLAGS} -c Ponto.cpp

main.o: Ponto.hpp main.cpp
	${CC} ${CFLAGS} -c main.cpp

main: main.o Ponto.o
	${CC} ${CFLAGS} -o main main.o Ponto.o
# Rule for cleaning files generated during compilation.
# Call 'make clean' to use it
clean:
	rm -f main *.o