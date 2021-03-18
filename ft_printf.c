/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:42:14 by cle-lan           #+#    #+#             */
/*   Updated: 2021/03/18 15:31:53 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_dispatch_to_type(int arg, t_flags *data, va_list args)
{
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
}

void	ft_parse_n_dispatch_to_flags(t_flags *data, va_list args)
{
	(void) args;
	// char *buffer;
	// while (buffer = data->buffer && buffer[data->i])
	// printf("(data->buffer[data->i] = %c)\n", data->buffer[data->i]);
	// printf("(data->buffer[data->i] = %d)\n", data->buffer[data->i]);
	// printf("data->buffer = %s\n", data->buffer);
	// printf("[data->i] = %d\n", data->i);
	// printf("[data->i] = %c\n", data->i);
	while (data->buffer[data->i])
	{
		//printf("(data->buffer[data->i] %d)\n", data->buffer[data->i]);
		 printf("data->i = %d\n", data->i);
		 printf("data->buffer[data->i]= %c\n", data->buffer[data->i]);
		if (data->buffer[data->i] == '-')
		{
			data->minus = 1;
			data->zero = 0; //si on a un zero apres le - il n'est pas pris en compte
			//ft_deal_with_minus(va_arg(args, int), data);
		}
		if (data->buffer[data->i] == '*')
		{
			data->star = 1;
			//ft_deal_with_star(va_arg(args, int), data);
		}
		if (data->buffer[data->i] == '0')
		{
			data->zero = 1;
			//ft_deal_with_zero(va_arg(args, int), data);
		}
		if (data->buffer[data->i] == '.')
		{
			data->dot = 1;
			// ft_deal_with_dot(va_arg(args, int), data);
		}
		if (ft_isdigit(data->buffer[data->i]))
		{
			printf("coucou\n");
			data->width = data->width * 10 + (data->buffer[data->i]);
			printf("data->width %d\n", data->width);
		}
		data->i++;
	}
}

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
		if (format[i] == '%') // && format[i+1]verifie si %%
			data.it_was_percent = 1;
		else if (format[i] != '%')
		{
			// printf("data was percent %d\n", data.it_was_percent);
			if (data.it_was_percent)
			{
				if (ft_is_in_flag_list(format[i]))
				{
					data.i = i;
					data.buffer = (char *)format;
					// printf("data.buffer = (%s)\n", data.buffer);
					// printf("(data.buffer[data.i] = %c)\n", data.buffer[data.i]);
					// printf("(data.buffer[data.i] = %d)\n", data.buffer[data.i]);
					printf("data.i = %d\n", data.i);
					 printf("data.i = %c\n", data.i);
					ft_parse_n_dispatch_to_flags(&data, args);
				}
				else if (ft_is_in_type_list(format[i]))
				{
					data.type = format[i];
					ft_dispatch_to_type((char)data.type, &data, args);
				}
				data.it_was_percent = 0;
			}
			if (!ft_is_in_type_list(format[i]))
			{
				ft_putchar_count(format[i], &data);
			}
		}
		i++;
	}
	va_end(args);
	return (data.count_chars); //valeur de retour de printf cest le nb de char printed
}

//flags ’-0.*’ et la taille de champ minimale avec toutes les conversions
