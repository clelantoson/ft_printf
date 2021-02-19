/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:42:14 by cle-lan           #+#    #+#             */
/*   Updated: 2021/02/19 17:03:46 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int     ft_printf(const char *s, ...)
{ 
    int i;

    va_list args;

    va_start(args, s);
    
    while (i < s)
    {
        i = 0;
        i++;
        int value = va_arg(args, char);
        printf("");
    }

    va_end(args);
}
