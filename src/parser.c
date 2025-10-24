/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeaydin <egeaydin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:08:52 by egeaydin          #+#    #+#             */
/*   Updated: 2025/10/24 21:16:47 by egeaydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			if (!(av[i][j] == ' ' || av[i][j] == '+' || av[i][j] == '-'
				|| (av[i][j] >= '0' && av[i][j] <= '9')))
				ft_error_exit("Error");
			j++;
		}
		i++;
	}
}

void	split_and_parse(char **av, t_list **a, int ac)
{
	t_list	*new_node;
	int		i;
	char	**args_splited;

	i = 0;
	if (ac > 2)
		args_splited = av + 1;
	else
		args_splited = ft_split(av[1], ' ');
	while (args_splited[i])
	{
		new_node = ft_lstnew(ft_atoi(args_splited[i]));
		if (!new_node)
		{
			ft_lstclear(a);
			return ;
		}
		ft_lstadd_back(a, new_node);
		ft_lstdelone(new_node);
		i++;
	}
	if (ac == 2)
		ft_free_split(args_splited);
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
				ft_lstclear(&a);
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
