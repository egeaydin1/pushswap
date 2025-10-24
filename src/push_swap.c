/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeaydin <egeaydin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:08:55 by egeaydin          #+#    #+#             */
/*   Updated: 2025/10/24 20:29:02 by egeaydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list		*a;
	//t_list	*b;

	a = NULL;
	//b = NULL;
	parser_main(&a, ac, av);
	if (not_sorted(a))
	{
		//get_index();
		//sort();
		ft_printf("sirali degil\n");
		return (1);
	}
	ft_printf("sirali\n");

	ft_lstclear(a);
	return (1);
}
