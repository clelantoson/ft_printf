/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:19:04 by cle-lan           #+#    #+#             */
/*   Updated: 2021/02/24 16:57:25 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_parser(char format)
{
  int i; 
  int ret;

  i = 0;
  while ((ret = ft_strchr(format, '%')) != 0)
  {
      i++;
      if ((ft_strchr(format, '%')) == 0)
      {
          if (ret[i] == 'c')
            data.type = 'c'; 
      }
  } 

  return (0);
}

//Si derriere le % on a s => on cherche une string 
  //Si derriere le % on a d => on cherche un int et ainsi de suite 

  //1er % == arg[0], 2e % == arg[1]
  //si y'a plus de % que de args 

  //si on trouve un % on stock le type dans ma structures (from astrid)