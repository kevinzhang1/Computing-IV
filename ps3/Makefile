CC=g++
CFLAGS=-g -O -Wall -Werror -std=c++11 -pedantic
SFLAGS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
all: NBody
NBody: main.o CelestialBody.o
	$(CC) main.o CelestialBody.o -o NBody $(SFLAGS)
main.o:	main.cpp CelestialBody.hpp
	$(CC) $(CFLAGS) -c main.cpp
CelestialBody.o: CelestialBody.cpp CelestialBody.hpp
	$(CC) $(CFLAGS) -c CelestialBody.cpp
clean:
	rm NBody main.o CelestialBody.o
