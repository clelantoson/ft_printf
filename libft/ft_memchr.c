/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 16:47:46 by cle-lan           #+#    #+#             */
/*   Updated: 2020/12/04 17:39:04 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*copys;

	copys = (unsigned char *)s;
	i = 0;
	while (n > i)
	{
		if (copys[i] == (unsigned char)c)
			return (&copys[i]);
		i++;
	}
	return (NULL);
}
