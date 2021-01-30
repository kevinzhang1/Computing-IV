CC=g++
CFLAGS=-g -O -Wall -Werror -std=c++11 -pedantic
LIBS=-lboost_unit_test_framework
all: test
test: test.o RingBuffer.o
	$(CC) test.o RingBuffer.o -o test $(LIBS)
test.o: test.cpp RingBuffer.h
	$(CC) $(CFLAGS) -c test.cpp
RingBuffer.o: RingBuffer.cpp RingBuffer.h
	$(CC) $(CFLAGS) -c RingBuffer.cpp
clean:
	rm test test.o RingBuffer.o
