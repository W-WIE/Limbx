#include "libmx.h"

static void swap_data(t_list *a, t_list *b) {
    void *temp = a->data;
    a->data = b->data;
    b->data = temp;
}

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
    if (!lst || !lst->next || !cmp) {
        return lst;
    }

    bool swapped;
    t_list *current;
    t_list *last_sorted = NULL;

    do {
        swapped = false;
        current = lst;

        while (current->next != last_sorted) {
            if (cmp(current->data, current->next->data)) {
                swap_data(current, current->next);
                swapped = true;
            }
            current = current->next;
        }

        last_sorted = current;
    } while (swapped);

    return lst;
}
