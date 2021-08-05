#include "libftprintf.h"

char	*ft_write_space(char c, int i, int side)
{
	char	*new;
	int		j;

	new = (char *)malloc(sizeof(char) * i);
	if (!new)
		return (NULL);
	j = 0;
	if (side == 1)
	{
		while (j < i - 1)
			new[j++] = ' ';
		new[j] = c;
		new[j + 1] = '\0';
	}
	else if (side == 0)
	{
		new[j++] = c;
		while (j < i)
			new[j++] = ' ';
		new[j] = '\0';
	}
	return (new);
}

char	*ft_write_char(char c)
{
	char	*new;

	new = (char *)malloc(sizeof(char) * 2);
	if (!new)
		return (NULL);
	new[0] = c;
	new[1] = '\0';
	return (new);
}

char	*ft_rewrite_format(const char *format, \
		const char *str, int i, t_struct setting)
{
	char	*new_format;
	int		j;
	int		len;
	int		end;

	j = i;
	len = 1;
	while (format[j++] != setting.format)
		len++;
	end = j;
	new_format = (char *)malloc(sizeof(char) \
	* (ft_strlen_str(format, i) - len) + ft_strlen(str) + 1);
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

char	*ft_rewrite_format_nul(const char *format, \
		const char *str, int i, t_struct setting)
{
	char		*new_format;
	t_rewstruct	data;

	data.j = i;
	data.len = 1;
	while (format[data.j++] != setting.format)
		data.len++;
	data.end = data.j;
	new_format = (char *)malloc(sizeof(char) \
	* (ft_strlen_str(format, i) - data.len) + ft_strlen_nul(str) + 1);
	if (!new_format)
		return (NULL);
	data.len = -1;
	while (data.len++ < i - 1)
		new_format[data.len] = format[data.len];
	data.j = 0;
	while (str[data.j] != '\0')
		new_format[data.len++] = str[data.j++];
	new_format[data.len++] = str[data.j++];
	while (str[data.j] != '\0')
		new_format[data.len++] = str[data.j++];
	while (format[data.end])
		new_format[data.len++] = format[data.end++];
	new_format[data.len] = '\0';
	return (new_format);
}

char	*ft_ifchar(va_list ag, const char *format, t_struct setting, int *j)
{
	char	c;
	char	*str;
	char	*result;
	int		i;

	i = *j;
	str = NULL;
	c = va_arg(ag, int);
	if (setting.zero == 1 || setting.length > 0)
		return (NULL);
	if (setting.width > 0 && setting.minus == 0)
		str = ft_write_space(c, setting.width, 1);
	else if (setting.width > 0 && setting.minus == 1)
		str = ft_write_space(c, setting.width, 0);
	else
		str = ft_write_char(c);
	if (c == '\0')
		result = ft_rewrite_format_nul(format, str, i, setting);
	else
		result = ft_rewrite_format(format, str, i, setting);
	if (c == '\0')
		i++;
	*j = ft_strlen(str) + i;
	free(str);
	return (result);
}
