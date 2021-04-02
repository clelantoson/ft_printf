/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_with_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:17:28 by cle-lan           #+#    #+#             */
/*   Updated: 2021/04/02 15:27:38 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_deal_with_int(int num, t_flags *data)
{
    char *i_to_s;
    
    i_to_s = ft_itoa(num);
    if (data->minus == 0)
    {
        ft_deal_with_width(data, ft_strlen(i_to_s));
        ft_putnbr_count_chars(num, data);
        free(i_to_s);
        if (data->dot > 0)
        {
            if (data->width > 0)
            {
                ft_deal_with_width(data, ft_strlen(i_to_s));
                free(i_to_s);
                ft_putnbr_count_chars(num, data);
            }
        }
    }
    else if (data->minus == 1)
    {
        ft_putnbr_count_chars(num, data);
        ft_deal_with_width(data, ft_strlen(i_to_s));
        free(i_to_s);
    }
   // ft_putnbr_count_chars(num, data);
}
