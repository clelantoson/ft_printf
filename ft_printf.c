/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:42:14 by cle-lan           #+#    #+#             */
/*   Updated: 2021/03/15 17:18:07 by cle-lan          ###   ########.fr       */
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
	else if (arg == 'p')
		ft_deal_with_ptr(va_arg(args, unsigned long long), data);
	else if (arg == 'd' || arg == 'i' || arg == 'u' )
		ft_deal_with_int(va_arg(args, int), data);
	// else if (arg == 'u')
	// 	ft_deal_with_u_int(va_arg(args, int), data);
	else if (arg == 'x')
		ft_deal_with_hex(va_arg(args, unsigned int), 1, data);
	else if (arg == 'X')
		ft_deal_with_hex(va_arg(args, unsigned int), 0, data);
	else if (arg == '%')
		ft_deal_with_pc(data);

	//return (count_chars);
}

// void	ft_dispatch_to_flags(int arg, t_flags *data, va_list args)
// {
// 	if (arg == '.')
// 	{
// 		data->dot = arg;
// 		ft_deal_with_dot(va_arg(args, int), data);
// 	}
// 	else if (arg == '-')
// 	{
// 		data->minus = arg;
// 		ft_deal_with_minus(va_arg(args, int), data);
// 	}
// 	else if (arg == '*')
// 	{
// 		data->star = arg;
// 		ft_deal_with_star(va_arg(args, int), data);
// 	}
// 	else if (arg == '0')
// 	{
// 		data->zero = arg;
// 		ft_deal_with_zero(va_arg(args, int), data);
// 	}
// 	else if (arg == ft_isdigit)

// }

int		ft_printf(const char *format, ...)
{
	va_list args;
	t_flags data;
	int i;

	i = 0;
	va_start(args, format);
	data = ft_init_struct();
	while (format[i])
	{
		if (format[i] == '%' && ft_is_in_type_list(format[i + 1])) // && verifie si %%
			data.it_was_percent = 1;
		else
		{
			if (data.it_was_percent)
			{
				if (ft_is_in_flag_list(format[i]))
					{
						data.buffer = *format;
						printf("data.buffer = %c\n", data.buffer);
						ft_dispatch_to_flags((char)data.type, &data, args);
					}
				if (ft_is_in_type_list(format[i]))
				{
					data.type = format[i];
					ft_dispatch_to_type((char)data.type, &data, args);
				}
				data.it_was_percent = 0;
			}
			if (!ft_is_in_type_list(format[i]))
				ft_putchar_count(format[i], &data);
		}
		i++;
	}
	va_end(args);
	return (data.count_chars); //valeur de retour de printf cest le nb de char printed
}

//flags ’-0.*’ et la taille de champ minimale avec toutes les conversions
