#include <stdlib.h>
#include <stdio.h>

#include "../vector.c"

int main () {
    vector v;
    vector v2;

    printf("------------- \n");
    printf("Add: \n");
    printf("------------- \n");

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

    printf("------------- \n");
    printf("Add (strings): \n");
    printf("------------- \n");

    vector_init(&v2);
    vector_add(&v2, "a");
    vector_add(&v2, "b");
    vector_add(&v2, "c");
    vector_add(&v2, "d");
    vector_add(&v2, "e");
    vector_add(&v2, "f");
    vector_add(&v2, "g");
    vector_set(&v2, 6, "x");

    printf("%s\n", vector_get(&v2, 0));
    printf("%s\n", vector_get(&v2, 4));
    printf("%s\n", vector_get(&v2, 6));

    printf("Capacity: %d\n", vector_capacity(&v2));
    printf("Size: %d\n", vector_items_count(&v2));

    printf("------------- \n");
    printf("Delete: \n");
    printf("------------- \n");

    vector_delete(&v2, 1);
    vector_delete(&v2, 1);
    vector_delete(&v2, 1);
    vector_delete(&v2, 1);
    vector_delete(&v2, 1);

    printf("Capacity: %d\n", vector_capacity(&v2));
    printf("Size: %d\n", vector_items_count(&v2));

    printf("------------- \n");
    printf("Delete (2): \n");
    printf("------------- \n");

    vector_delete(&v2, 1);

    printf("Capacity: %d\n", vector_capacity(&v2));
    printf("Size: %d\n", vector_items_count(&v2));

    printf("------------- \n");
    printf("Insert: \n");
    printf("------------- \n");

    printf("%s\n", vector_get(&v2, 0));

    printf("------------- \n");
    printf("------------- \n");

    vector_insert(&v2, 0, "i");
    vector_insert(&v2, 0, "i");

    printf("%s\n", vector_get(&v2, 0));
    printf("%s\n", vector_get(&v2, 1));
    printf("%s\n", vector_get(&v2, 2));

    printf("Capacity: %d\n", vector_capacity(&v2));
    printf("Size: %d\n", vector_items_count(&v2));

    printf("------------- \n");
    printf("Prepend: \n");
    printf("------------- \n");

    vector_prepend(&v2, "p");
    vector_prepend(&v2, "o");
    vector_prepend(&v2, "n");

    printf("%s\n", vector_get(&v2, 0));
    printf("%s\n", vector_get(&v2, 1));
    printf("%s\n", vector_get(&v2, 2));
    printf("%s\n", vector_get(&v2, 3));
    printf("%s\n", vector_get(&v2, 4));
    printf("%s\n", vector_get(&v2, 5));

    printf("Capacity: %d\n", vector_capacity(&v2));
    printf("Size: %d\n", vector_items_count(&v2));

    printf("------------- \n");
    printf("Pop: \n");
    printf("------------- \n");

    printf("%s\n", vector_get(&v2, 0));
    printf("%s\n", vector_get(&v2, 1));
    printf("%s\n", vector_get(&v2, 2));
    printf("%s\n", vector_get(&v2, 3));
    printf("%s\n", vector_get(&v2, 4));
    printf("%s\n", vector_get(&v2, 5));
    printf("%s\n", vector_pop(&v2));
    printf("%s\n", vector_pop(&v2));
    printf("%s\n", vector_pop(&v2));
    printf("%s\n", vector_pop(&v2));
    printf("%s\n", vector_pop(&v2));
    printf("%s\n", vector_pop(&v2));

    printf("Capacity: %d\n", vector_capacity(&v2));
    printf("Size: %d\n", vector_items_count(&v2));

    printf("------------- \n");
    printf("Find item: \n");
    printf("------------- \n");

    vector_add(&v2, "a");
    vector_add(&v2, "a");
    vector_add(&v2, "x");

    printf("%d\n", vector_find(&v2, "x"));

    vector_pop(&v2);
    vector_pop(&v2);
    vector_pop(&v2);

    printf("------------- \n");
    printf("Remove item: \n");
    printf("------------- \n");

    vector_add(&v2, "a");
    vector_add(&v2, "a");
    vector_add(&v2, "x");
    vector_add(&v2, "a");
    vector_add(&v2, "a");

    printf("%s\n", vector_get(&v2, 0));
    printf("%s\n", vector_get(&v2, 1));
    printf("%s\n", vector_get(&v2, 2));

    printf("Capacity: %d\n", vector_capacity(&v2));
    printf("Size: %d\n", vector_items_count(&v2));

    vector_remove_item(&v2, "a");

    printf("%s\n", vector_get(&v2, 0));

    printf("Capacity: %d\n", vector_capacity(&v2));
    printf("Size: %d\n", vector_items_count(&v2));

    vector_free(&v2);

    return 0;
}