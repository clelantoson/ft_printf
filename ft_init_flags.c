/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 15:30:13 by cle-lan           #+#    #+#             */
/*   Updated: 2021/04/21 12:17:22 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_flags(t_flags *data)
{
	data->type = 0;
	data->minus = 0;
	data->zero = 0;
	data->dot = -1;
	data->star = 0;
	data->width = 0;
}
