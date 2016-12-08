all: main

main: main.o
	g++ -o main main.o

generator.o: generator.cpp card.hpp
	g++ -o generator.o -c generator.cpp -W -Wall -ansi -pedantic

dfs.o: dfs.cpp dfs.hpp
	g++ -o dfs.o -c dfs.cpp -W -Wall -ansi -pedantic	

main.o: main.cpp
	g++ -o main.o -c main.cpp -W -Wall -ansi -pedantic

clean:
	rm -rf *.o

mrproper: clean
	rm -rf hello