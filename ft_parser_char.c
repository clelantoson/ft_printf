/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:19:04 by cle-lan           #+#    #+#             */
/*   Updated: 2021/03/01 16:04:55 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parser_char(char c, char *format, t_flags *data, int count_chars)
{
  int i; 

  i = 0;
  while (format[i])
  {
      if (format[i] != '%')
      {
			ft_putchar(format[i]);
			count_chars++;
      }
      if (format[i] == '%')
      {
        data->type = 'c'; 
        i++;
        ft_putchar(c);
		count_chars++;
      }
    i++;
  } 
  return (count_chars);
}

//Si derriere le % on a s => on cherche une string 
  //Si derriere le % on a d => on cherche un int et ainsi de suite 

  //1er % == arg[0], 2e % == arg[1]
  //si y'a plus de % que de args 

  //si on trouve un % on stock le type dans ma structures (from astrid)