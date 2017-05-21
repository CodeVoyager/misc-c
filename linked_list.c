#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct linked_list_node {
    struct linked_list_node *next;
    int data;
} linked_list_node;

typedef struct linked_list {
    struct linked_list_node *head;
    struct linked_list_node *tail;
    unsigned int size;
} linked_list;

void init_linked_list(linked_list *l) {
    l->size = 0;
    l->head = NULL;
    l->tail = NULL;
}

int linked_list_size(linked_list *l) {
    return l->size;
}

bool linked_list_is_empty(linked_list *l) {
    if (l->head == NULL) {
        return true;
    }

    return false;
}

int linked_list_value_at(linked_list *l, int i) {
    int _index = 0;
    linked_list_node *node;

    if (l->size < i) {
        return NULL;
    }

    if (l->head == NULL) {
        return NULL;
    } else {
        node = l->head;
    }

    while (_index < i) {
        node = node->next;
        ++_index;
    }

    return node->data;
}

void linked_list_push_front(linked_list *l, int d) {
    linked_list_node *n = malloc(sizeof(linked_list_node));
    n->data = d;
    n->next = NULL;
    l->size++;

    if (l->head == NULL) {
        l->head = n;
    }

    if (l->tail == NULL) {
        l->tail = n;
    }

    if (l->head != n) {
        n->next = l->head;
        l->head = n;
    }
}

int linked_list_pop_front(linked_list *l) {
    if (l->head == NULL) {
        return NULL;
    }

    int return_value = l->head->data;
    linked_list_node *h = l->head;

    l->head = l->head->next;
    l->size--;

    if (l->size == 0) {
        l->tail = NULL;
    }

    free(h);

    return return_value;
}

void linked_list_push_back(linked_list *l, int d) {
    linked_list_node *n = malloc(sizeof(linked_list_node));
    n->data = d;
    n->next = NULL;

    if (l->size == 0) {
        l->head = n;
        l->tail = n;
    }

    if (l->tail != n) {
        l->tail->next = n;
        l->tail = n;
    }

    l->size++;
}

int linked_list_pop_back(linked_list *l) {
    if (l->tail == NULL) {
        return NULL;
    }

    int return_value = l->tail->data;
    linked_list_node *t = l->tail;
    linked_list_node *h = l->head;

    if (t == h) {
        l->head = NULL;
    } else {
        while (h->next != t) {
            h = h->next;
        }

        h->next = NULL;
        l->tail = h;
    }

    l->size--;
    free(t);

    return return_value;
}

int linked_list_front_value(linked_list *l) {
    if (l->head == NULL) {
        return NULL;
    }

    return l->head->data;
}

int linked_list_back_value(linked_list *l) {
    if (l->tail == NULL) {
        return NULL;
    }

    return l->tail->data;
}

void linked_list_insert_at(linked_list *l, int d, int i) {
    if (l->size <= i) {
        if (l->size == 0 && i == 0) {
            linked_list_push_front(l, d);
        }
        return;
    }

    linked_list_node *n = malloc(sizeof(linked_list_node));
    linked_list_node *a = l->head;
    int p = 0;
    n->data = d;

    while (p < i - 1) {
        a = a->next;
        ++p;
    }

    if (a->next == NULL) {
        a->next = n;
        n->next = NULL;
        l->tail = n;
    } else {
        n->next = a->next;
        a->next = n;
    }

    l->size++;
}

void linked_list_remove_at(linked_list *l, int i) {
    if (l->head == NULL) {
        return;
    }

    if (l->size <= i) {
        return;
    }

    linked_list_node *n = l->head;
    linked_list_node *_n;

    while (--i > 0) {
        n = n->next;
    }

    if (n->next == l->tail) {
        n->next = NULL;
        l->tail = n;
        free(n->next);
    } else {
        _n = n->next;
        n->next = n->next->next;
        free(_n);
    }

    l->size--;
}

int linked_list_n_from_back_value(linked_list *l, int i) {
    if (l->size - i < 0) {
        return NULL;
    }

    return linked_list_value_at(l, (l->size - i));
}

void linked_list_reverse(linked_list *l) {
    if (l->size == 0 || l->size == 1) {
        return;
    }

    linked_list_node *head = l->head;
    linked_list_node *tail = l->tail;
    linked_list_node *node = l->head;
    linked_list_node *next;
    linked_list_node *new_head = NULL;

    while (node) {
        next = node->next;
        node->next = new_head;
        new_head = node;
        node = next;
    }

    l->head = new_head;
}

void linked_list_remove_value(linked_list *l, int d) {
    linked_list_node *n = l->head;
    linked_list_node *next;
    linked_list_node *p = NULL;
    int i = 0;

    while (n) {
        if (n->data == d) {
            next = n->next;

            if (p) {
                p->next = next;
            } else {
                l->head = next;
            }

            free(n);
            l->size--;
            return;
        }

        p = n;
        n = n->next;
    }
}