/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_with_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:19:50 by cle-lan           #+#    #+#             */
/*   Updated: 2021/04/21 12:55:27 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_no_minus(char *str, t_flags *data)
{
	ft_deal_with_width(data, data->dot);
	ft_putstrdot_count(str, data, data->dot);
}

void	ft_print_with_minus(char *str, t_flags *data)
{
	ft_putstrdot_count(str, data, data->dot);
	ft_deal_with_width(data, temp);
}

void		ft_zero_or_nulldot(char *str, t_flags *data)
{
	if (!str)
		str = "(null)";
	if (ft_strlen(str) == 0)
		ft_deal_with_width(data, ft_strlen(str));
	if (data->dot == 0)
	{
		if (data->width > 0)
			ft_deal_with_width(data, 0);
		else
			ft_putstrdot_count(str, data, data->dot);
	}
}

void	ft_no_minus_str(char *str, t_flags *data)
{
	if (data->dot < 0)
	{
		ft_deal_with_width(data, ft_strlen(str));
		ft_putstr_count(str, data);
	}
	else if (data->dot > 0)
	{
		if ((size_t)data->dot > ft_strlen(str))
		{
			data->dot = ft_strlen(str);
			ft_print_no_minus(str, data);
		}
		else
			ft_print_no_minus(str, data);
	}
}

void 	ft_minus_str(char *str, t_flags *data, int temp)
{
	if (data->dot == 1)
	{
		if (data->width > 0)
		{
			if (ft_strlen(str) == 0)
				ft_deal_with_width(data, ft_strlen(str));
			else
			{
				temp = data->dot;
				ft_putstrdot_count(str, data, data->dot);
				ft_deal_with_width(data, temp);
				data->dot = 0;
			}
		}
		else
			ft_deal_with_width(data, 0);
	}
	if (data->dot < 0)
	{
		ft_putstr_count(str, data);
		ft_deal_with_width(data, ft_strlen(str));
	}
	else if (data->dot > 0)
	{
		if ((size_t)data->dot > ft_strlen(str))
			data->dot = ft_strlen(str);
		if (data->dot > 0)
		{
			temp = data->dot;
			ft_putstrdot_count(str, data, data->dot);
			ft_deal_with_width(data, temp);
		}
	}
}

void	ft_deal_with_str(char *str, t_flags *data)
{
	int temp;

	if (!str || ft_strlen(str) == 0 || data->dot == 0)
		ft_zero_or_nulldot(str, data);
	else if (data->minus == 0)
		ft_no_minus_str(str, data);
	else if (data->minus == 1)
	{
		ft_minus_str(str, data, temp);
		data->minus = 0;
	}
}
