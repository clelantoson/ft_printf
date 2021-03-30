/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrdot_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 17:20:09 by cle-lan           #+#    #+#             */
/*   Updated: 2021/03/30 15:35:18 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstrdot_count(char *s, t_flags *data, int precision)
{
	int i;

	i = 0;
	if (s == NULL)
		return ;
	while (i < precision && s[i])
	{
		ft_putchar_count(s[i], data);
		i++;
	}
	data->dot = 0;
}
