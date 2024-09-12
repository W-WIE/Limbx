#include "libmx.h"

void mx_pop_back(t_list **head) {
    if (head == NULL || *head == NULL) {
        return;
    }

    t_list *current = *head;
    t_list *previous = NULL;

    if (current->next == NULL) {
        free(current);
        *head = NULL;
        return;
    }

    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }

    previous->next = NULL;
    free(current);
}
