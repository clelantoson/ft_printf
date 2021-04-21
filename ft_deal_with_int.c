/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_with_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:17:28 by cle-lan           #+#    #+#             */
/*   Updated: 2021/04/21 18:24:39 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_is_num_neg(t_flags *data, int copy_width, int num)
{
	if (num < 0)
		data->width = copy_width - 1;
	else
		data->width = copy_width;
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

void		ft_print_width_and_dot_int(t_flags *data, int copy_dot, char *numstr)
{
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

void		ft_deal_with_int(int num, t_flags *data)
{
	char	*numstr;
	int		copy_num;
	int		copy_dot;
	int		copy_width;

	copy_dot = data->dot;
	copy_width = data->width;
	copy_num = num;

	if (data->zero == 1 && data->dot >= 0)
		data->zero = 0;
	if (data->dot == 0 && num == 0)
	{
		ft_deal_with_width(data, 0);
		return ;
	}
	if (num < 0 && (data->dot > 0 || data->zero == 1))
	{
		if (data->zero == 1 && (data->dot <= 0 || data->width == 0))
			ft_putstr_count("-", data);
		num = -num;
		data->zero = 1;
		data->width--;
		data->zero = 1;
	}

	if (num == -2147483648 && num < 0)
		numstr = "2147483648";
	else
		numstr = ft_itoa(num);

	if (data->minus == 1)
	{
		if (copy_num < 0 && data->dot > 0)
			ft_putchar_count('-', data);
		ft_print_width_and_dot_int(data, copy_dot, numstr);
		ft_is_num_neg(data, copy_width, num);
	}
	ft_print_width_int(data, numstr);

	if (data->minus == 0)
	{
		if (copy_num < 0 && data->dot > 0)
			ft_putchar_count('-', data);
		ft_print_width_and_dot_int(data, copy_dot, numstr);
		ft_is_num_neg(data, copy_width, num);
	}
	if (num == -2147483648 && num < 0)
		return ;
	else
		free(numstr);
}
