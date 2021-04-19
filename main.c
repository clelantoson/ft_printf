/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 15:00:16 by cle-lan           #+#    #+#             */
/*   Updated: 2021/04/19 14:49:50 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

int ft_printf(const char *, ...);

// int main()
// {
//     const char a = 'x';
//     const char b = 'y';
//     const char c = 'z';
//     ft_printf("ft_printf -  This is char %c\n", a, b, c);
// }-

int main()
{
    int ret1;
    int ret2;
    //  int i;
    // char c = '1';
    // c = 'a';
    // ret1 = ft_printf("%*c%*c\n", -10, '0', -10, '1');
    // ret2 = printf("%*c%*c\n", -10, '0', -10, '1');
    // printf("ma fct c : ret1 %i vraie fct : ret2 %i\n", ret1, ret2);

    // ret1 = ft_printf("%-10c%*c%c*\n",'0', 10, '1', '2');
    // ret2 = printf("%-10c%*c%c*\n",'0', 10, '1', '2');
    // printf("ma fct c : ret1 %i vraie fct : ret2 %i\n", ret1, ret2);
  //char *str1;
  //  char *str2;
  //  str1 = "";
  //   //str2 = "world";
  //   //str2 = "b";
  //   // ret1 = ft_printf("%3.7s%7.3s\n", str1, str2);
  //   // ret2 = printf("%3.7s%7.3s\n", str1, str2);
    // ret1 = ft_printf("%*.5s %*.5s\n", -10, "123", 10, "4567");
    // ret2 = printf("%*.5s %*.5s\n", -10, "123", 10, "4567");
    // printf("ma fct s : ret1 %i vraie fct : ret2 %i\n", ret1, ret2);
    // unsigned int a = 123456789;
    // unsigned int max = 4294967295;
    // ret1 = ft_printf("1 - Hello %u !\n", max);
    // ret2 = printf("2 - Hello %u !\n", max);
    // printf("ma fct u : ret1 %u vraie fct : ret2 %u\n", ret1, ret2);
    // d = -216;
    // int d = -135;

  //trouver moyen enlever minus
  //   ret1 = printf("%0-*.*d %0*.*d\n", 2, 6, 102, 21, 10, -101);
  //  ret2 = ft_printf("%0-*.*d %0*.*d\n", 2, 6, 102, 21, 10, -101);
  //   printf("ma fct d : ret1 %i vraie fct : ret2 %i\n", ret1, ret2);

   //   ret1 = printf(" 0*%0-*d*0 0*%0*d*0\n", 21, 1021, 21, -1011);
  //   ret2 = ft_printf(" 0*%0-*d*0 0*%0*d*0\n", 21, 1021, 21, -1011);
  //   printf("ma fct d : ret1 %i vraie fct : ret2 %i\n", ret1, ret2);

    //  ret1 = printf("%0*.0d %0*.10d\n", -2, 0, 21, 1);
    //  ret2 = ft_printf("%0*.0d %0*.10d\n", -2, 0, 21, 1);
    //   printf("ma fct d : ret1 %i vraie fct : ret2 %i\n", ret1, ret2);

      // ret1 = printf("%0*.0d %0*.10d\n", -21, INT_MAX, 21, INT_MIN);
      // ret2 = ft_printf("%0*.0d %0*.10d\n", -21, INT_MAX, 21, INT_MIN);
      // printf("ma fct d : ret1 %i vraie fct : ret2 %i\n", ret1, ret2);

      // ret1 = printf(" --0*%0*.0d*0 0*%0*.10d*0-- \n", -21, LONG_MAX, 21, LONG_MIN);
      // ret2 = ft_printf(" --0*%0*.0d*0 0*%0*.10d*0-- \n", -21, LONG_MAX, 21, LONG_MIN);
      //   printf("ma fct d : ret1 %i vraie fct : ret2 %i\n", ret1, ret2);

    // ret1 = ft_printf("%0.*d !\n", 0, d);
    // ret2 = printf("%0.*d !\n", 0, d);
    // printf("ma fct d : ret1 %i vraie fct : ret2 %i\n", ret1, ret2);
    // ret1 = ft_printf("%% !\n");
    // ret2 = printf("%% !\n");
    // printf("ma fct %% : ret1 %i vraie fct : ret2 %i\n", ret1, ret2);
    // int X = 107;
    // ret1 = ft_printf("Hello %X !\n", X);
    // ret2 = printf("Hello %X !\n", X);
    // printf("ma fct hexa X : ret1 %i vraie fct : ret2 %i\n", ret1, ret2);
    // int x = 108;
    // ret1 = ft_printf("Hello %x !\n", x);
    // ret2 = printf("Hello %x !\n", x);
    // printf("ma fct hexa x : ret1 %i vraie fct : ret2 %i\n", ret1, ret2);

   // int a = 0;
    int *pnull = NULL;
    // ret1 = ft_printf("Hello %-6.p !\n", &a);
    // ret2 = printf("Hello %-6.p !\n", &a);
    // printf("ma fct p : ret1 %i vraie fct : ret2 %i\n", ret1, ret2);
    ret1 = ft_printf("Hello %*.p !\n", -3, pnull);
    ret2 = printf("Hello %*.p !\n", -3, pnull);
    printf("ma fct p : ret1 %i vraie fct : ret2 %i\n", ret1, ret2);
    }
