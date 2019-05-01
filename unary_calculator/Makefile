all: unarycalculator

unarycalculator: list.cpp list.h main.cpp unary.cpp unary.h
	g++ -Wall -g -o $@ list.cpp main.cpp unary.cpp -std=c++17

clean:
	rm -rv unarycalculator
