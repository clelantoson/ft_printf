/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:42:14 by cle-lan           #+#    #+#             */
/*   Updated: 2021/02/22 11:55:07 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"

int     ft_printf(const char *input, ...)
{ 
//    int i;
    va_list args;

    va_start(args, input);
    
    // while (i < input)
    // {
    //     i = 0;
    //     i++;
    //     int value = va_arg(args, char);
    //     printf("");
    // }
     
    ft_putchar(input);

    va_end(args);
    return (0);
}
