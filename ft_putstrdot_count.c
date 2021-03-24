/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrdot_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 17:20:09 by cle-lan           #+#    #+#             */
/*   Updated: 2021/03/24 14:09:39 by cle-lan          ###   ########.fr       */
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
}
