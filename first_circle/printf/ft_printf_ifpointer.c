#include "libftprintf.h"

char	*ft_plus_index(char *str)
{
	char	*dub;
	int		i;
	int		j;

	dub = (char *)malloc(sizeof(char) * (2 + (int)ft_strlen(str)) + 1);
	if (!dub)
		return (NULL);
	dub[0] = '0';
	dub[1] = 'x';
	i = 2;
	j = 0;
	while (str[j] != '\0')
		dub[i++] = str[j++];
	dub[i] = '\0';
	free(str);
	return (dub);
}

static int	ft_intlen_sexteen_long(unsigned long long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 15)
	{
		n = n / 16;
		i++;
	}
	i++;
	return (i);
}

char	*ft_ten_to_sixteen_long(t_struct setting, unsigned long long int num)
{
	char			*str;
	char			sexteen[16];
	unsigned int	i;

	if (setting.format == 'X')
		ft_sexteen_fill_up(&*sexteen);
	else
		ft_sexteen_fill_low(&*sexteen);
	i = ft_intlen_sexteen_long(num);
	str = (char *)malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	str[i] = '\0';
	i--;
	while (num > 15)
	{
		str[i] = sexteen[num % 16];
		num /= 16;
		i--;
	}
	str[i] = sexteen[num];
	return (str);
}

char	*ft_ifpointer(va_list ag, const char *format, t_struct setting, int i)
{
	unsigned long long int	p;
	char					*str;
	char					*result;

	result = NULL;
	p = (unsigned long long int)va_arg(ag, char *);
	str = ft_ten_to_sixteen_long(setting, p);
	str = ft_plus_index(str);
	if (setting.length > 0 || setting.zero == 1)
	{
		free(str);
		return (NULL);
	}
	if (setting.width <= (int)ft_strlen(str))
		str = ft_strdup_malloc(str);
	else if (setting.width > 0 && setting.minus == 0)
		str = ft_write_str_space(str, setting.width);
	else if (setting.width > 0 && setting.minus == 1)
		str = ft_write_str_space_minus(str, setting.width);
	result = ft_rewrite_format(format, str, i, setting);
	free(str);
	return (result);
}
