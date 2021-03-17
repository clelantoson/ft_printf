/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_with_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:19:04 by cle-lan           #+#    #+#             */
/*   Updated: 2021/03/02 16:50:18 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_deal_with_char(char c, t_flags *data)
{
	if (data->minus == 1)
		ft_putchar_count(c, data);
	if (data->minus == 0)
		ft_putchar_count(c, data);
}

//Si derriere le % on a s => on cherche une string
	//Si derriere le % on a d => on cherche un int et ainsi de suite

	//1er % == arg[0], 2e % == arg[1]
	//si y'a plus de % que de args

	//si on trouve un % on stock le type dans ma structures (from astrid)
