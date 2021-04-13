/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_with_pc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 18:56:37 by cle-lan           #+#    #+#             */
/*   Updated: 2021/04/13 23:26:01 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_deal_with_pc(t_flags *data)
{
	if (data->zero == 1 && data->minus == 1)
		data->zero = 0;
	if (data->width > 0)
	{
		if (data->minus == 0)
		{
			ft_deal_with_width(data, 1);
			ft_putchar_count('%', data);
		}
		else if (data->minus == 1)
		{
			ft_putchar_count('%', data);
			ft_deal_with_width(data, 1);
		}
	}
	else
		ft_putchar_count('%', data);
}
