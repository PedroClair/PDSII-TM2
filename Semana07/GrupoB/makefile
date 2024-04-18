CX= g++

programa:main.o 
	@echo "criando Programa"
	$(CX) main.o -o programa

main.o:main.cpp
	@echo "criando main.o"
	$(CX) -c main.cpp -o main.o

clean:
	@echo "limpando arquivos"
	rm -f main.o
	@echo "limpeza concluida"