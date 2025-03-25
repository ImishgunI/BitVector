#include "bit_vector.h"

int main() {
  size_t size = 0;
  scanf("%ld", &size);
  struct Vector* v = init(size);
  if (v == NULL) {
    fprintf(stderr, "Sorry, vector is still NULL\n");
    return EXIT_FAILURE;
  }
  delete_vector(v);
  return EXIT_SUCCESS;
}

struct Vector* init(size_t size) {
  struct Vector* bit_vector = (struct Vector*)malloc(sizeof(struct Vector));
  if (!bit_vector) {
    fprintf(stderr, "Cannot allocate memory for bit_vector: %d", errno);
    return NULL;
  }
  bit_vector->array = (uint32_t*)malloc(sizeof(uint32_t) * size);
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
