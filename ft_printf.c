/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:42:14 by cle-lan           #+#    #+#             */
/*   Updated: 2021/03/04 12:46:48 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void	ft_dispatch_to_type(int arg, t_flags *data, va_list args)
{
	// int count_chars;
	// count_chars = 0;
	if (arg == 'c')
		ft_deal_with_char(va_arg(args, int), data);
	else if (arg == 's')
		ft_deal_with_str(va_arg(args, char *), data);
	// else if (c == 'p')
	//ft_deal_with_ptr(va_arg(args, idk), (char *)format, &data);
	else if (arg == 'd' || arg == 'i')
		ft_deal_with_int(va_arg(args, int), data);
	// else if (c == 'u')
	//	ft_deal_with_int(va_arg(args, int), (char *)format, &data, count_chars);
	// else if (c == 'x')
	//	ft_deal_with_int(va_arg(args, int), (char *)format, &data, count_chars);
	// else if (c == 'X')
	//	ft_deal_with_int(va_arg(args, int), (char *)format, &data, count_chars);
	// else if (c == '%')
	//	ft_deal_with_int(va_arg(args, int), (char *)format, &data, count_chars);

	//return (count_chars);
}

int		ft_printf(const char *format, ...)
{
	va_list args;
	t_flags data;
	data.count_chars = 0;
	data.i = 0;
	va_start(args, format);
	data = ft_init_struct();
	while (format[data.i])
	{
		if (format[data.i] != '%')
		{
			 if (ft_is_in_type_list(format[data.i]))
			{
				data.i++;
				ft_putchar(format[data.i], &data);
			}
			else
			{
				ft_putchar(format[data.i], &data);
			} //printf("count = %d\n", data.count_chars);
		}
		if (format[data.i] == '%')
		{
			data.type = format[data.i + 1];
			// i++;
			// printf("format[i + 1] = %d !\n", format[i + 1]);
			ft_dispatch_to_type((char)data.type, &data, args); 
			//printf("data %d \n", data.count_chars);
		}
		data.i++;
	}
	va_end(args);
	return (data.count_chars); //valeur de retour de printf cest le nb de char printed
}
