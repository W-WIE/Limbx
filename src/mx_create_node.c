#include "libmx.h"

t_list *mx_create_node(void *data) {
    t_list *new_node = (t_list *)calloc(1, sizeof(t_list));
    if (new_node == NULL) {
        return NULL;  
    }

    new_node->data = data;  
    return new_node;
}
