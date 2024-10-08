RE2NFA: main.o stack.o nfa.o
	gcc -g -o RE2NFA main.o stack.o nfa.o

main.o: main.c
	gcc -g -c main.c

stack.o: stack.c
	gcc -g -c stack.c

nfa.o: nfa.c
	gcc -g -c nfa.c

clean:
	rm -f RE2NFA main.o stack.o
