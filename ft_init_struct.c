/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:50:10 by cle-lan           #+#    #+#             */
/*   Updated: 2021/03/04 12:30:01 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags ft_init_struct(void)
{
    t_flags data;
    
    data.type = 0;
    data.i = 0;
    data.count_chars = 0;
    
    return (data);
}

