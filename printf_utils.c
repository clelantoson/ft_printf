#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

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

void	ft_putstr(char *s, t_flags *data)
{
	int i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i])
	{
		ft_putchar(s[i], data);
		i++;
	}
}

void	ft_putchar(char c, t_flags *data)
{
	write(1, &c, 1);
	data->count_chars++;
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

void	ft_putnbr_count_chars(int n, t_flags *data)
{
	unsigned int bignum;

	bignum = n;
	if (n < 0)
	{
		bignum = -bignum;
		ft_putchar('-', data);
	}
	if (bignum >= 10)
	{
		ft_putnbr_count_chars(bignum / 10, data);
	}
	ft_putchar(bignum % 10 + '0', data);
	//printf("data %d \n", data->count_chars);
}


char*	ft_tolower(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = (str[i] + 32);
			i++;
		}
		else
			i++;
	}
	return (str);
}


char		*ft_deal_with_base(unsigned long long to_hexa_copy, int base, char *str,
 								int count)
{
	while (to_hexa_copy != 0)
	{
		if ((to_hexa_copy % base) < 10)
			str[count - 1] = (to_hexa_copy % base) + '0';
		else
		{
			str[count - 1] = (to_hexa_copy % base) + '7';
		}
		to_hexa_copy /= base;
		count--;
		}
		return (str);
	}

char	*ft_ulltoa_base(unsigned long long to_hexa, int base)
{
	char					*str;
	unsigned long long		to_hexa_copy;
	int	count;

	str = 0;
	count = 0;
	to_hexa_copy = to_hexa;
	// if (to_hexa == 0)
	//return (ft_strdup("0"));
	 while (to_hexa != 0)
	{
		to_hexa /= base;
		count++;
	}
	if (!(str = malloc(sizeof(char) * (count + 1))))
		return (0);
	str[count] = '\0';
	str = ft_deal_with_base(to_hexa_copy, base, str, count);
	return (str);
}
