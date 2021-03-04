#ifndef PRINTF_H
# define PRINTF_H

#include <stdarg.h>
# include <stdlib.h>

typedef struct s_flags
{
    int type;
    char buffer;
    int count_chars;
    int i;

} t_flags;

size_t	ft_strlen(const char *str);
int     ft_printf(const char *, ...);
void	ft_putstr(char *s, t_flags *data);
void	ft_putchar(char c, t_flags *data);
char	*ft_strchr(const char *s, int c);
void		ft_deal_with_char(char c, t_flags *data);
int     ft_is_in_type_list(int c);
void		ft_deal_with_str(char *str, t_flags *data);
void    ft_putnbr_count_chars(int n, t_flags *data);
void     ft_deal_with_int(int num, t_flags *data);
t_flags ft_init_struct(void);

#endif
