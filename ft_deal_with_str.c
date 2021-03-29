/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_with_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:19:50 by cle-lan           #+#    #+#             */
/*   Updated: 2021/03/29 12:56:41 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_put_str_dot(char *str, t_flags *data)
{
	ft_deal_with_width(data, data->dot);
	ft_putstrdot_count(str, data, data->dot);
}

void	ft_deal_with_str(char *str, t_flags *data)
{
//	printf("datadot %d\n",data->dot);
	if (!str)
		str = "(null)";
	// if (data->dot == -1)
	// 	ft_putstrdot_count(str, data, data->dot);
	if (data->minus == 0 && data->dot < 0)
	{
		ft_deal_with_width(data, ft_strlen(str));
		ft_putstr_count(str, data);
	}
		else if (data->minus == 1)
	{
		ft_putstr_count(str, data);
		ft_deal_with_width(data, ft_strlen(str));
	}

	if (data->dot >= 0 && (size_t)data->dot > ft_strlen(str))
	{
		data->dot = ft_strlen(str);
		ft_put_str_dot(str, data);
	}
	if (data->dot > 0)
		ft_put_str_dot(str, data);
}


