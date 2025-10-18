/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hientranpc <hientranpc@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:08:52 by egeaydin          #+#    #+#             */
/*   Updated: 2025/10/18 21:54:06 by hientranpc       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_free(t_list **head)
{
	t_list	*tmp;

	while (*head)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
	return(0);
}
int is_valid_char(char c)
{
	if (c == ' ' || c == '+' || c == '-' || (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

int is_valid_arguments(char **av, int ac)
{
	int i;
	int j;
	
	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!is_valid_char(av[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
int	split_and_parse(char **av, t_list **a,int ac)
{
	char	**ar_splited;
	t_list	*new_node;
	int	i;
	int	j;
	
	i = 1;
	while (i < ac)
	{
		j = 0;
		ar_splited = ft_split(av[i], 32);
		while (ar_splited[j] != NULL)
		{
			new_node = ft_lstnew(ft_atoi(ar_splited[j]));
			if (!new_node)
				return (ft_free(a));
			ft_lstadd_back(a,new_node);
			free(ar_splited[j]);
			j++;
		}
		free(ar_splited);
		i++;
	}
	return 1;
}
int has_duplicates(t_list *a)
{
	t_list *i;
	t_list *j;
	
	j = a;
	while (j)
	{
		i = j->next;
		while (i)
		{
				if (i->content == j->content)
				{
					ft_lstclear(&a,free);
					return (1);
				}
			i = i->next;
		}
		j = j->next;
	}
	return (0);
}
void	print_stack(t_list **head)
{
	t_list	*start;

	if (!head || !*head)
		return ;
	start = *head;
	while (start != NULL)
	{
		ft_printf("%d\n", start->content);
		start = start->next;
	}
}

int	parser_main(t_list **a, int ac, char **av)
{
	if (ac <= 1)
		return (0);
	if (!is_valid_arguments(av,ac))
		return (0);
	if (!split_and_parse(av, a, ac))
		return (0);
	if (has_duplicates(*a))
		return (0);
	ft_printf("Stack A:\n");
	print_stack(a);	
	return (1);
}
// int max-min sinirlarini test et

