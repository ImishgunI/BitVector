#include "bit_vector.h"

static void print_vector(struct Vector* v);

int main() {
  size_t size = 0;
  printf("Enter size for vector: ");
  scanf("%ld", &size);
  struct Vector* v = init(size);
  if (v == NULL) {
    fprintf(stderr, "Sorry, vector is still NULL\n");
    return EXIT_FAILURE;
  }
  uint32_t index = 0;
  printf("Enter index you want set bit: ");
  scanf("%u", &index);
  set_bit(v, index);
  print_vector(v);
  delete_vector(v);
  return EXIT_SUCCESS;
}

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

static void print_vector(struct Vector* v) {
  for (size_t i = 0; i < v->size; i++) {
    printf("%u ", v->array[i]);
  }
}
