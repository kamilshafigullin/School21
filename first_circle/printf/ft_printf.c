#include "libftprintf.h"

void	ft_putstr(const char *str)
{
	while (*str)
		ft_putchar(*str++);
}

char	*ft_get_new_format(va_list ag, char *format, t_struct setting, int *j)
{
	char	*res;
	int		i;

	i = *j;
	res = NULL;
	if (setting.format == 'c')
		res = ft_ifchar(ag, format, setting, &i);
	else if (setting.format == 's')
		res = ft_ifstring(ag, format, setting, &i);
	else if (setting.format == '%')
		res = ft_ifpercent(format, setting, i);
	else if (setting.format == 'd' || setting.format == 'i')
		res = ft_ifinteger(ag, format, setting, i);
	else if (setting.format == 'u')
		res = ft_ifuninteger(ag, format, setting, i);
	else if (setting.format == 'x' || setting.format == 'X')
		res = ft_ifhex(ag, format, setting, i);
	else if (setting.format == 'p')
		res = ft_ifpointer(ag, format, setting, i);
	*j = i;
	free(format);
	return (res);
}

int	ft_printf_start (const char **format, char **result, int *i, int *j)
{
	if (!ft_strchr(*format, '%'))
	{
		ft_putstr(*format);
		return (1);
	}
	*result = ft_strdup(*format);
	*i = -1;
	*j = 0;
	return (0);
}

int	ft_printf_main(const char *result, const char *format, int *k, int *m)
{
	int	i;
	int	j;

	i = *m;
	j = *k;
	while (result[j] != '%' && result[j] != '\0')
		j = (j + 1);
	j = j + 1;
	while (format[i + 1] != '%' && format[i])
		i = i + 1;
	if (format[i] == '\0' || result[j] == '\0')
		return (1);
	i = i + 1;
	*m = i;
	*k = j;
	return (0);
}

int	ft_printf(const char *format, ...)
{
	t_struct	setting;
	va_list		ag;
	char		*result;
	int			i;
	int			j;

	if (ft_printf_start(&format, &result, &i, &j) == 1)
		return (ft_strlen(format));
	va_start(ag, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			if (ft_get_setting_format(ag, format, i + 1, &setting) == -1)
				return (-1);
			while (result[j] != '%')
				j++;
			result = ft_get_new_format(ag, result, setting, &j);
			if (!result)
				return (-1);
			if (setting.format == '%' && ft_printf_main(result, format, &j, &i))
				break ;
		}
	}
	return (ft_putstr_final(result, j, ag));
}
