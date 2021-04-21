/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_with_width.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 20:50:05 by cle-lan           #+#    #+#             */
/*   Updated: 2021/04/21 12:11:53 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_deal_with_width(t_flags *data, int len)
{
	while (data->width - len > 0)
	{
		if (data->zero == 1)
			ft_putchar_count('0', data);
		else
			ft_putchar_count(' ', data);
		data->width--;
	}
	data->width = 0;
}
