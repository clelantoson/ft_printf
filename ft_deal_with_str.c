/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_with_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:19:50 by cle-lan           #+#    #+#             */
/*   Updated: 2021/03/29 16:14:10 by cle-lan          ###   ########.fr       */
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
	// if (data->dot < 0)
	// {
	// 	ft_putstrdot_count(str, data, data->dot);
	// }
	if (data->minus == 0 && data->dot < 0) //"%s" //"%5s" //5.s
	{
		ft_deal_with_width(data, ft_strlen(str));
		ft_putstr_count(str, data);
	}
	else if (data->minus == 1) //"%-s" //"%-5s" 
	{
		ft_putstr_count(str, data);
		ft_deal_with_width(data, ft_strlen(str));
	}

	if (data->dot >= 0 && (size_t)data->dot > ft_strlen(str)) //".7s" "hello"
	{
		data->dot = ft_strlen(str);
		ft_deal_with_dot(str, data);
	}
	if (data->dot > 0) //".5s"
		ft_deal_with_dot(str, data);
	if (data->dot == 0) //".s"
	{
		ft_putstrdot_count(str, data, data->dot);
	}
}
