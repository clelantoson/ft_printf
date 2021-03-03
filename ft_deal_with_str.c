/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_with_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:19:50 by cle-lan           #+#    #+#             */
/*   Updated: 2021/03/03 16:22:23 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_deal_with_str(char *str, t_flags *data, int count_chars)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
   		i++;
		count_chars++;
	}
	return (count_chars);
}
