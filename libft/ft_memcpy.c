/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 17:35:22 by cle-lan           #+#    #+#             */
/*   Updated: 2020/12/04 17:39:35 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dstcpy;
	const char	*srccpy;

	dstcpy = (char *)dst;
	srccpy = (const char *)src;
	i = 0;
	if ((dstcpy == NULL) && (srccpy == NULL))
		return (NULL);
	while (i < n)
	{
		dstcpy[i] = srccpy[i];
		i++;
	}
	return (dst);
}
