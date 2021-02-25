/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:42:14 by cle-lan           #+#    #+#             */
/*   Updated: 2021/02/25 14:49:03 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"

int     ft_printf(const char *format, ...)
{ 
    char res;
    va_list args;
    t_flags data;
    int count_chars;

    va_start(args, format);

    ft_parser_char((char *)format, &data, count_chars);
    res = va_arg(args, int);

   // ft_putstr((char *)format);  //obligatoire
    
    //si ya des args les afficher avec putchar
    //ft_putchar(res);
    va_end(args);
    return (count_chars);
    //valeur de retour cest le nb de char printed
}
