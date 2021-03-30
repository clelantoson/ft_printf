/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:50:10 by cle-lan           #+#    #+#             */
/*   Updated: 2021/03/31 00:56:03 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags ft_init_struct(void)
{
	t_flags data;

	data.type = 0;
	data.i = 0;
	data.buffer = NULL;
	data.count_chars = 0;
	data.minus = 0;
	data.zero = 0;
	data.dot = -1;
	data.star = 0;
	data.width = 0;
	data.it_was_percent = 0;
	return (data);
}

