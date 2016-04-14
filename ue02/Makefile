CC=cc

# CFLAGS=-Wall -g
# FILE=fractal
# ARGS=129 54

CFLAGS=-Wall -g -lgmp
FILE=ackermann
ARGS=3 1

all: post-build

pre-build:
	rm -f ${FILE}

build: pre-build
	${CC} ${CFLAGS} ${FILE}.c -o ${FILE}

post-build: build
	valgrind ./${FILE} ${ARGS}
	echo "\n==~ OUTPUT ~==\n"
	./${FILE} ${ARGS}