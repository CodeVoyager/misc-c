#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

void vector_init (vector *v) {
    v->capacity = VECTOR_START_CAPACITY;
    v->items = malloc(sizeof(void *) * v->capacity);
    v->items_count = -1;
}

int vector_items_count (vector *v) {
    return v->items_count;
}

int vector_capacity (vector *v) {
    return v->capacity;
}

void vector_resize (vector *v, int capacity) {
    void **items = realloc(v->items, sizeof(void *) * capacity);

    if (items) {
        v->capacity = capacity;
        v->items = items;
    }
}

void vector_add (vector *v, void *item) {
    if (v->capacity == v->items_count) {
        vector_resize(v, v->capacity * 2);
    }

    v->items[++v->items_count] = item;
}

void vector_set(vector *v, int index, void *item) {
    if (index >= 0 && index <= v->capacity) {
        v->items[index] = item;
    }
}

void *vector_get(vector *v, int index) {
    if (index >= 0 && index <= v->capacity) {
        return v->items[index];
    }

    return NULL;
}

void vector_delete(vector *v, int index) {
    if (index < 0 || index > v->capacity) {
        return;
    }

    v->items[index] = NULL;

    for (int i = index; i < v->items_count; ++i) {
        v->items[i] = v->items[i + 1];
        v->items[i + 1] = NULL;
    }

    v->items_count--;

    if (v->items_count > 0 && v->items_count == v->capacity / 4) {
        vector_resize(v, v->capacity / 2);
    }
}

void vector_free (vector *v) {
    free(v->items);
}
