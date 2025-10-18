/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hientranpc <hientranpc@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:50:02 by egeaydin          #+#    #+#             */
/*   Updated: 2025/09/30 23:10:12 by hientranpc       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int(*f)(int), void (*del)(int))
{
	t_list	*lstnew;
	t_list	*newcontent;
	int	content;

	lstnew = NULL;
	while (lst != NULL)
	{
		content = (*f)(lst->content);
		newcontent = ft_lstnew(content);
		if (newcontent == NULL)
		{
			del(content);
			ft_lstclear(&lstnew, del);
			return (NULL);
		}
		ft_lstadd_back(&lstnew, newcontent);
		lst = lst->next;
	}
	return (lstnew);
}
