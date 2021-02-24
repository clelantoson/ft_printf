/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:42:14 by cle-lan           #+#    #+#             */
/*   Updated: 2021/02/24 16:57:28 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"

int     ft_printf(const char *format, ...)
{ 
    char res;
    char res1;
    char res2;
    va_list args;
    t_flags data;

    va_start(args, format);
    
    res = va_arg(args, int);
    res1 = va_arg(args, int);
    res2 = va_arg(args, int);

    ft_strchr(format, '%');
    ft_putstr((char *)format);  //obligatoire
    
    //si ya des args les afficher avec putchar
    ft_putchar(res);
    ft_putchar(res1);
    ft_putchar(res2);
   
    va_end(args);
    return (0);
    //valeur de retour cest le nb de char printed
}
