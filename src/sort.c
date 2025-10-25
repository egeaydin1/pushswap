/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeaydin <egeaydin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:02:15 by egeaydin          #+#    #+#             */
/*   Updated: 2025/10/25 11:48:14 by egeaydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void sort_two(t_list **a)
{
    int one;
    int two;

	one = (*a)->value;
    two = (*a)->next->value;
	
	if (one > two)
		sa(a);	
}
void sort_three(t_list **a)
{
    int one;
    int two;
    int three;

    one = (*a)->value;
    two = (*a)->next->value;
    three = (*a)->next->next->value;
    
    if (one > two && two > three)
    {
        sa(a);
        rotate(a,"rra");
    }
	else if (one > two && two < three && one > three)
		rotate(a,"ra");
	else if (one < two && two > three && one > three)
		rotate(a,"rra");
	else if (one > two && two < three)
		sa(a);
    else
    {
        sa(a);
        rotate(a,"ra");
	}
}

void sort(t_list **a)
{
	int	size;
	
	size = ft_lstsize(*a);
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size < 8)
		
	
	
}