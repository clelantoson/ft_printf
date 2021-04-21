/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 21:22:07 by cle-lan           #+#    #+#             */
/*   Updated: 2021/04/21 12:16:03 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*ft_deal_with_base(unsigned long long to_hexa_copy,
											int base, char *str, int count)
{
	while (to_hexa_copy != 0)
	{
		if ((to_hexa_copy % base) < 10)
			str[count - 1] = (to_hexa_copy % base) + '0';
		else
		{
			str[count - 1] = (to_hexa_copy % base) + '7';
		}
		to_hexa_copy /= base;
		count--;
	}
	return (str);
}

char					*ft_ulltoa_base(unsigned long long to_hexa, int base)
{
	char				*str;
	unsigned long long	to_hexa_copy;
	int					count;

	str = 0;
	count = 0;
	to_hexa_copy = to_hexa;
	if (to_hexa == 0)
		return (ft_strdup("0"));
	while (to_hexa != 0)
	{
		to_hexa /= base;
		count++;
	}
	if (!(str = malloc(sizeof(char) * (count + 1))))
		return (0);
	str[count] = '\0';
	str = ft_deal_with_base(to_hexa_copy, base, str, count);
	return (str);
}
