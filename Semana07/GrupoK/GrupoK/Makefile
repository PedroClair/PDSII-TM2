# Nome do executável
TARGET = main

# Lista de arquivos fonte
SRCS = program/main.cpp src/modelagem.cpp

# Comando de compilação
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Regra padrão para compilar o programa
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Regra para limpar os arquivos gerados pela compilação
clean:
	rm -f $(TARGET)

# Define a regra 'all' como dependência do alvo padrão
all: $(TARGET)

# Define a regra 'all' como phony (não depende de arquivos)
.PHONY: all clean
