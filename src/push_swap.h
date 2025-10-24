/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeaydin <egeaydin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:14:26 by egeaydin          #+#    #+#             */
/*   Updated: 2025/10/24 21:20:10 by egeaydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

void	parser_main(t_list **a, int ac, char **av);
void	ft_free_split(char **arr);
void	ft_error_exit(char *msg);
int		not_sorted(t_list *a);
void	print_stack(t_list **head);

#endif