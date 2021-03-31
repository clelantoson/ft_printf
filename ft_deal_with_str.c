/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_with_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:19:50 by cle-lan           #+#    #+#             */
/*   Updated: 2021/03/31 23:18:32 by cle-lan          ###   ########.fr       */
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
	if (!str)
		str = "(null)";

	if (data->dot == 0)
	{
		if (data->width > 0)
			ft_deal_with_width(data, ft_strlen(str));
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
		if (data->dot < 0)
		{
			ft_putstr_count(str, data);
			ft_deal_with_width(data, ft_strlen(str));
		}
		else if (data->dot > 0)
		{

				ft_putstr_count(str, data);
			 	ft_deal_with_width(data, ft_strlen(str));
			// }
		}
	}
}

	// if (data->minus == 0 && data->dot < 0) //"%s" //"%5s"
	// {
	// 	ft_deal_with_width(data, ft_strlen(str));
	// 	ft_putstr_count(str, data);
	// }
	// else if (data->minus == 1) //"%-s" //"%-5s"
	// {
	// 	ft_putstr_count(str, data);
	// 	ft_deal_with_width(data, ft_strlen(str));
	// }
	// if (data->dot > 0 && (size_t)data->dot > ft_strlen(str)) //".7s" "hello"
	// {
	// 	data->dot = ft_strlen(str);
	// 	ft_deal_with_dot(str, data);
	// }
	// if (data->dot > 0) //".5s"
	// 	ft_deal_with_dot(str, data);
	// if (data->dot == 0) //".s"
	// {
	// 	ft_putstrdot_count(str, data, data->dot);
	// }
