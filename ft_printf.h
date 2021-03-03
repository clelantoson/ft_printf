#ifndef PRINTF_H
# define PRINTF_H

#include <stdarg.h>
# include <stdlib.h>

typedef struct s_flags
{
    int type;
    char buffer;
    int count_chars;

} t_flags;

size_t	ft_strlen(const char *str);
int     ft_printf(const char *, ...);
void	ft_putstr(char *s);
void	ft_putchar(char c);
char	*ft_strchr(const char *s, int c);
int		ft_deal_with_char(char c, t_flags *data, int count_chars);
int     ft_is_in_type_list(int c);
int		ft_deal_with_str(char *str, t_flags *data, int count_chars);
int    ft_putnbr_count_chars(int n);
int     ft_deal_with_int(int num, t_flags *data, int count_chars);

#endif
