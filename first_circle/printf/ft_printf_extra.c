#include "libftprintf.h"

int	ft_width2(va_list ag, t_struct *new)
{
	new->width = va_arg(ag, int);
	if (new->width < 0)
	{
		new->width = -new->width;
		new->minus = 1;
		new->zero = 0;
	}
	return (1);
}

int	ft_get_setting_format2(const char *format, \
							t_struct *setting, t_istruct *size)
{
	if (format[size->j] == '0' && format[size->j] != setting->format && \
		format[size->j + 1] != '-')
		setting->zero = 1;
	else if ((format[size->j] == '-' && format[size->j] != setting->format) || \
			(format[size->j] == '0' && format[size->j] != setting->format && \
			format[size->j + 1] == '-'))
		setting->minus = 1;
	if (format[size->j] == '-' || format[size->j] == '0')
		size->j++;
	return (1);
}

char	*ft_ifhex2(char *string, t_struct setting)
{
	char	*str;

	str = ft_strdup_malloc(string);
	if (setting.length > (int)ft_strlen(str))
		str = ft_write_str_zero(str, setting.length);
	if (setting.width > (int)ft_strlen(str) && \
	setting.minus == 0 && setting.zero == 0)
		str = ft_write_str_space(str, setting.width);
	else if (setting.width > (int)ft_strlen(str) && setting.minus == 0 && \
	setting.zero == 1 && setting.length >= 0 && setting.precision)
		str = ft_write_str_space(str, setting.width);
	else if (setting.width > (int)ft_strlen(str) && \
	setting.minus == 1 && setting.zero == 0)
		str = ft_write_str_space_minus(str, setting.width);
	else if (setting.width > (int)ft_strlen(str) && setting.zero == 1)
		str = ft_write_str_zero(str, setting.width);
	return (str);
}

char	*ft_ifstring2(char *string, t_struct setting)
{
	char	*str;

	str = ft_strdup_malloc(string);
	if (setting.precision == 1 && \
	setting.length < (int)ft_strlen(str) && setting.length >= 0)
		str = ft_write_str_precision(str, setting.length);
	else if (setting.precision == 1 && setting.length < 0)
		str = ft_strdup_malloc(str);
	if (setting.width == 0 || setting.width <= (int)ft_strlen(str))
		str = ft_strdup_malloc(str);
	else if (setting.width > 0 && setting.minus == 0)
		str = ft_write_str_space(str, setting.width);
	else if (setting.width > 0 && setting.minus == 1)
		str = ft_write_str_space_minus(str, setting.width);
	return (str);
}
