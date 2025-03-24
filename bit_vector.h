#ifndef BIT_VECTOR
#define BIT_VECTOR

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

struct Vector{
  uint32_t* array;
  size_t size;
};

struct Vector* init();

#endif // !BIT_VECTOR
