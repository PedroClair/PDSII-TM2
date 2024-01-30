# Makefile Structured
program: main.o list.o
	g++ -std=c++20 -Wall build/bin/*.o -o build/programa
	.\build\programa.exe

main.o: 
	g++ -std=c++20 -Wall -I include/lista/ -c src/main.cpp -o build/bin/main.o

list.o:
	g++ -std=c++20 -Wall -I include/lista/ -c src/lista/list.cpp -o build/bin/list.o

# build/programa: Generalization
# 	g++ -std=c++20 -Wall -I include/lista/ src/main.cpp src/lista/list.cpp -o build/programa
# 	build/programa

# CMD step by step
# g++ -std=c++20 -Wall -I include/lista/ -c src/lista/list.cpp -o build/bin/list.o
# g++ -std=c++20 -Wall -I include/lista/ -c src/main.cpp -o build/bin/main.o
# g++ -std=c++20 -Wall build/bin/*.o -o build/programa
# .\build\programa.exe