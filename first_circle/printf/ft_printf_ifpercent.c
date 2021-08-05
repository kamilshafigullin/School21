#include "libftprintf.h"

char	*ft_write_zero(char c, int i)
{
	char	*new;
	int		j;

	new = (char *)malloc(sizeof(char) * i);
	if (!new)
		return (NULL);
	j = 0;
	while (j < i - 1)
		new[j++] = '0';
	new[j] = c;
	new[j + 1] = '\0';
	return (new);
}

char	*ft_rewrite_format_percent(const char *format, \
		const char *str, int i, t_struct setting)
{
	char	*new_format;
	int		j;
	int		len;
	int		end;

	j = i + 1;
	len = 2;
	while (format[j++] != setting.format)
		len++;
	end = j;
	new_format = (char *)malloc(sizeof(char) \
	* (ft_strlen(format) - len) + ft_strlen(str) + 1);
	if (!new_format)
		return (NULL);
	len = -1;
	while (len++ < i - 1)
		new_format[len] = format[len];
	j = 0;
	while (str[j] != '\0')
		new_format[len++] = str[j++];
	while (format[end])
		new_format[len++] = format[end++];
	new_format[len] = '\0';
	return (new_format);
}

char	*ft_ifpercent(const char *format, t_struct setting, int i)
{
	char	*new;
	char	*result;

	new = NULL;
	if (setting.width == 0)
		new = ft_write_char('%');
	else if (setting.width > 0 && setting.minus == 0 && setting.zero == 0)
		new = ft_write_space('%', setting.width, 1);
	else if (setting.width > 0 && setting.minus == 1 && setting.zero == 0)
		new = ft_write_space('%', setting.width, 0);
	else if (setting.width > 0 && setting.zero == 1)
		new = ft_write_zero('%', setting.width);
	result = ft_rewrite_format_percent(format, new, i, setting);
	free(new);
	return (result);
}
