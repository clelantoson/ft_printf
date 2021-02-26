/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:42:14 by cle-lan           #+#    #+#             */
/*   Updated: 2021/02/26 12:09:52 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int     ft_printf(const char *format, ...)
{ 
    char res;
    va_list args;
    t_flags data;
    int count_chars;

    va_start(args, format);

    count_chars = ft_parser_char(va_arg(args, int), (char *)format, &data, count_chars);
    res = va_arg(args, int);

   // ft_putstr((char *)format);  //obligatoire
    
    //si ya des args les afficher avec putchar
    //ft_putchar(res);
    va_end(args);
    return (count_chars);
    //valeur de retour cest le nb de char printed
}
