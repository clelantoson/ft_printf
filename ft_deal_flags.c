/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 11:26:30 by cle-lan           #+#    #+#             */
/*   Updated: 2021/04/21 12:05:27 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_is_star(t_flags *data, va_list args)
{
	data->star = 1;
	data->width = va_arg(args, int);
	if (data->width < 0)
	{
		data->width *= -1;
		data->minus = 1;
		if (data->zero == 1 && data->minus == 1)
			data->zero = 0;
	}
}

int		ft_is_dot(t_flags *data, va_list args)
{
	data->i++;
	data->dot = 0;
	while (ft_isdigit(data->buffer[data->i]))
	{
		data->dot = (data->dot * 10) + data->buffer[data->i] - '0';
		data->i++;
	}
	if (data->buffer[data->i] == '*')
		data->dot = va_arg(args, int);
	return (data->i);
}

void	ft_is_minus(t_flags *data)
{
	data->minus = 1;
	data->zero = 0;
}
