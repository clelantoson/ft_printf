/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_with_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 20:58:39 by cle-lan           #+#    #+#             */
/*   Updated: 2021/04/21 12:20:00 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_deal_with_hex(unsigned int to_hexa, int to_lower, t_flags *data)
{
	char	*hexa;
	int		copy_hex;
	int		copy_dot;
	int		copy_width;
	int		neg;

	neg = 0;
	copy_dot = data->dot;
	copy_width = data->width;
	copy_hex = to_hexa;

	if (data->zero == 1 && data->dot >= 0)
		data->zero = 0;
	if (data->dot == 0 && to_hexa == 0)
	{
		ft_deal_with_width(data, 0);
		return ;
	}
	if (to_hexa < 0 && (data->dot > 0 || data->zero == 1))
	{
		if (data->zero == 1 && (data->dot <= 0 || data->width == 0))
			ft_putstr_count("-", data);
		to_hexa  = -to_hexa;
		data->zero = 1;
		data->width--;
		data->zero = 1;
		neg = 1;
	}
	
	hexa = ft_ulltoa_base((unsigned long long)to_hexa, 16);
		
	if (to_lower == 1)
		hexa = ft_str_tolower(hexa);
	if (data->minus == 1)	
	{
		// if (copy_hex < 0 && data->dot > 0)
		// 	ft_putchar_count('-', data);
		if (data->dot > 0)
		{
			data->width = data->dot - 1;
			data->zero = 1;
			ft_deal_with_width(data, ft_strlen(hexa) - 1);
		}
		ft_putstrdot_count(hexa, data, ft_strlen(hexa));
		data->dot = copy_dot;
		data->zero = 0;
		if (neg == 1)
			data->width = copy_width -1;
		else
			data->width = copy_width;
	}
	if (data->dot > 0 && (size_t)data->dot < ft_strlen(hexa))
		data->dot = ft_strlen(hexa);

	if (data->dot > 0)
	{
		data->width -= data->dot;
		data->zero = 0;
		ft_deal_with_width(data, 0);
	}
	else
		ft_deal_with_width(data, ft_strlen(hexa));

	if (data->minus == 0)
	{
		// if (copy_hex < 0 && data->dot > 0)
		// 	ft_putchar_count('-', data);
		if (data->dot > 0)
		{
			data->width = data->dot - 1;
			data->zero = 1;
			ft_deal_with_width(data, ft_strlen(hexa) - 1);
		}
		ft_putstrdot_count(hexa, data, ft_strlen(hexa));
		data->dot = copy_dot;
		data->zero = 0;
		if (neg == 1)
			data->width = copy_width -1;
		else
			data->width = copy_width;
	}
	free(hexa);
}

