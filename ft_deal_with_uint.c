/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_with_uint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:17:28 by cle-lan           #+#    #+#             */
/*   Updated: 2021/04/12 22:31:37 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_deal_with_uint(unsigned int num, t_flags *data)
{
	char			*numstr;
	int				copy_num;
	int 			copy_dot;
	int 			copy_width;

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
	numstr = ft_utoa(num);
	if (data->minus == 1)
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
		data->width = copy_width;
	}
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

	if (data->minus == 0)
	{
		if (data->dot >= 0)
		{
			data->width = data->dot - 1;
			data->zero = 1;
			ft_deal_with_width(data, ft_strlen(numstr) - 1);
		}
		ft_putstrdot_count(numstr, data, ft_strlen(numstr));
		data->dot = copy_dot;
		data->zero = 0;
		data->width = copy_width;
	}
	free(numstr);
}


//  Si le nombre de chiffres dans l’argument est inférieur à precision , la valeur de sortie est
//   remplie à gauche de zéros.
//   La valeur n’est pas tronquée lorsque le nombre de chiffres dépasse la précision
