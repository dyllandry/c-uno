#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#include <stddef.h>

struct Array {
  void *elements;
  size_t element_size;
  size_t used;
  size_t capacity;
};

struct Array CreateArray(size_t element_size);
void PushArray(struct Array *array, void *element);
void *GetElementArray(struct Array *array, size_t element);

#endif
