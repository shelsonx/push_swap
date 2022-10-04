//falta adicionar o cabecalho

#include "push_swap.h"

int find_smallest_index(t_node *list)
{
    t_node  *current;
    int     smallest;
    int     smallest_index;
    int     index;

    current = list;
    smallest = list->value;
    index = 0;
    smallest_index = 0;
    while (current != NULL)
    {
        if (current->value < smallest)
        {
            smallest = current->value;
            smallest_index = index;
        }
        current = current->next;
        index++;
    }
    return (smallest_index);
}
