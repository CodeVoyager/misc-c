#include <stdlib.h>
#include <stdio.h>

#include "vector.c"

int main () {
    vector v;
    vector v2;

    vector_init(&v);
    vector_add(&v, 1);
    vector_add(&v, 2);
    vector_add(&v, 3);
    vector_add(&v, 4);

    printf("%d\n", vector_get(&v, 1));
    printf("%d\n", vector_get(&v, 2));
    printf("%d\n", vector_get(&v, 3));
    printf("Capacity: %d\n", vector_capacity(&v));

    vector_free(&v);

    vector_init(&v2);
    vector_add(&v2, "a");
    vector_add(&v2, "b");
    vector_add(&v2, "c");
    vector_add(&v2, "d");
    vector_add(&v2, "e");
    vector_add(&v2, "f");
    vector_add(&v2, "g");

    printf("%s\n", vector_get(&v2, 0));
    printf("%s\n", vector_get(&v2, 4));
    printf("%s\n", vector_get(&v2, 6));
    printf("Capacity: %d\n", vector_capacity(&v2));

    vector_free(&v2);

    return 0;
}