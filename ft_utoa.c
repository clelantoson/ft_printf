/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 11:14:19 by cle-lan           #+#    #+#             */
/*   Updated: 2021/04/13 18:17:51 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_len(long int n)
{
	int len;

	len = 0;
	if (n <= 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char			*ft_utoa(unsigned int n)
{
	char		*str;
	long int	bignum;
	int			len;

	bignum = n;
	len = ft_len(bignum);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len] = 0;
	if (bignum < 0)
		bignum = -bignum;
	if (bignum >= 0)
	{
		while (len > 0)
		{
			str[--len] = bignum % 10 + '0';
			bignum = bignum / 10;
		}
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
