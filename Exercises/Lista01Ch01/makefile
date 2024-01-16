CC=g++
CFLAGS=-std=c++20 -Wall
TARGET=program

BUILD_DIR = ./build
SRC_DIR = ./src
INCLUDE_DIR = ./include

# ./build/program: ./build/lista.o ./build/main.o
# 	g++	-std=c++20 -Wall -o ./build/program ./build/program/*o

# ./build/lista.o: ./include/lista.hpp ./build/lista.cpp
# 	g++	-std=c++20 -Wall -I ./include -c ./src/lista.cpp -o ./build/lista.o

# ./build/main.o: ./include/lista.hpp ./build/main.cpp
# 	g++	-std=c++20 -Wall -I ./include -c ./src/main.cpp -o ./build/main.o


${BUILD_DIR}/${TARGET}: ${BUILD_DIR}/lista.o ${BUILD_DIR}/main.o
	${CC} ${CFLAGS} -o ${BUILD_DIR}/${TARGET} ${BUILD_DIR}/*.o

${BUILD_DIR}/lista.o: ${INCLUDE_DIR}/lista.hpp ${SRC_DIR}/lista.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/lista.cpp -o ${BUILD_DIR}/lista.o

${BUILD_DIR}/main.o: ${INCLUDE_DIR}/lista.hpp ${SRC_DIR}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o

# Rule for cleaning files generated during compilation.
# Call 'make clean' to use it
clean:
	rm -f ${BUILD_DIR}/*.o