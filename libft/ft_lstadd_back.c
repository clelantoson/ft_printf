/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 17:33:24 by cle-lan           #+#    #+#             */
/*   Updated: 2020/12/18 09:06:28 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **firstlst, t_list *new)
{
	t_list *last_elmt;

	if (*firstlst == NULL)
	{
		*firstlst = new;
		return ;
	}
	last_elmt = ft_lstlast(*firstlst);
	last_elmt->next = new;
}
