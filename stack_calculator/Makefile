all: calculator

list.o: list.c calculator.h
	gcc -Wall -g -c -o $@ list.c

main.o: main.c calculator.h
	gcc -Wall -g -c -o $@ main.c

operate.o: operate.c calculator.h
	gcc -Wall -g -c -o $@ operate.c

text.o: text.c calculator.h
	gcc -Wall -g -c -o $@ text.c -lm

calculator: list.o main.o operate.o text.o calculator.h
	gcc -Wall -g -o $@ list.o main.o operate.o text.o -lm

clean:
	rm -v calculator *.o 
