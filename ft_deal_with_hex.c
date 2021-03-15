/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_with_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 20:58:39 by cle-lan           #+#    #+#             */
/*   Updated: 2021/03/15 14:31:30 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_deal_with_hex(unsigned int to_hexa, int to_lower, t_flags *data)
{
	char	*hexa;
	int i;

	i = 0;
	hexa = ft_ulltoa_base((unsigned long long)to_hexa, 16);
	if (to_lower == 1)
		hexa = ft_str_tolower(hexa);
	while (hexa[i])
	{
		ft_putchar_count(hexa[i], data);
		i++;
	}
}

