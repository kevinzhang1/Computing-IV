CC=g++
CFLAGS=-g -O -Wall -Werror -std=c++11 -pedantic
SFLAGS=-lsfml-graphics -lsfml-window -lsfml-system

all: sfml-app
sfml-app: main.o PTree.o
	$(CC) $(CFLAGS) -o sfml-app main.o PTree.o $(SFLAGS)
main.o: main.cpp PTree.hpp PTree.cpp
	$(CC) $(CFLAGS) -c main.cpp -o main.o
PTree.o: PTree.cpp PTree.hpp
	$(CC) $(CFLAGS) -c PTree.cpp -o PTree.o
clean:
	rm sfml-app main.o PTree.o
