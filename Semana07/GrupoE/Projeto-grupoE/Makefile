CC = g++
CFLAGS = -Wall -Wextra -std=c++11

SRCS = main.cpp historias.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = historia_bancaria

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)
