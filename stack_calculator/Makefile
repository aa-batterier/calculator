all: bin/calculator

lib/list.o: src/list.c src/calculator.h
	gcc -Wall -g -c -o $@ src/list.c

lib/main.o: src/main.c src/calculator.h
	gcc -Wall -g -c -o $@ src/main.c

lib/operate.o: src/operate.c src/calculator.h
	gcc -Wall -g -c -o $@ src/operate.c

lib/text.o: src/text.c src/calculator.h
	gcc -Wall -g -c -o $@ src/text.c -lm

bin/calculator: lib/list.o lib/main.o lib/operate.o lib/text.o src/calculator.h
	gcc -Wall -g -o $@ lib/list.o lib/main.o lib/operate.o lib/text.o -lm

clean:
	rm -v bin/* lib/*
