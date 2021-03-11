/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:41:24 by cle-lan           #+#    #+#             */
/*   Updated: 2020/12/15 15:37:27 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int bignum;

	bignum = n;
	if (n < 0)
	{
		bignum = -bignum;
		ft_putchar_fd('-', fd);
	}
	if (bignum >= 10)
		ft_putnbr_fd(bignum / 10, fd);
	ft_putchar_fd(bignum % 10 + '0', fd);
}
