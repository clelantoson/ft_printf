/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_with_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:17:28 by cle-lan           #+#    #+#             */
/*   Updated: 2021/04/09 14:30:06 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_deal_with_int(int num, t_flags *data)
{
	char	*d_i;
	int		save_i;
	int copydot = data->dot;
	int copywidth = data->width;
	
	save_i = num;
	if (data->zero == 1 && data->dot > 0)
		data->zero = 0;
	if (data->dot == 0 && num == 0)
	{
		ft_deal_with_width(data, 0);
	}
	if (num < 0 && (data->dot >= 0 || data->zero == 1))
	{
		if (data->zero == 1 && data->dot == -1)
			ft_putstr_count("-", data);
		num *= -1;
		data->zero = 1;
		data->width--;
		data->zero = 0;
	}

	d_i = ft_itoa(num);
	
	if (data->minus == 1)
	{
		if (save_i < 0 && data->dot >= 0)
			ft_putchar_count('-', data);
		if (data->dot >= 0)
		{
			data->width = data->dot - 1;
			data->zero = 1;
			ft_deal_with_width(data, ft_strlen(d_i) - 1);
		}
		ft_putstrdot_count(d_i, data, ft_strlen(d_i));
		data->dot = copydot;
		data->width = copywidth;
		data->zero = 0;
	}
	if (data->dot >= 0 && (size_t)data->dot < ft_strlen(d_i))
		data->dot = ft_strlen(d_i);
	if (data->dot >= 0)
	{
		data->width -= data->dot;
		ft_deal_with_width(data, 0);
	}
	else
		ft_deal_with_width(data, ft_strlen(d_i));

	if (data->minus == 0)
	{
		if (save_i < 0 && data->dot >= 0)
			ft_putchar_count('-', data);
		if (data->dot >= 0)
		{
			data->width = data->dot - 1;
			data->zero = 1;
			ft_deal_with_width(data, ft_strlen(d_i) - 1);
		}
		ft_putstrdot_count(d_i, data, ft_strlen(d_i));
	}
	free(d_i);
}


//  Si le nombre de chiffres dans l’argument est inférieur à precision , la valeur de sortie est
//   remplie à gauche de zéros.
//   La valeur n’est pas tronquée lorsque le nombre de chiffres dépasse la précision
