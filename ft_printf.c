/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:42:14 by cle-lan           #+#    #+#             */
/*   Updated: 2021/03/03 16:22:11 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int     ft_dispatch_to_type(int arg, t_flags data, va_list args)
{
	int count_chars;
	count_chars = 0;
	if (arg == 'c')
		count_chars = ft_deal_with_char(va_arg(args, int), &data, count_chars);
   else if (arg == 's')
	   count_chars = ft_deal_with_str(va_arg(args, char *), &data, count_chars);
	// else if (c == 'p')
	//     count_chars = ft_deal_with_ptr(va_arg(args, idk), (char *)format, &data, count_chars);
	else if (arg == 'd' || arg == 'i')
	    count_chars = ft_deal_with_int(va_arg(args, int), &data, count_chars);
	// else if (c == 'u')
	//     count_chars = ft_deal_with_int(va_arg(args, int), (char *)format, &data, count_chars);
	// else if (c == 'x')
	//     count_chars = ft_deal_with_int(va_arg(args, int), (char *)format, &data, count_chars);
	// else if (c == 'X')
	//     count_chars = ft_deal_with_int(va_arg(args, int), (char *)format, &data, count_chars);
	// else if (c == '%')
	//     count_chars = ft_deal_with_int(va_arg(args, int), (char *)format, &data, count_chars);
	
	return (count_chars);
}

int		ft_printf(const char *format, ...)
{
	va_list args;
	t_flags data;
	int count_chars;
	int i;

	i = 0;
	count_chars = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			 if (ft_is_in_type_list(format[i]))
			{
				i++;
				ft_putchar(format[i]);
				count_chars++;
			}
			else
			{
				ft_putchar(format[i]);
				count_chars++;
			 //   printf("!= pc - count_chars = %d\n", count_chars);
			 }
		}
		if (format[i] == '%')
		{
			data.type = format[i + 1];
		   // i++;
		   // printf("format[i + 1] = %d !\n", format[i + 1]);
			count_chars += ft_dispatch_to_type((char)data.type, data, args);
			// printf("== pc - count_chars = %d\n", count_chars);
		   // printf("data.type = %c, data = %d, args = %d !\n", data.type, data, args);
		}
		i++;
	}
   // ft_putstr((char *)format);  //obligatoire

	//si ya des args les afficher avec putchar
	//ft_putchar(res);
	va_end(args);
	return (count_chars);
	//valeur de retour de printf cest le nb de char printed
}
