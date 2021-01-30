CC=g++
CFLAGS=-g -O -Wall -Werror -std=c++11 -pedantic
Boost=-lboost_unit_test_framework
all: TextGenerator test
TextGenerator: TextGenerator.o MModel.o
	$(CC) TextGenerator.o MModel.o -o TextGenerator
test:	test.o MModel.o
	$(CC) test.o MModel.o -o test $(Boost)
test.o: test.cpp
	$(CC) -c test.cpp $(Boost)
TextGenerator.o: TextGenerator.cpp MModel.h
	$(CC) $(CFLAGS) -c TextGenerator.cpp
MModel.o: MModel.cpp MModel.h
	$(CC) $(CFLAGS) -c MModel.cpp
clean:
	rm TextGenerator test test.o TextGenerator.o MModel.o
