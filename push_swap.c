/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hientranpc <hientranpc@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:08:55 by egeaydin          #+#    #+#             */
/*   Updated: 2025/10/19 16:49:25 by hientranpc       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void error(void)
{
	ft_printf("Error\n");
	exit(1);
}

int	main(int ac, char **av)
{
	t_list	*a;
	//t_list	*b;

	a = NULL;
	//b = NULL;
	if (!parser_main(&a, ac, av))
		error();
}
