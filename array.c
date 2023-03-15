#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Array CreateArray(size_t element_size) {
  struct Array array;
  array.element_size = element_size;
  array.capacity = 1;
  array.used = 0;
  array.elements = malloc(array.capacity * array.element_size);
  return array;
}

void PushArray(struct Array *array, void *element) {
  if (array->used == array->capacity) {
    array->capacity *= 2;
    array->elements =
        realloc(array->elements, array->capacity * array->element_size);
  }
  memcpy(array->elements + (array->used * array->element_size), element,
         array->element_size);
  array->used++;
}

void *GetElementArray(struct Array *array, int index) {
  return (array->elements + (array->element_size * index));
}

void *PopArray(struct Array *array) {
  if (array->used == 0) {
    return 0;
  }
  size_t last_element_offset = array->element_size * (array->used - 1);
  return array->elements + last_element_offset;
}
