/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_with_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 20:58:39 by cle-lan           #+#    #+#             */
/*   Updated: 2021/04/21 17:16:49 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_is_hexa_neg(t_flags *data, int copy_width, unsigned int to_hexa)
{
	if (to_hexa < 0)
		data->width = copy_width - 1;
	else
		data->width = copy_width;
}

void		ft_print_width(t_flags *data, char *hexa)
{
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
}

void		ft_print_width_and_dot(t_flags *data, int copy_dot, char *hexa)
{
	if (data->dot > 0)
	{
		data->width = data->dot - 1;
		data->zero = 1;
		ft_deal_with_width(data, ft_strlen(hexa) - 1);
	}
	ft_putstrdot_count(hexa, data, ft_strlen(hexa));
	data->dot = copy_dot;
	data->zero = 0;
}

int			ft_check_nuldot_argnul(t_flags *data, unsigned int to_hexa)
{
	if (data->dot == 0 && to_hexa == 0)
	{
		ft_deal_with_width(data, 0);
		return (1);
	}
	else
		return (0);
}

void		ft_deal_with_hex(unsigned int to_hexa, int to_lower, t_flags *data)
{
	char	*hexa;
	int		copy_dot;
	int		copy_width;

	copy_dot = data->dot;
	copy_width = data->width;
	if (data->zero == 1 && data->dot >= 0)
		data->zero = 0;
	if (ft_check_nuldot_argnul(data, to_hexa) == 1)
		return ;
	hexa = ft_ulltoa_base((unsigned long long)to_hexa, 16);
	if (to_lower == 1)
		hexa = ft_str_tolower(hexa);
	if (data->minus == 1)
	{
		ft_print_width_and_dot(data, copy_dot, hexa);
		ft_is_hexa_neg(data, copy_width, to_hexa);
	}
	ft_print_width(data, hexa);
	if (data->minus == 0)
	{
		ft_print_width_and_dot(data, copy_dot, hexa);
		ft_is_hexa_neg(data, copy_width, to_hexa);
	}
	free(hexa);
}
