all: bin/stack_calculator

lib/list.o: src/list.c src/stack_calculator.h
	gcc -Wall -g -c -o $@ src/list.c

lib/main.o: src/main.c src/stack_calculator.h
	gcc -Wall -g -c -o $@ src/main.c

bin/stack_calculator: lib/list.o lib/main.o src/stack_calculator.h
	gcc -Wall -g -o $@ lib/list.o lib/main.o

clean:
	rm -v bin/* lib/*
