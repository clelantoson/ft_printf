/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_with_width.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 20:50:05 by cle-lan           #+#    #+#             */
/*   Updated: 2021/03/20 01:18:51 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_deal_with_width(t_flags *data)
{
	while (data->width - (data->minus - 1) > 1)
	{
		if (data->zero == 1)
			ft_putchar_count('0', data);
		else
			ft_putchar_count(' ', data);
		data->width--;
	}
}
