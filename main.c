#include <stdlib.h>

#include "bit_vector.h"

int main() {
  struct Vector* v = init();
  if (v == NULL) {
    fprintf(stderr, "Sorry, vector is still NULL\n");
    return EXIT_FAILURE;
  }
  delete_vector(v);
  return 0;
}

struct Vector* init() {
  struct Vector* bit_vector = (struct Vector*)malloc(sizeof(struct Vector));
  if (bit_vector == NULL) {
    fprintf(stderr, "Cannot allocate memory for bit_vector: %d", errno);
    return NULL;
  }
  return bit_vector;
}

void delete_vector(struct Vector* v) { return free(v); }
