CC=cc
CFLAGS=-Wall -g -lgmp
ARGS=4

clean:
	rm -f *.o

f: dijkstra

dijkstra: clean
	$(CC) $(CFLAGS) -c graph.c -o graph.o
	$(CC) $(CFLAGS) -c main.c -o main.o

	$(CC) $(CFLAGS) graph.o main.o -o main

	valgrind ./main $(ARGS)
	# echo "\n==~ OUTPUT ~==\n"
	# ./sort $(ARGS)
	tput bel
