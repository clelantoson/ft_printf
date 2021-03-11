/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_count_chars.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 21:20:43 by cle-lan           #+#    #+#             */
/*   Updated: 2021/03/11 21:21:21 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_count_chars(int n, t_flags *data)
{
	unsigned int bignum;

	bignum = n;
	if (n < 0)
	{
		bignum = -bignum;
		ft_putchar_count('-', data);
	}
	if (bignum >= 10)
	{
		ft_putnbr_count_chars(bignum / 10, data);
	}
	ft_putchar_count(bignum % 10 + '0', data);
}
