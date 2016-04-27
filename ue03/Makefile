CC=cc
CFLAGS=-Wall -g -lgmp
ARGS=5 20

clean:
	rm -f exp
	rm -f modexp

exp: clean
	$(CC) $(CFLAGS) exp.c -o exp
	valgrind ./exp $(ARGS)
	echo "\n==~ OUTPUT ~==\n"
	./exp $(ARGS)
	tput bel
