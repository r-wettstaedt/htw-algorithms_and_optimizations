CC=cc
CFLAGS=-Wall -g -lgmp
ARGS=

clean:
	rm -f *.o

f: prime

prime: clean
	$(CC) $(CFLAGS) -c rabin-miller.c -o rabin-miller.o

	$(CC) $(CFLAGS) rabin-miller.o -o rabin-miller

	valgrind ./rabin-miller $(ARGS)
	# echo "\n==~ OUTPUT ~==\n"
	# ./sort $(ARGS)
	tput bel