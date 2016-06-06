CC=cc
CFLAGS=-Wall -g -lgmp
ARGS=4

clean:
	rm -f *.o

f: prime

prime: clean
	$(CC) $(CFLAGS) -c rabin-miller.c -o rabin-miller.o
	$(CC) $(CFLAGS) -c main.c -o main.o

	$(CC) $(CFLAGS) rabin-miller.o main.o -o main

	valgrind ./main $(ARGS)
	# echo "\n==~ OUTPUT ~==\n"
	# ./sort $(ARGS)
	tput bel