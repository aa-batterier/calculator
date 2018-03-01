all: bin/stack_calculator

lib/list.o: src/list.c src/calculator.h
	gcc -Wall -g -c -o $@ src/list.c

lib/main.o: src/main.c src/calculator.h
	gcc -Wall -g -c -o $@ src/main.c

lib/operate.o: src/operate.c src/calculator.h
	gcc -Wall -g -c -o $@ src/operate.c

bin/stack_calculator: lib/list.o lib/main.o lib/operate.o src/calculator.h
	gcc -Wall -g -o $@ lib/list.o lib/main.o lib/operate.o

clean:
	rm -v bin/* lib/*
