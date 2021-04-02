/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_with_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:17:28 by cle-lan           #+#    #+#             */
/*   Updated: 2021/04/02 16:44:20 by cle-lan          ###   ########.fr       */
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
        //free(i_to_s);
        if (data->dot > 0)
        {
            if (data->width > 0)
            {
                ft_deal_with_width(data, ft_strlen(i_to_s));
                free(i_to_s);
                ft_putnbr_count_chars(num, data);
            }
            else if ((size_t)data->dot < ft_strlen(i_to_s))
            {
                data->zero = 1;
                data->dot = ft_strlen(i_to_s);
                data->width = data->dot -1;
                ft_deal_with_width(data, data->width);
	            ft_putnbr_count_chars(num, data);
                free(i_to_s);
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

//  Si le nombre de chiffres dans l’argument est inférieur à precision , la valeur de sortie est
//   remplie à gauche de zéros.
//   La valeur n’est pas tronquée lorsque le nombre de chiffres dépasse la précision