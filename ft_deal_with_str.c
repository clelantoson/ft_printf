/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_with_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:19:50 by cle-lan           #+#    #+#             */
/*   Updated: 2021/04/15 14:35:39 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_deal_with_dot(char *str, t_flags *data)
{
	ft_deal_with_width(data, data->dot);
	ft_putstrdot_count(str, data, data->dot);
}

void	ft_deal_with_str(char *str, t_flags *data)
{
	int temp;

	if (!str)
		str = "(null)";
	if (ft_strlen(str) == 0)
		ft_deal_with_width(data, ft_strlen(str));
	if (data->dot == 0)
	{
		if (data->width > 0)
			ft_deal_with_width(data, 0); //%3.s
		else
			ft_putstrdot_count(str, data, data->dot);
	}
	else if (data->minus == 0)
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
				ft_deal_with_dot(str, data);
			}
			else
			{
				ft_deal_with_dot(str, data);
			}
		}
	}
	else if (data->minus == 1)
	{
		if (data->dot == 1)
		{
			if (data->width > 0)
			{
				if (ft_strlen(str) == 0)
					ft_deal_with_width(data, ft_strlen(str)); //%-3.1s
				else
				{
					temp = data->dot;
					ft_putstrdot_count(str, data, data->dot);
					ft_deal_with_width(data, temp); //%-3.1s
					data->dot = 0;
				}
			}
			else
				ft_deal_with_width(data, 0); //%-3.1s
		}
		if (data->dot < 0)
		{
			ft_putstr_count(str, data);
			ft_deal_with_width(data, ft_strlen(str));
		}
		else if (data->dot > 0)
		{
			if ((size_t)data->dot > ft_strlen(str))
			{
				data->dot = ft_strlen(str);
			}
			if (data->dot > 0)
			{
				temp = data->dot;
				ft_putstrdot_count(str, data, data->dot);
				ft_deal_with_width(data, temp);
			}
		}
		data->minus = 0;
	}
}
