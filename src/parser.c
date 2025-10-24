/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeaydin <egeaydin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:08:52 by egeaydin          #+#    #+#             */
/*   Updated: 2025/10/24 18:51:51 by egeaydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_char(char c)
{
	if (c == ' ' || c == '+' || c == '-' || (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

void	is_valid_arguments(char **av, int ac)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!is_valid_char(av[i][j]))
				ft_error_exit("Error");
			j++;
		}
		i++;
	}
}

void	split_and_parse(char **av, t_list **a, int ac)
{
	char	**ar_splited;
	t_list	*new_node;
	int		i;
	int		j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		ar_splited = ft_split(av[i], 32);
		while (ar_splited[j] != NULL)
		{
			new_node = ft_lstnew(ft_atoi(ar_splited[j]));
			if (!new_node)
			{
				ft_free(a);
				return ;
			}
			ft_lstadd_back(a, new_node);
			free(ar_splited[j]);
			j++;
		}
		free(ar_splited);
		i++;
	}
}

void	has_duplicates(t_list *a)
{
	t_list	*i;
	t_list	*j;

	j = a;
	while (j)
	{
		i = j->next;
		while (i)
		{
			if (i->value == j->value)
			{
				ft_lstclear(a);
				ft_error_exit("Error");
			}
			i = i->next;
		}
		j = j->next;
	}
}

void	parser_main(t_list **a, int ac, char **av)
{
	if (ac <= 1)
		ft_error_exit("Error");
	is_valid_arguments(av, ac);
	split_and_parse(av, a, ac);
	has_duplicates(*a);
	ft_printf("Stack A:\n");
	print_stack(a);
}
// int max-min sinirlarini test et
