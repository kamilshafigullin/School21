#include "libftprintf.h"

int	ft_strchr (const char *str, int ch)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ch)
		i++;
	if (str[i] != ch)
		return (0);
	return (1);
}

int	ft_width(va_list ag, t_istruct size, const char *format, t_struct *new)
{
	char	*nums;

	if (size.k == 1 && format[size.j - 1] == '*')
	{
		ft_width2(ag, new);
		return (1);
	}
	nums = (char *)malloc(sizeof(char) * size.k);
	if (!nums)
		return (-1);
	nums[size.k] = '\0';
	while (size.k-- > 0)
	{
		if (format[size.j] == '*')
			return (-1);
		nums[size.k] = format[--size.j];
	}
	new->width = ft_atoi(nums);
	free(nums);
	return (1);
}

int	ft_length(va_list ag, t_istruct size, const char *format, t_struct *new)
{
	char	*nums;
	int		len;

	size.j = size.j + 1;
	if (format[size.j] == '*' && format[size.j + 1] == format[size.i])
	{
		new->length = va_arg(ag, int);
		return (1);
	}
	nums = (char *)malloc(sizeof(char) * (size.i - size.j) + 1);
	if (!nums)
		return (-1);
	len = 0;
	while (size.j < size.i)
	{
		if (format[size.j] == '*')
			return (-1);
		nums[len++] = format[size.j++];
	}
	nums[len] = '\0';
	new->length = ft_atoi(nums);
	free(nums);
	return (1);
}

int	ft_get_length_width(va_list ag, const char *format, \
						t_struct *setting, t_istruct size)
{
	int	k;

	k = 0;
	while (ft_strchr("-0", format[size.j]))
		size.j++;
	while (ft_strchr("1234567890*", format[size.j]) && \
			(format[size.j] != '.' || format[size.j] != setting->format))
	{
		size.j++;
		k++;
	}
	setting->width = 0;
	size.k = k;
	if ((format[size.j] == '.' || format[size.j] == setting->format) && k > 0)
		if (ft_width(ag, size, format, &*setting) == -1)
			return (-1);
	setting->precision = 0;
	if (format[size.j] == '.')
		setting->precision = 1;
	setting->length = 0;
	if (ft_strchr("1234567890*", format[size.j + 1]) && format[size.j] == '.')
		if (ft_length(ag, size, format, &*setting) == -1)
			return (-1);
	return (1);
}

int	ft_get_setting_format(va_list ag, const char *format, \
							int i, t_struct *send_setting)
{
	t_istruct	size;
	t_struct	setting;

	size.j = i;
	while (format[i] != 's' && format[i] != 'c' && format[i] != 'p' \
		&& format[i] != 'd' && format[i] != 'i' && format[i] != 'u' \
		&& format[i] != 'x' && format[i] != 'X' && format[i] != '%')
	{
		if (!ft_strchr("1234567890.*0-", format[i]))
			return (-1);
		i++;
	}
	setting.format = format[i];
	setting.zero = 0;
	setting.minus = 0;
	ft_get_setting_format2(format, &setting, &size);
	size.i = i;
	if (ft_get_length_width(ag, format, &setting, size) == -1)
		return (-1);
	*send_setting = setting;
	return (1);
}
