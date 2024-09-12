#include "libmx.h"

void mx_push_back(t_list **list, void *data) {
    if (!list) return;  
    t_list *new_node = mx_create_node(data);
    if (!new_node) return;  

    if (*list == NULL) {
        *list = new_node;
    } else {
        t_list *temp = *list;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}
