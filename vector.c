#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

void vector_init (vector *v) {
    v->capacity = VECTOR_START_CAPACITY;
    v->items = malloc(sizeof(void *) * v->capacity);
    v->items_count = 0;
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

    v->items[v->items_count] = item;
    v->items_count++;
}

void vector_set(vector *v, int index, void *item) {
    if (index >= 0 && index <= v->capacity) {
        v->items[index] = item;
    }
}

void vector_insert(vector *v, int index, void *item) {
    if (index < v->items_count) {
        if (v->items_count == v->capacity) {
             vector_resize(v, v->capacity * 2);
        }
        for (int i = v->items_count; i > index; --i) {
            v->items[i] = v->items[i - 1];
        }
        v->items[index] = item;
        v->items_count++;
    }
}

void vector_prepend(vector *v, void *item) {
    vector_insert(v, 0, item);
}

void *vector_get(vector *v, int index) {
    if (index >= 0 && index <= v->capacity) {
        return v->items[index];
    }

    return NULL;
}

void *vector_pop(vector *v) {
    if (v->items_count > 0) {
        void *item = v->items[v->items_count - 1];

        vector_delete(v, v->items_count - 1);

        return item;
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

void vector_remove_item(vector *v, void *item) {
    int item_index;

    while (1) {
        item_index = vector_find(v, item);

        if (item_index > -1) {
            vector_delete(v, item_index);
        } else {
            return;
        }
    }
}

int vector_find(vector *v, void *item) {
    for (int i = 0; i < v->items_count; i++) {
        if (v->items[i] == item) {
            return i;
        }
    }

    return -1;
}

void vector_free (vector *v) {
    free(v->items);
}
