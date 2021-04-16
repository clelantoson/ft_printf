/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_with_ptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:51:10 by cle-lan           #+#    #+#             */
/*   Updated: 2021/04/16 16:28:03 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_deal_with_ptr(unsigned long long to_pointer, t_flags *data)
{
	char	*pointer;
	int			copy_ptr;
	int 		copy_dot;
	int 		copy_width;
	int 		neg;
	
	neg = 0;
	copy_dot = data->dot;
	copy_width = data->width;
	copy_ptr = to_pointer;

	if (data->zero == 1 && data->dot >= 0)
		data->zero = 0;
	if (to_pointer == 0 && data->dot == 0)
	{
		ft_putstrdot_count("0x", data, 2);
		data->zero = 1;
		ft_deal_with_width(data, 0);
		data->zero = 0;
	}
	pointer = ft_ulltoa_base(to_pointer, 16);
	pointer = ft_str_tolower(pointer);
	if (data->dot > 0 && (size_t)data->dot < ft_strlen(pointer))
		data->dot = ft_strlen(pointer);
	if (data->minus == 1)	
	{
		if (data->dot > 0)
		{
			data->width = data->dot;
			data->zero = 1;
			ft_deal_with_width(data, ft_strlen(pointer));
		}
		ft_putstrdot_count("0x", data, 2);
		ft_putstrdot_count(pointer, data, ft_strlen(pointer));
		data->dot = copy_dot;
		data->zero = 0;
	}
	ft_deal_with_width(data, ft_strlen(pointer) + 2);


	// if (data->dot > 0)
	// {
	// 	data->width -= data->dot;
	// 	data->zero = 0;
	// 	ft_deal_with_width(data, 0);
	// }
	// else
	// 	ft_deal_with_width(data, ft_strlen(pointer));

	if (data->minus == 0)
	{
		if (data->dot > 0)
		{
			data->width = data->dot;
			data->zero = 1;
			ft_deal_with_width(data, ft_strlen(pointer));
		}
		ft_putstrdot_count("0x", data, 2);
		ft_putstrdot_count(pointer, data, ft_strlen(pointer));
		data->dot = copy_dot;
		data->zero = 0;
	}
	free(pointer);
}
