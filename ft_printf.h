#ifndef PRINTF_H
# define PRINTF_H

#include <stdarg.h>

typedef struct s_flags
{
    int type;
    char buffer;

} t_flags;

int     ft_printf(const char *, ...);
void	ft_putstr(char *s);
void	ft_putchar(char c);
char	*ft_strchr(const char *s, int c);
int		ft_deal_with_char(char c, t_flags *data, int count_chars);
int     ft_is_in_type_list(int c);
int		ft_deal_with_str(char *str, t_flags *data, int count_chars);

#endif
