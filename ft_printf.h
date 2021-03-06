/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 14:23:27 by cle-lan           #+#    #+#             */
/*   Updated: 2021/04/22 14:31:36 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct	s_flags
{
	int			type;
	char		*buffer;
	int			count_chars;
	int			i;
	int			minus;
	int			zero;
	int			dot;
	int			star;
	int			width;
	int			it_was_percent;
	int			neg;
}				t_flags;

size_t			ft_strlen(const char *str);
int				ft_printf(const char *format, ...);
void			ft_putstr_count(char *s, t_flags *data);
void			ft_putchar_count(char c, t_flags *data);
void			ft_deal_with_char(char c, t_flags *data);
int				ft_is_in_type_list(int c);
void			ft_deal_with_str(char *str, t_flags *data);
void			ft_putnbr_count_chars(int n, t_flags *data);
void			ft_deal_with_int(int num, t_flags *data);
void			ft_deal_with_uint(unsigned int num, t_flags *data);
t_flags			ft_init_struct(void);
void			ft_deal_with_pc(t_flags *data);
char			*ft_ulltoa_base(unsigned long long to_hexa, int base);
void			ft_deal_with_hex(unsigned int to_hexa, int to_lower,
								t_flags *data);
char			*ft_str_tolower(char *str);
void			ft_deal_with_ptr(unsigned long long to_pointer, t_flags *data);
int				ft_is_in_flag_list(int c);
void			ft_dispatch_to_flags(t_flags *data, va_list args);
void			ft_deal_with_width(t_flags *data, int len);
void			ft_putstrdot_count(char *s, t_flags *data, int precision);
char			*ft_utoa(unsigned int n);
void			ft_init_flags(t_flags *data);
void			ft_is_star(t_flags *data, va_list args);
int				ft_is_dot(t_flags *data, va_list args);
void			ft_is_minus(t_flags *data);
void			ft_print_width_int(t_flags *data, char *numstr);
void			ft_print_width_n_dot_int(t_flags *data, int copy_dot,
										char *numstr);
int				ft_num_is_negative(int num, t_flags *data);

#endif
