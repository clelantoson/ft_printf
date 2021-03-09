/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_with_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 20:58:39 by cle-lan           #+#    #+#             */
/*   Updated: 2021/03/10 00:22:15 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char    *treat_base(unsigned long long to_hexa_copy, int base, char *str, int count)
{
	while (to_hexa_copy != 0)
	    {
	        if ((to_hexa_copy % base) < 10)
	            str[count - 1] = (to_hexa_copy % base) + '0';
	        else
	            str[count - 1] = (to_hexa_copy % base) + '7';
		        to_hexa_copy /= base;
	        count--;
	    }
	    return (str);
	}

char        *ft_ulltoa_base(unsigned long long to_hexa, int base)
{
	    char                *str;
	    unsigned long long    to_hexa_copy;
	    int                    count;

		str = 0;
		count = 0;
		to_hexa_copy = to_hexa;
		// if (to_hexa == 0)
	//     return (ft_strdup("0"));
	    while (to_hexa != 0)
	    {
	        to_hexa /= base;
	       count++;
	    }
	    if (!(str = malloc(sizeof(char) * (count + 1))))
	        return (0);
	    str[count] = '\0';
	    str = treat_base(to_hexa_copy, base, str, count);
	    return (str);
}


void	ft_deal_with_hex(unsigned int to_hexa, int to_lower, t_flags *data)
{
	char	*hexa;
	int i;

	i = 0;
	hexa = ft_ulltoa_base((unsigned long long)to_hexa, 16);
	if (to_lower == 1)
		hexa = ft_tolower(hexa);
	while (hexa[i])
	{
		ft_putchar(hexa[i], data);
		i++;
	}
}

