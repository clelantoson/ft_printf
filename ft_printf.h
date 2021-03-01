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
int		ft_parser_char(char c, char *format, t_flags *data, int count_chars);

#endif