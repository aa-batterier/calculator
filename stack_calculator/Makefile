all: bin/calculator

bin/calculator: src/list.c src/main.c src/operate.c src/text.c src/calculate.h
	gcc -Wall -g -o $@ src/list.c src/main.c src/text.c src/operate.c -lm

clean:
	rm -v bin/* lib/*
