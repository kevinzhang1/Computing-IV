CC= g++
CFLAGS= -g -O -Wall -Werror -std=c++11 -pedantic
SFLAGS= -lsfml-system
all: ED
ED: main.o ED.o
	$(CC) main.o ED.o -o ED $(SFLAGS)
main.o:	main.cpp ED.cpp ED.hpp
	$(CC) $(CFLAGS) -c main.cpp
ED.o:	ED.cpp ED.hpp
	$(CC) $(CFLAGS) -c ED.cpp
clean:
	rm ED main.o ED.o
