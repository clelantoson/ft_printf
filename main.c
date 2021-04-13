/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 15:00:16 by cle-lan           #+#    #+#             */
/*   Updated: 2021/04/13 17:33:39 by cle-lan          ###   ########.fr       */
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
  //  int i;
   // char c;
    // c = 'a';
    // ret1 = ft_printf("%*.c !\n", -4, c);
    // ret2 = printf("%*.c !\n", -4, c);
    // printf("ma fct c : ret1 %i vraie fct : ret2 %i\n", ret1, ret2);
   //char *str1;
  //  char *str2;
  //  str1 = "n";
    //str2 = "world";
    //str2 = "b";
    // ret1 = ft_printf("%3.7s%7.3s\n", str1, str2);
    // ret2 = printf("%3.7s%7.3s\n", str1, str2);
    // ret1 = ft_printf("%-16.2s\n", str1);
    // ret2 = printf("%-16.2s\n", str1);
    // printf("ma fct s : ret1 %i vraie fct : ret2 %i\n", ret1, ret2);
    // unsigned int a = 123456789;
    unsigned int max = 4294967295;
    ret1 = ft_printf("1 - Hello %u !\n", max);
    ret2 = printf("2 - Hello %u !\n", max);
    printf("ma fct u : ret1 %u vraie fct : ret2 %u\n", ret1, ret2);
    // d = -216;
    // int d = -135;
    // ret1 = ft_printf("%0.*d !\n", 0, d);
    // ret2 = printf("%0.*d !\n", 0, d);
    // printf("ma fct d : ret1 %i vraie fct : ret2 %i\n", ret1, ret2);
    // // ret1 = ft_printf("1 - Hello %% !\n");
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


// void    ft_deal_with_int(int num, t_flags *data)
// {
//     char *i_to_s;

//     i_to_s = ft_itoa(num);
//     if (data->minus == 0)
//     {
//         ft_deal_with_width(data, ft_strlen(i_to_s));
//         ft_putnbr_count_chars(num, data);
//         //free(i_to_s);
//         if (data->dot > 0)
//         {
//             if (data->width > 0)
//             {
//                 ft_deal_with_width(data, ft_strlen(i_to_s));
//                 free(i_to_s);
//                 ft_putnbr_count_chars(num, data);
//             }
//             else if ((size_t)data->dot < ft_strlen(i_to_s))
//             {
//                 data->zero = 1;
//                 data->dot = ft_strlen(i_to_s);
//                 data->width = data->dot -1;
//                 ft_deal_with_width(data, data->width);
// 	               ft_putnbr_count_chars(num, data);
//                 free(i_to_s);
//             }
//         }
//     }
//     else if (data->minus == 1)
//     {
//         ft_putnbr_count_chars(num, data);
//         ft_deal_with_width(data, ft_strlen(i_to_s));
//         free(i_to_s);
//     }
//    // ft_putnbr_count_chars(num, data);
// }
