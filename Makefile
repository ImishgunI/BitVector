CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 -g

all: clean bit_vector

bit_vector: bit_vector.o
	$(CC) $(CFLAGS) $< -o $@

bit_vector.o: main.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o

clang-format:
	clang-format -style=Google -i *.c *.h
