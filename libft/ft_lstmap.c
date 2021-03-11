/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 18:31:06 by cle-lan           #+#    #+#             */
/*   Updated: 2020/12/22 19:52:15 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *result;
	t_list *head;
	t_list *new_link;

	if (!lst)
		return (NULL);
	result = ft_lstnew(f(lst->content));
	if (!result)
		return (0);
	head = result;
	lst = lst->next;
	while (lst)
	{
		new_link = ft_lstnew(f(lst->content));
		result->next = new_link;
		if (!result->next)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		result = result->next;
		lst = lst->next;
	}
	result->next = NULL;
	return (head);
}
