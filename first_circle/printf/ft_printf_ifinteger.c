#include "libftprintf.h"

char	*ft_write_str_zero(char *str, int precision)
{
	char	*new;
	int		i;
	int		len;

	len = precision - ft_strlen(str);
	new = (char *)malloc(sizeof(char) * precision + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = '0';
		i++;
	}
	len = 0;
	while (str[len])
		new[i++] = str[len++];
	new[i] = '\0';
	free(str);
	return (new);
}

char	*ft_write_empty_line(char *str, int len, int width)
{
	char	*empty;

	if (width == 1)
	{
		empty = (char *)malloc(sizeof(char) * len + 1);
		if (!empty)
			return (NULL);
		empty[len] = '\0';
		len--;
		while (len)
			empty[len--] = ' ';
		empty[len] = ' ';
	}
	else
	{
		empty = (char *)malloc(sizeof(char) * 1);
		if (!empty)
			return (NULL);
		empty[0] = '\0';
	}
	free(str);
	return (empty);
}

char	*ft_write_str_zero_negative(char *str, int precision, int width)
{
	char	*new;
	int		i;
	int		len;
	int		j;

	len = precision - (ft_strlen(str) - 1);
	new = (char *)malloc(sizeof(char) * precision + 2);
	i = 0;
	new[i] = '-';
	i++;
	j = 0;
	if (width == 1)
		len--;
	while (j < len)
	{
		new[i++] = '0';
		j++;
	}
	len = 1;
	while (str[len])
		new[i++] = str[len++];
	new[i] = '\0';
	free(str);
	return (new);
}

char	*ft_ifinteger2(char *string, t_struct setting)
{
	char	*str;

	str = ft_strdup_malloc(string);
	if (setting.length > (int)ft_strlen(str) && str[0] != '-')
		str = ft_write_str_zero(str, setting.length);
	else if (setting.length > (int)ft_strlen(str) - 1 && str[0] == '-')
		str = ft_write_str_zero_negative(str, setting.length, 0);
	if (setting.width > (int)ft_strlen(str) && \
	setting.minus == 0 && setting.zero == 0)
		str = ft_write_str_space(str, setting.width);
	else if (setting.width > (int)ft_strlen(str) && setting.minus == 0 \
	&& setting.zero == 1 && setting.length >= 0 && setting.precision)
		str = ft_write_str_space(str, setting.width);
	else if (setting.width > (int)ft_strlen(str) && \
	setting.minus == 1 && setting.zero == 0)
		str = ft_write_str_space_minus(str, setting.width);
	else if (setting.width > (int)ft_strlen(str) && \
	setting.zero == 1 && str[0] != '-')
		str = ft_write_str_zero(str, setting.width);
	else if (setting.width > (int)ft_strlen(str) && \
	setting.zero == 1 && str[0] == '-')
		str = ft_write_str_zero_negative(str, setting.width, 1);
	return (str);
}

char	*ft_ifinteger(va_list ag, const char *format, t_struct setting, int i)
{
	char	*str;
	char	*result;

	str = ft_printf_itoa(va_arg(ag, int));
	if (!str)
		return (NULL);
	if (str[0] == '0' && setting.length == 0 && \
	setting.precision == 1 && setting.width == 0)
		str = ft_write_empty_line(str, 0, 0);
	else if (str[0] == '0' && setting.length == 0 && \
	setting.precision == 1 && setting.width > 0)
		str = ft_write_empty_line(str, setting.width, 1);
	if (setting.length <= (int)ft_strlen(str) && \
	setting.width <= (int)ft_strlen(str) && str[0] != '-')
	{
		result = ft_rewrite_format(format, str, i, setting);
		free(str);
		return (result);
	}
	str = ft_ifinteger2(str, setting);
	result = ft_rewrite_format(format, str, i, setting);
	free(str);
	return (result);
}
