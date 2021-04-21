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

void	ft_print_width_and_dot_uint(t_flags *data, int copy_dot, int copy_width, char *numstr)
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

void		ft_minus_or_no_minus_uint(t_flags *data, int copy_dot, int copy_width, char *numstr)
{
	if (data->minus == 1)
		ft_print_width_and_dot_uint(data, copy_dot, copy_width, numstr);
	ft_print_width_int(data, numstr);
	if (data->minus == 0)
		ft_print_width_and_dot_uint(data, copy_dot, copy_width, numstr);
}

void				ft_deal_with_uint(unsigned int num, t_flags *data)
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
	numstr = ft_utoa(num);
	ft_minus_or_no_minus_uint(data, copy_dot, copy_width, numstr);
	free(numstr);
}
