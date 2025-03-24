#ifndef BIT_VECTOR
#define BIT_VECTOR

#include <errno.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct Vector {
  uint32_t* array;
  size_t size;
};

struct Vector* init();
void delete_vector(struct Vector* v);
#endif  // !BIT_VECTOR
