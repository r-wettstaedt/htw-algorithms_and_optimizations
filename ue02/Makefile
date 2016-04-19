CC=cc
CFLAGS=-Wall -g
FILE=fractal
ARGS=0 256 45 128

# CFLAGS=-Wall -g -lgmp
# FILE=ackermann
# ARGS=3 1

clean:
	rm -f vector.o
	rm -f svg.o
	rm -f fractal.o
	rm -f fractal

f: fractal

fractal: clean
	$(CC) -c vector.c -o vector.o
	$(CC) -c svg.c -o svg.o
	$(CC) -c fractal.c -o fractal.o
	$(CC) $(CFLAGS) vector.o svg.o fractal.o -o fractal
	# valgrind ./fractal $(ARGS)
	# echo "\n==~ OUTPUT ~==\n"
	./fractal $(ARGS)

# all: post-build

# libs: vector.c
# 	rm -f vector.o
# 	${CC} ${CFLAGS} -c vector.c -o vector.o

# pre-build: libs
# 	rm -f ${FILE}.o

# build: pre-build
# 	${CC} ${CFLAGS} ${FILE}.c -o ${FILE}.o

# post-build: build
# 	valgrind ./${FILE}.o ${ARGS}
# 	echo "\n==~ OUTPUT ~==\n"
# 	./${FILE}.o ${ARGS}