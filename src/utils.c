/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeaydin <egeaydin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:48:23 by egeaydin          #+#    #+#             */
/*   Updated: 2025/10/24 19:17:15 by egeaydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_free(t_list **head)
{
	t_list	*tmp;

	while (*head)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
	return (0);
}

void	ft_error_exit(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(1);
}

int	not_sorted(t_list *a)
{
	int	prev;

	if (!a)
		return (0);
	prev = a->value;
	a = a->next;
	while (a)
	{
		if (prev > a->value)
			return (1);
		prev = a->value;
		a = a->next;
	}
	return (0);
}
// asaası silinecekk !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

void	print_stack(t_list **head)
{
	t_list	*start;

	if (!head || !*head)
		return ;
	start = *head;
	while (start != NULL)
	{
		ft_printf("%d\n", start->value);
		start = start->next;
	}
}
