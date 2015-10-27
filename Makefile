exec: compile_main
	./bptree < input.txt
compile_main:
	gcc bptree.c main.c -o bptree
