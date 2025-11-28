#ifndef MY_MINI_VECTOR_H__
#define MY_MINI_VECTOR_H__

#include <stddef.h> // size_t

typedef struct Vector {
    unsigned int* data;
    size_t size;
    size_t capacity;
} Vector_t;

// Initialisierung und Freigabe
void vector_init(Vector_t* vec);
void vector_clear(Vector_t* vec);

// Einfügen
int vector_push_back(Vector_t* vec, unsigned int value);

// Zugriff
int vector_get(const Vector_t* vec, size_t index, unsigned int* outValue);

// Ausgabe
void vector_print(const Vector_t* vec);

#endif
