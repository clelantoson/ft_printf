/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 11:14:19 by cle-lan           #+#    #+#             */
/*   Updated: 2020/12/15 15:32:24 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char			*ft_itoa(int n)
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
