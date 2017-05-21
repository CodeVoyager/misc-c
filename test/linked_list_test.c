#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../linked_list.c"


int main () {
    linked_list l;

    printf("------------- \n");
    printf("Push Front: \n");
    printf("------------- \n");

    init_linked_list(&l);

    linked_list_push_front(&l, 4);
    linked_list_push_front(&l, 3);
    linked_list_push_front(&l, 2);
    linked_list_push_front(&l, 1);

    int i = 0;

    while (i < linked_list_size(&l)) {
        printf("%d at position: %d\n", linked_list_value_at(&l, i), i);
        printf("=============\n");
        i++;
    }

    printf("------------- \n");
    printf("Pop Front: \n");
    printf("------------- \n");

    linked_list_pop_front(&l);

    i = 0;

    while (i < linked_list_size(&l)) {
        printf("%d at position: %d\n", linked_list_value_at(&l, i), i);
        printf("=============\n");
        i++;
    }

    printf("------------- \n");
    printf("Push Back: \n");
    printf("------------- \n");

    linked_list_push_back(&l, 888);
    linked_list_push_back(&l, 999);

    i = 0;

    while (i < linked_list_size(&l)) {
        printf("%d at position: %d\n", linked_list_value_at(&l, i), i);
        printf("=============\n");
        i++;
    }

    printf("------------- \n");
    printf("Pop Back: \n");
    printf("------------- \n");

    linked_list_pop_back(&l);
    linked_list_pop_back(&l);

    i = 0;

    while (i < linked_list_size(&l)) {
        printf("%d at position: %d\n", linked_list_value_at(&l, i), i);
        printf("=============\n");
        i++;
    }

    printf("------------- \n");
    printf("At front: \n");
    printf("------------- \n");


    printf("Value \"%d\" at front\n", linked_list_front_value(&l));

    printf("------------- \n");
    printf("At back: \n");
    printf("------------- \n");


    printf("Value \"%d\" at back\n", linked_list_back_value(&l));

    printf("------------- \n");
    printf("Insert at: \n");
    printf("------------- \n");

    linked_list_insert_at(&l, 999, 1);

    i = 0;

    while (i < linked_list_size(&l)) {
        printf("%d at position: %d\n", linked_list_value_at(&l, i), i);
        printf("=============\n");
        i++;
    }

    printf("------------- \n");
    printf("Remove at: \n");
    printf("------------- \n");

    linked_list_remove_at(&l, 1);

    i = 0;

    while (i < linked_list_size(&l)) {
        printf("%d at position: %d\n", linked_list_value_at(&l, i), i);
        printf("=============\n");
        i++;
    }

    printf("------------- \n");
    printf("At N from back: \n");
    printf("------------- \n");

    printf("Value \"%d\" at %d from back\n", linked_list_n_from_back_value(&l, 2), 2);

    printf("------------- \n");
    printf("Reverse: \n");
    printf("------------- \n");

    linked_list_reverse(&l);

    i = 0;

    while (i < linked_list_size(&l)) {
        printf("%d at position: %d\n", linked_list_value_at(&l, i), i);
        printf("=============\n");
        i++;
    }

    printf("------------- \n");
    printf("Remove value: \n");
    printf("------------- \n");

    linked_list_remove_value(&l, 3);
    linked_list_remove_value(&l, 4);
    linked_list_remove_value(&l, 999);

    i = 0;

    while (i < linked_list_size(&l)) {
        printf("%d at position: %d\n", linked_list_value_at(&l, i), i);
        printf("=============\n");
        i++;
    }

    return 0;
}