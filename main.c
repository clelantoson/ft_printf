/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 15:00:16 by cle-lan           #+#    #+#             */
/*   Updated: 2021/03/04 12:30:53 by cle-lan          ###   ########.fr       */
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
    ret1 = ft_printf("1 - Hello %c !\n", c);
    ret2 = printf("2 - Hello %c !\n", c);
    printf("ma fct i : ret1 %i vraie fct : ret2 %i\n", ret1, ret2);
    char *str;
    str = "world";
    ret1 = ft_printf("Hello %s !\n", str);
    ret2 = printf("Hello %s !\n", str);
    printf("ma fct i : ret1 %i vraie fct : ret2 %i\n", ret1, ret2);
    int a = 2021;
    ret1 = ft_printf("Hello %i !\n", a);
    ret2 = printf("Hello %i !\n", a);
    printf("ma fct i : ret1 %i vraie fct : ret2 %i\n", ret1, ret2);
    ret1 = ft_printf("Hello %d !\n", a);
    ret2 = printf("Hello %d !\n", a);
    printf("ma fct d : ret1 %i vraie fct : ret2 %i\n", ret1, ret2);
}
//     ret1 = ft_printf("Hello %% !\n");
//     ret2 = printf("Hello %% !\n");
//     printf("ma fct %% : ret1 %i vraie fct : ret2 %i\n", ret1, ret2);
//     int x = 2730;
//     ret1 = ft_printf("Hello %x !\n", x);
//     ret2 = printf("Hello %x !\n", x);
//     printf("ma fct hexa x : ret1 %i vraie fct : ret2 %i\n", ret1, ret2);
//     int X = 107;
//     ret1 = ft_printf("Hello %X !\n", X);
//     ret2 = printf("Hello %X !\n", X);
//     printf("ma fct hexa X : ret1 %i vraie fct : ret2 %i\n", ret1, ret2);
    /*ret1 = ft_printf("Hello %p !\n", str);
    ret1 = printf("Hello %p !\n", str);
    printf("ma fct p : ret1 %i vraie fct : ret2 %i\n", ret1, ret2);*/
