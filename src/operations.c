/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeaydin <egeaydin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:51:59 by egeaydin          #+#    #+#             */
/*   Updated: 2025/10/24 18:57:46 by egeaydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **a)
{
	t_list	*first;
	t_list	*second;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*a = second;
	ft_printf("sa\n");
}

void	push(t_list **target_stack, t_list **source_stack, char *opname)
{
	t_list	*temp;

	if (!source_stack || !*source_stack || !target_stack)
		return ;
	temp = *source_stack;
	*source_stack = (*source_stack)->next;
	temp->next = NULL;
	ft_lstadd_front(target_stack, temp);
	if (ft_strncmp(opname, "pa", 3) == 0)
		ft_printf("pa\n");
	else if (ft_strncmp(opname, "pb", 3) == 0)
		ft_printf("pb\n");
}

void	rotate(t_list **a, char *opname)
{
	t_list	*temp;
	t_list	*last;

	temp = *a;
	if (!a || !*a || !(*a)->next)
		return ;
	if (ft_strncmp(opname, "ra", 5) == 0)
	{
		*a = (*a)->next;
		temp->next = NULL;
		ft_lstadd_back(a, temp);
		ft_printf("ra\n");
	}
	else if (ft_strncmp(opname, "rra", 5) == 0)
	{
		while (temp->next->next)
			temp = temp->next;
		last = temp->next;
		temp->next = NULL;
		ft_lstadd_front(a, last);
		ft_printf("rra\n");
	}
}
