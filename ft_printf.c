/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:42:14 by cle-lan           #+#    #+#             */
/*   Updated: 2021/02/23 15:49:40 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"

int     ft_printf(const char *input, ...)
{ 
    char res;
    char res1;
    char res2;
    va_list args;

    va_start(args, input);
    
    // while (i < input)
    // {
    //     i = 0;
    //     i++;
    res = va_arg(args, int);
    res1 = va_arg(args, int);
    res2 = va_arg(args, int);
    //     printf("");
    // }
    ft_putstr((char *)input);
    ft_putchar(res);
    ft_putchar(res1);
    ft_putchar(res2);
    //printf("this is input %s\n", input);
    va_end(args);
    return (0);
}
