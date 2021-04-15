/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:42:14 by cle-lan           #+#    #+#             */
/*   Updated: 2021/04/16 01:56:48 by cle-lan          ###   ########.fr       */
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
	else if (arg == 'd' || arg == 'i')
		ft_deal_with_int(va_arg(args, int), data);
	else if (arg == 'u')
		ft_deal_with_uint((unsigned int)va_arg(args, unsigned int), data);
	else if (arg == 'x')
		ft_deal_with_hex(va_arg(args, unsigned int), 1, data);
	else if (arg == 'X')
		ft_deal_with_hex(va_arg(args, unsigned int), 0, data);
	else if (arg == '%')
		ft_deal_with_pc(data);
}

int		ft_parse_n_dispatch_to_flags(t_flags *data, va_list args)
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
		//  printf("data->i = %d\n", data->i);
		//  printf("data->buffer[data->i]= %c\n", data->buffer[data->i]);
		if (!ft_isdigit(data->buffer[data->i]) && !ft_is_in_type_list(data->buffer[data->i])
		&& !ft_is_in_flag_list(data->buffer[data->i]))
			break ;
		if (data->buffer[data->i] == '-')
		{
			data->minus = 1;
			data->zero = 0; //si on a un zero apres le - il n'est pas pris en compte
			//ft_deal_with_minus(va_arg(args, int), data);
		}
		if (data->buffer[data->i] == '*')
		{
			data->star = 1;
			data->width = va_arg(args, int);
			if (data->width < 0)
			{
				data->width *= -1;
				data->minus = 1;
				if (data->zero == 1 && data->minus == 1)
					data->zero = 0;
			}
		}
		if (data->buffer[data->i] == '0' && data->width == 0)
		{
			data->zero = 1;
			//data->minus = 0;
		}
		if (data->buffer[data->i] == '.')
		{
			data->i++;
			data->dot = 0;
			while (ft_isdigit(data->buffer[data->i]))
			{
				data->dot = (data->dot * 10) + data->buffer[data->i] - '0';
				data->i++;
			}
			if (data->buffer[data->i] == '*')
				data->dot = va_arg(args, int);
		//printf("data->dot = %d\n", data->dot);
		}
		if (ft_isdigit(data->buffer[data->i]))
		{
			// if (data->star == 1)
			// 	data->width = 0;
			data->width = (data->width * 10) + data->buffer[data->i] - '0';
		}
		if (ft_is_in_type_list(data->buffer[data->i]))
		{
			data->type = data->buffer[data->i];
			break ;
		}
		data->i++;
	}
	return (data->i);
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
		if (format[i] == '%') // && format[i+1]verifie si %% marche plus
		{
			if (data.it_was_percent == 1) //verifie si %%
			{
				ft_putchar_count('%', &data);
				data.it_was_percent = 0;
			}
			else
				data.it_was_percent = 1;
		}
		else if (format[i] != '%')
		{
			if (data.it_was_percent)
			{
					data.i = i;
					data.buffer = (char *)format;
					i = ft_parse_n_dispatch_to_flags(&data, args);
				if (ft_is_in_type_list(format[i]))
				{
					data.type = format[i];
					ft_dispatch_to_type((char)data.type, &data, args);
					data.minus = 0;
				}
				data.it_was_percent = 0;
			}
			else
				ft_putchar_count(format[i], &data);
		}
		i++;
	}
	va_end(args);
	return (data.count_chars);
}

//flags ’-0.*’ et la taille de champ minimale avec toutes les conversions
