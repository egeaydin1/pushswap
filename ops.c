#include "push_swap.h"

void sa(t_list **a)
{
    t_list *first;
    t_list *second;

    if (!a || !*a || !(*a)->next)
        return;

    first = *a;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *a = second;
    ft_printf("sa\n");
}
void sb(t_list **b)
{
    t_list *first;
    t_list *second;

    if (!b || !*b || !(*b)->next)
        return;

    first = *b;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *b = second;
    ft_printf("sb\n");
}
void pa(t_list **a, t_list **b)
{
    t_list *temp;

    if (!b || !*b)
        return;
    
    temp = *b;
    *b = (*b)->next;
    temp->next = NULL;
    ft_lstadd_front(a, temp);
}