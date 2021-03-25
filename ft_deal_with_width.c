/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_with_width.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 20:50:05 by cle-lan           #+#    #+#             */
/*   Updated: 2021/03/25 21:16:48 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_deal_with_width(t_flags *data, int len)
{
	while (data->width - len > 0)
	{
		// printf("data->width %d\n", data->width);
		// printf("len %d\n", len);
		if (data->zero == 1)
			ft_putchar_count('0', data);
		else
			ft_putchar_count(' ', data);
		data->width--;
	}
	data->width = 0;
}
