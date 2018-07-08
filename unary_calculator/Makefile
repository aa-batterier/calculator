all: bin/unarycalculator

bin/unarycalculator: src/list.cpp src/list.h src/main.cpp src/unary.cpp src/unary.h
	g++ -Wall -g -o $@ src/list.cpp src/main.cpp src/unary.cpp -std=c++17
