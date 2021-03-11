/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:02:19 by cle-lan           #+#    #+#             */
/*   Updated: 2020/12/18 14:42:41 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*copycount;

	copycount = (char *)malloc(count * size);
	if (copycount == NULL)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		copycount[i] = '\0';
		i++;
	}
	return (copycount);
}
