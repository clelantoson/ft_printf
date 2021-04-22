/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_with_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:17:28 by cle-lan           #+#    #+#             */
/*   Updated: 2021/04/22 14:29:44 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_minus_or_no_minus(t_flags *data, int copy_dot, int copy_width,
								char *numstr)
{
	if (data->minus == 1)
	{
		ft_print_width_n_dot_int(data, copy_dot, numstr);
		if (data->neg == 1)
			data->width = copy_width - 1;
		else
			data->width = copy_width;
	}
	ft_print_width_int(data, numstr);
	if (data->minus == 0)
	{
		ft_print_width_n_dot_int(data, copy_dot, numstr);
		if (data->neg == 1)
			data->width = copy_width - 1;
		else
			data->width = copy_width;
	}
}

void		ft_print_width_int(t_flags *data, char *numstr)
{
	if (data->dot > 0 && (size_t)data->dot < ft_strlen(numstr))
		data->dot = ft_strlen(numstr);
	if (data->dot > 0)
	{
		data->width -= data->dot;
		data->zero = 0;
		ft_deal_with_width(data, 0);
	}
	else
		ft_deal_with_width(data, ft_strlen(numstr));
}

void		ft_print_width_n_dot_int(t_flags *data, int copy_dot,
										char *numstr)
{
	if (data->neg && data->dot > 0)
		ft_putchar_count('-', data);
	if (data->dot > 0)
	{
		data->width = data->dot - 1;
		data->zero = 1;
		ft_deal_with_width(data, ft_strlen(numstr) - 1);
	}
	ft_putstrdot_count(numstr, data, ft_strlen(numstr));
	data->dot = copy_dot;
	data->zero = 0;
}

int			ft_num_is_negative(int num, t_flags *data)
{
	if (num < 0 && (data->dot > 0 || data->zero == 1))
	{
		if (data->zero == 1 && (data->dot <= 0 || data->width == 0))
			ft_putstr_count("-", data);
		num = -num;
		data->zero = 1;
		data->width--;
		data->zero = 1;
		data->neg = 1;
	}
	return (num);
}

void		ft_deal_with_int(int num, t_flags *data)
{
	char	*numstr;
	int		copy_dot;
	int		copy_width;

	copy_dot = data->dot;
	copy_width = data->width;
	if (data->zero == 1 && data->dot >= 0)
		data->zero = 0;
	if (data->dot == 0 && num == 0)
	{
		ft_deal_with_width(data, 0);
		return ;
	}
	num = ft_num_is_negative(num, data);
	if (num == -2147483648 && data->neg == 1)
		numstr = "2147483648";
	else
		numstr = ft_itoa(num);
	ft_minus_or_no_minus(data, copy_dot, copy_width, numstr);
	if (num == -2147483648 && data->neg == 1)
		return ;
	else
		free(numstr);
}
