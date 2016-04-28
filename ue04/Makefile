CC=cc
CFLAGS=-Wall -g
FILE=fractal
ARGS=0 256 45 128

# CFLAGS=-Wall -g -lgmp
# FILE=ackermann
# ARGS=3 1

clean:
	rm -f quicksort.o
	rm -f insertionsort.o
	rm -f mergesort.o
	rm -f sort.o
	rm -f sort

f: sort

sort: clean
	$(CC) -c quicksort.c -o quicksort.o
	$(CC) -c insertionsort.c -o insertionsort.o
	$(CC) -c mergesort.c -o mergesort.o
	$(CC) -c sort.c -o sort.o
	$(CC) $(CFLAGS) quicksort.o insertionsort.o mergesort.o sort.o -o sort
	valgrind ./sort $(ARGS)
	echo "\n==~ OUTPUT ~==\n"
	./sort $(ARGS)
	tput bel