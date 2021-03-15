/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 15:00:16 by cle-lan           #+#    #+#             */
/*   Updated: 2021/03/15 15:30:04 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_printf(const char *, ...);

// int main()
// {
//     const char a = 'x';
//     const char b = 'y';
//     const char c = 'z';
//     ft_printf("ft_printf -  This is char %c\n", a, b, c);
// }


int main()
{
    int ret1;
    int ret2;
    char c;
    c = 'a';
    ret1 = ft_printf("1 - Hello %-c !\n", c);
    ret2 = printf("2 - Hello %-c !\n", c);
    // printf("ma fct c : ret1 %i vraie fct : ret2 %i\n", ret1, ret2);
    // char *str;
    // str = "world";
    // ret1 = ft_printf("1 - Hello %s !\n", str);
    // ret2 = printf("2 - Hello %s !\n", str);
    // printf("ma fct s : ret1 %i vraie fct : ret2 %i\n", ret1, ret2);
    // unsigned int a = 123456789;
    // ret1 = ft_printf("1 - Hello %u !\n", a);
    // ret2 = printf("2 - Hello %u !\n", a);
    // printf("ma fct u : ret1 %u vraie fct : ret2 %u\n", ret1, ret2);
    // ret1 = ft_printf("1 - Hello %d !\n", a);
    // ret2 = printf("2 - Hello %d !\n", a);
    // printf("ma fct d : ret1 %i vraie fct : ret2 %i\n", ret1, ret2);
    // ret1 = ft_printf("1 - Hello %% !\n");
    // ret2 = printf("2 - Hello %% !\n");
    // printf("ma fct %% : ret1 %i vraie fct : ret2 %i\n", ret1, ret2);
    // int X = 107;
    // ret1 = ft_printf("Hello %X !\n", X);
    // ret2 = printf("Hello %X !\n", X);
    // printf("ma fct hexa X : ret1 %i vraie fct : ret2 %i\n", ret1, ret2);
    // int x = 108;
    // ret1 = ft_printf("Hello %x !\n", x);
    // ret2 = printf("Hello %x !\n", x);
    // printf("ma fct hexa x : ret1 %i vraie fct : ret2 %i\n", ret1, ret2);
    // ret1 = ft_printf("Hello %p !\n", str);
    // ret2 = printf("Hello %p !\n", str);
    // printf("ma fct p : ret1 %i vraie fct : ret2 %i\n", ret1, ret2);
    }
