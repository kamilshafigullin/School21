#include "libftprintf.h"

static int	ft_intlen_un(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_strcpy(char *str, char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_printf_itoa_un(unsigned int n)
{
	char			*str;
	unsigned int	i;

	i = ft_intlen_un(n);
	str = (char *)malloc(sizeof(char) * i + 1);
	if (str == NULL)
		return (NULL);
	if (n == 0)
		return (ft_strcpy(str, "0"));
	str[i] = '\0';
	i = i - 1;
	while (n > 0)
	{
		str[i] = 48 + (n % 10);
		n = n / 10;
		i--;
	}
	return (str);
}

char	*ft_ifuninteger2(char *string, t_struct setting)
{
	char	*str;

	str = ft_strdup_malloc(string);
	if (setting.length > (int)ft_strlen(str))
		str = ft_write_str_zero(str, setting.length);
	if (setting.width > (int)ft_strlen(str) && \
	setting.minus == 0 && setting.zero == 0)
		str = ft_write_str_space(str, setting.width);
	else if (setting.width > (int)ft_strlen(str) && \
	setting.minus == 0 && setting.zero == 1 && \
	setting.length >= 0 && setting.precision)
		str = ft_write_str_space(str, setting.width);
	else if (setting.width > (int)ft_strlen(str) && \
	setting.minus == 1 && setting.zero == 0)
		str = ft_write_str_space_minus(str, setting.width);
	else if (setting.width > (int)ft_strlen(str) && setting.zero == 1)
		str = ft_write_str_zero(str, setting.width);
	return (str);
}

char	*ft_ifuninteger(va_list ag, const char *format, t_struct setting, int i)
{
	char	*str;
	char	*result;

	str = ft_printf_itoa_un(va_arg(ag, unsigned int));
	if (!str)
		return (NULL);
	if (str[0] == '0' && setting.length == 0 && \
	setting.precision == 1 && setting.width == 0)
		str = ft_write_empty_line(str, 0, 0);
	else if (str[0] == '0' && setting.length == 0 && \
	setting.precision == 1 && setting.width > 0)
		str = ft_write_empty_line(str, setting.width, 1);
	if (setting.length <= (int)ft_strlen(str) && \
	setting.width <= (int)ft_strlen(str) && setting.length > 0)
	{
		result = ft_rewrite_format(format, str, i, setting);
		free(str);
		return (result);
	}
	str = ft_ifuninteger2(str, setting);
	result = ft_rewrite_format(format, str, i, setting);
	free(str);
	return (result);
}
