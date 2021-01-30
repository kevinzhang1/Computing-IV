CC=g++
SFLAGS=-lsfml-graphics -lsfml-window -lsfml-system
CFLAGS=-g -O -Wall -Werror -std=c++11 -pedantic
all: sfml-app
sfml-app: PhotoMagic.o FibLFSR.o
	$(CC) $(CFLAGS) -o sfml-app PhotoMagic.o FibLFSR.o $(SFLAGS)
PhotoMagic.o: PhotoMagic.cpp FibLFSR.hpp
	$(CC) $(CFLAGS) -c PhotoMagic.cpp -o PhotoMagic.o
FibLFSR.o: FibLFSR.cpp FibLFSR.hpp
	$(CC) $(CFLAGS) -c FibLFSR.cpp -o FibLFSR.o
clean:
	rm PhotoMagic.o sfml-app FibLFSR.o
