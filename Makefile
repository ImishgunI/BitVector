CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 -g
LIB_NAME = bit_vector.a

all: clean $(LIB_NAME)

$(LIB_NAME): bit_vector.o
	ar rcs $@ $^
	ranlib $@

bit_vector.o: bit_vector.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o

clang-format:
	clang-format -style=Google -i *.c *.h
