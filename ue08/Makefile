CC=cc
CFLAGS=-Wall -g
ARGS=4

clean:
	rm -f *.o

f: dijkstra

dijkstra: clean
	$(CC) $(CFLAGS) -c heap.c -o heap.o
	$(CC) $(CFLAGS) -c graph.c -o graph.o
	$(CC) $(CFLAGS) -c main.c -o main.o

	$(CC) $(CFLAGS) heap.o graph.o main.o -o main

	valgrind ./main $(ARGS)
	# echo "\n==~ OUTPUT ~==\n"
	# ./sort $(ARGS)
	tput bel
