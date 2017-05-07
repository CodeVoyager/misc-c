#ifndef VECTOR_H
#define VECTOR_H

#define VECTOR_START_CAPACITY 4

typedef struct vector {
    void **items;
    int capacity;
    int items_count;
} vector;

void vector_init (vector *);
void vector_add (vector *, void *);
void vector_prepend (vector *, void *);
void vector_insert (vector *, int, void *);
void *vector_pop (vector *);
void vector_set (vector *, int, void *);
void *vector_get (vector *, int);
void vector_delete (vector *, int);
void vector_remove_item (vector *, void *);
int vector_find (vector *, void *);
int vector_items_count (vector *);
int vector_capacity (vector *);
static void vector_resize (vector *, int);
void vector_free (vector *);

#endif