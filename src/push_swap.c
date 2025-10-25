/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeaydin <egeaydin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:08:55 by egeaydin          #+#    #+#             */
/*   Updated: 2025/10/25 11:46:57 by egeaydin         ###   ########.fr       */
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
		ft_printf("sirali degil\n");
		sort(&a);
		if (!not_sorted(a))
	{
		print_stack(&a);
		ft_printf("siralandi\n");
	}
	}
	else
		ft_printf("zaten sirali\n");
	
	ft_lstclear(&a);
	return (1);
}
