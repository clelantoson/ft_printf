/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 15:00:16 by cle-lan           #+#    #+#             */
/*   Updated: 2021/02/23 15:49:04 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_printf(const char *, ...);

int main()
{
    const char a = 'x';
    const char b = 'y'; 
    const char c = 'z';
    ft_printf("ft_printf -  This is char %c\n", a, b, c);
}