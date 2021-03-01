/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:42:14 by cle-lan           #+#    #+#             */
/*   Updated: 2021/03/01 16:44:25 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int     ft_dispatch_to_type(int arg, t_flags data, va_list args, const char *format)
{
    int count_chars;
    
    if (arg == 'c')
        count_chars = ft_parser_char(va_arg(args, int), (char *)format, &data, count_chars);
   // else if (c == 's')
   //     count_chars = ft_parser_str(va_arg(args, char *), (char *)format, &data, count_chars);
   // else if (c == 'p')
   //     count_chars = ft_parser_ptr(va_arg(args, idk), (char *)format, &data, count_chars);
   // else if (c == 'd')
   //     count_chars = ft_parser_d(va_arg(args, int), (char *)format, &data, count_chars); 
   // else if (c == 'i')
   //     count_chars = ft_parser_d(va_arg(args, int), (char *)format, &data, count_chars);     

    return (count_chars);
}

int     ft_printf(const char *format, ...)
{ 
    va_list args;
    t_flags data;
    int count_chars;
    int i;

     va_start(args, format);

     while (format[i])
    {
        if (format[i] != '%')
        {
            ft_putchar(format[i]);
        }
        if (format[i] == '%')
        {
            count_chars = ft_dispatch_to_type((char)data.type, data, args, format);
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
