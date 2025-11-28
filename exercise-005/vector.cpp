#include "vector.hpp"

#include <stdlib.h>
#include <stdio.h>
#include <fmt/format.h>

// Initialisierung
void vector_init(Vector_t* vec) {
    if (!vec) return;
    vec->size = 0;
    vec->capacity = 4;
    vec->data = (unsigned int*)malloc(vec->capacity * sizeof(unsigned int));
}

// Freigabe
void vector_clear(Vector_t* vec) {
    if (!vec) return;
    if (vec->data) free(vec->data);
    vec->data = NULL;
    vec->size = 0;
    vec->capacity = 0;
}

// Einfügen am Ende
int vector_push_back(Vector_t* vec, unsigned int value) {
    if (!vec) return -1;

    // Kapazität prüfen
    if (vec->size >= vec->capacity) {
        size_t new_capacity = vec->capacity * 2;
        unsigned int* new_data = (unsigned int*)realloc(vec->data, new_capacity * sizeof(unsigned int));
        if (!new_data) return -1; // Speicherfehler
        vec->data = new_data;
        vec->capacity = new_capacity;
    }

    vec->data[vec->size] = value;
    vec->size++;
    return 0; // Erfolg
}

// Zugriff per Index
int vector_get(const Vector_t* vec, size_t index, unsigned int* outValue) {
    if (!vec || !outValue) return -1;
    if (index >= vec->size) return -1;
    *outValue = vec->data[index];
    return 0;
}

// Ausgabe
void vector_print(const Vector_t* vec) {
    if (!vec || !vec->data) return;

    for (size_t i = 0; i < vec->size; i++) {
        fmt::print("{} ", vec->data[i]);
    }
    fmt::println("");
}
