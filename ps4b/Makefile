CC=g++
CFLAGS=-g -O -Wall -Werror -std=c++11 -pedantic
SFLAGS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
all: KSGuitarSim extracredit
KSGuitarSim: KSGuitarSim.o StringSound.o RingBuffer.o
	$(CC) KSGuitarSim.o StringSound.o RingBuffer.o -o KSGuitarSim $(SFLAGS)
extracredit: extracredit.o StringSound.o RingBuffer.o
	$(CC) extracredit.o StringSound.o RingBuffer.o -o extracredit $(SFLAGS)
KSGuitarSim.o: KSGuitarSim.cpp StringSound.h
	$(CC) $(CFLAGS) -c KSGuitarSim.cpp
extracredit.o: extracredit.cpp StringSound.h
	$(CC) $(CFLAGS) -c extracredit.cpp
StringSound.o: StringSound.cpp StringSound.h
	$(CC) $(CFLAGS) -c StringSound.cpp
RingBuffer.o: RingBuffer.cpp RingBuffer.hpp
	$(CC) $(CFLAGS) -c RingBuffer.cpp
clean:
	rm KSGuitarSim extracredit KSGuitarSim.o extracredit.o StringSound.o RingBuffer.o
