#include "bit_vector.h"

struct Vector* init(size_t size) {
  struct Vector* bit_vector = (struct Vector*)malloc(sizeof(struct Vector));
  if (!bit_vector) {
    fprintf(stderr, "Cannot allocate memory for bit_vector: %d", errno);
    return NULL;
  }
  bit_vector->array = (uint32_t*)calloc(size, sizeof(uint32_t));
  if (!bit_vector->array) {
    fprintf(stderr, "Cannot allocate memory for array in bit_vector: %d",
            errno);
    delete_vector(bit_vector);
    return NULL;
  }
  bit_vector->size = size;
  return bit_vector;
}

void delete_vector(struct Vector* v) {
  if (v->array) {
    free(v->array);
  }
  free(v);
}

void set_bit(struct Vector* vector, uint32_t index) {
  uint32_t array_index = index / 32;
  uint32_t bit = index % 32;
  vector->array[array_index] |= 1 << bit;
}

void clear_bit(struct Vector* vector, uint32_t index) {
  uint32_t array_index = index / 32;
  uint32_t bit = index % 32;
  vector->array[array_index] &= bit;
}

void toggle_bit(struct Vector *vector, uint32_t index) {
    uint32_t array_index = index / 32;
    if(vector->array[array_index] != 0) {
        clear_bit(vector, index);
    } else {
        set_bit(vector, index);
    }
}

uint32_t get_bit(struct Vector vector, uint32_t index) {
    uint32_t array_index = index / 32;
    return vector.array[array_index];
}
