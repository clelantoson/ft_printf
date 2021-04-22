/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_with_ptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:51:10 by cle-lan           #+#    #+#             */
/*   Updated: 2021/04/22 13:33:03 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_width_dot(t_flags *data, char *pointer, int copy_dot,
														int copy_width)
{
	ft_putstrdot_count("0x", data, 2);
	data->dot = copy_dot;
	if (data->dot > 0)
	{
		data->width = data->dot;
		data->zero = 1;
		ft_deal_with_width(data, ft_strlen(pointer));
		ft_putstrdot_count(pointer, data, data->dot);
		data->dot = copy_dot;
		data->zero = 0;
		data->width = copy_width;
	}
}

void	ft_print_dot_or_not(t_flags *data, char *pointer, int copy_dot,
														int copy_ptr)
{
	if (data->minus == 1)
		if (copy_ptr == 0 && copy_dot == 0)
			ft_deal_with_width(data, 2);
		else
			ft_putstrdot_count(pointer, data, ft_strlen(pointer));
	else if (data->minus == 0)
	{
		if (copy_ptr == 0 && copy_dot == 0)
			ft_deal_with_width(data, 2);
		else
			ft_deal_with_width(data, ft_strlen(pointer) + 2);
	}
}

char	*ft_check_cases_n_convert(t_flags *data, char *pointer,
								unsigned long long to_pointer)
{
	if (data->zero == 1 && data->dot >= 0)
		data->zero = 0;
	pointer = ft_ulltoa_base(to_pointer, 16);
	pointer = ft_str_tolower(pointer);
	if (data->dot > 0 && (size_t)data->dot < ft_strlen(pointer))
		data->dot = ft_strlen(pointer);
	return (pointer);
}


void	ft_deal_with_ptr(unsigned long long to_pointer, t_flags *data)
{
	char	*pointer;
	int		copy_ptr;
	int 	copy_dot;
	int 	copy_width;

	copy_dot = data->dot;
	copy_width = data->width;
	copy_ptr = to_pointer;
	pointer = NULL;
	pointer = ft_check_cases_n_convert(data, pointer, to_pointer);
	if (data->minus == 1)
	{
		ft_print_width_dot(data, pointer, copy_dot, copy_width);
		ft_print_dot_or_not(data, pointer, copy_dot, copy_ptr);
		ft_deal_with_width(data, ft_strlen(pointer) + 2);
	}
	if (data->minus == 0)
	{
		ft_print_dot_or_not(data, pointer, copy_dot, copy_ptr);
		ft_print_width_dot(data, pointer, copy_dot, copy_width);
		if (copy_ptr == 0 && copy_dot == 0)
			ft_deal_with_width(data, copy_width + 2);
		else
			ft_putstrdot_count(pointer, data, ft_strlen(pointer));
	}
	free(pointer);
}
