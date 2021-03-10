/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_with_ptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:51:10 by cle-lan           #+#    #+#             */
/*   Updated: 2021/03/11 00:39:29 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_deal_with_ptr(unsigned long long to_pointer, t_flags *data)
{
	char	*pointer;
	int i;
	int count;

	i = 0;
	count = 0;
	pointer = ft_ulltoa_base(to_pointer, 16);
	pointer = ft_tolower(pointer);
	ft_putstr("0x", data);
	while (pointer[i])
	{
		ft_putchar(pointer[i], data);
		i++;
	}
}
