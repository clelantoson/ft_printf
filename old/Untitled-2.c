
#include "ft_printf.h"
void	ft_in_put_part_int(char *d_i, int save_i, t_flags *data)
{
	if (save_i < 0 && data->dot >= 0)
		ft_putchar_count('-', data);
	if (data->dot >= 0)
	{
		data->width =  data->dot - 1;
		data->zero = 1;
		ft_deal_with_width(data, ft_strlen(d_i) - 1);
	}
	ft_putstrdot_count(d_i, data, ft_strlen(d_i));
}
void	ft_put_part_int(char *d_i, int save_i, t_flags *data)
{
	if (data->minus == 1)
		ft_in_put_part_int(d_i, save_i, data);
	if (data->dot >= 0 && (size_t)data->dot < ft_strlen(d_i))
		data->dot = ft_strlen(d_i);
	if (data->dot >= 0)
	{
		data->width -= data->dot;
		ft_deal_with_width(data, 0);
	}
	else
		ft_deal_with_width(data, ft_strlen(d_i));
	if (data->minus == 0)
		ft_in_put_part_int(d_i, save_i, data);
}

void			ft_deal_with_int(int num, t_flags *data)
{
	char	*d_i;
	int		save_i;
	save_i = num;
	if (data->dot == 0 && num == 0)
	{
		ft_deal_with_width(data, 0);
	}
	if (num < 0 && (data->dot >= 0 || data->zero == 1))
	{
		if (data->zero == 1 && data->dot == -1)
			ft_putstr_count("-", data);
		num *= -1;
		data->zero = 1;
		data->width--;
	}
	d_i = ft_itoa(num);
	ft_put_part_int(d_i, save_i, data);
	free(d_i);
}
