/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:37:28 by cle-lan           #+#    #+#             */
/*   Updated: 2020/12/15 15:51:26 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	char	*scpy;

	i = 0;
	scpy = (char *)s;
	if (*to_find == 0)
		return (scpy);
	while (scpy[i] && i < len)
	{
		j = 0;
		while (scpy[i + j] == to_find[j] && i + j < len)
		{
			j++;
			if (to_find[j] == 0)
				return (&scpy[i]);
		}
		i++;
	}
	return (0);
}
