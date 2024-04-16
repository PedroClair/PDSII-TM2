
CC = g++
CFLAGS = -std=c++11 -Wall -g
TARGET = programa

programa:  user_story.o main.o
	${CC} ${CFLAGS}  user_story.o  main.o -o programa

user_story.o: user_story.hpp user_story.cpp
	${CC} ${CFLAGS} -c user_story.cpp -o user_story.o 

main.o:  user_story.hpp main.cpp
	${CC} ${CFLAGS} -c main.cpp -o main.o 