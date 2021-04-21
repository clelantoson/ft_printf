/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_with_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:08:41 by cle-lan           #+#    #+#             */
/*   Updated: 2021/04/21 12:08:53 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_deal_with_char(char c, t_flags *data)
{
	if (data->minus == 0)
	{
		ft_deal_with_width(data, 1);
		ft_putchar_count(c, data);
	}
	else if (data->minus == 1)
	{
		ft_putchar_count(c, data);
		ft_deal_with_width(data, 1);
		data->minus = 0;
	}
}
