CC=cc
CFLAGS=-Wall -g
FILE=fractal
ARGS=0 256 45 128

# CFLAGS=-Wall -g -lgmp
# FILE=ackermann
# ARGS=3 1

clean:
	rm -f heapsort.o
	rm -f quicksort.o
	rm -f sort.o
	rm -f sort

f: sort

sort: clean
	$(CC) -c heapsort.c -o heapsort.o
	$(CC) -c quicksort.c -o quicksort.o
	$(CC) -c sort.c -o sort.o
	$(CC) $(CFLAGS) heapsort.o quicksort.o sort.o -o sort
	valgrind ./sort $(ARGS)
	# echo "\n==~ OUTPUT ~==\n"
	# ./sort $(ARGS)
	tput bel