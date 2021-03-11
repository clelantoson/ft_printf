#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

// void	ft_putchar(char c)
// {
//  	write(1, &c, 1);
// }

// int	ft_putnbr_count_chars(int n)
// {
// 	unsigned int bignum;
// 	int count_chars;

// 	count_chars = 0;
// 	bignum = n;
// 	if (n < 0)
// 	{
// 		bignum = -bignum;
// 		ft_putchar('-');
// 		count_chars++;
// 	}
// 	if (bignum >= 10)
// 	{
// 		ft_putnbr_count_chars(bignum / 10);
// 	}
// 	ft_putchar(bignum % 10 + '0');
// 	count_chars++;
// 	return(count_chars);
// }

