#ifndef BIT_VECTOR
#define BIT_VECTOR

#include <errno.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Vector {
  uint32_t* array;
  size_t size;
};

struct Vector* init(size_t size);
void delete_vector(struct Vector* v);
void set_bit(struct Vector* vector, uint32_t index);
void clear_bit(struct Vector* vector, uint32_t index);
void toggle_bit(struct Vector* vector, uint32_t index);
uint32_t get_bit(struct Vector vector, uint32_t index);
#endif  // !BIT_VECTOR
