/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 15:00:16 by cle-lan           #+#    #+#             */
/*   Updated: 2021/02/22 10:50:48 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_printf(const char *, ...);

int main()
{
    const char a = 'c';
    const char b = 'd';
    ft_printf("ft_printf -  This is char \n", a);
    printf("This my char %c, %c \n", a, b);
}