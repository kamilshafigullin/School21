#include "libftprintf.h"

static int	ft_intlen_sexteen(unsigned int n)
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

void	ft_sexteen_fill_up(char sexteen[16])
{
	sexteen[0] = '0';
	sexteen[1] = '1';
	sexteen[2] = '2';
	sexteen[3] = '3';
	sexteen[4] = '4';
	sexteen[5] = '5';
	sexteen[6] = '6';
	sexteen[7] = '7';
	sexteen[8] = '8';
	sexteen[9] = '9';
	sexteen[10] = 'A';
	sexteen[11] = 'B';
	sexteen[12] = 'C';
	sexteen[13] = 'D';
	sexteen[14] = 'E';
	sexteen[15] = 'F';
	return ;
}

void	ft_sexteen_fill_low(char sexteen[16])
{
	sexteen[0] = '0';
	sexteen[1] = '1';
	sexteen[2] = '2';
	sexteen[3] = '3';
	sexteen[4] = '4';
	sexteen[5] = '5';
	sexteen[6] = '6';
	sexteen[7] = '7';
	sexteen[8] = '8';
	sexteen[9] = '9';
	sexteen[10] = 'a';
	sexteen[11] = 'b';
	sexteen[12] = 'c';
	sexteen[13] = 'd';
	sexteen[14] = 'e';
	sexteen[15] = 'f';
	return ;
}

char	*ft_ten_to_sixteen(t_struct setting, unsigned int num)
{
	char			*str;
	char			sexteen[16];
	unsigned int	i;

	if (setting.format == 'X')
		ft_sexteen_fill_up(&*sexteen);
	else
		ft_sexteen_fill_low(&*sexteen);
	i = ft_intlen_sexteen(num);
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

char	*ft_ifhex(va_list ag, const char *format, t_struct setting, int i)
{
	char			*result;
	unsigned int	num;
	char			*str;

	result = NULL;
	num = va_arg(ag, unsigned int);
	str = ft_ten_to_sixteen(setting, num);
	if (str[0] == '0' && setting.length == 0 && \
	setting.precision == 1 && setting.width == 0)
		str = ft_write_empty_line(str, 0, 0);
	else if (str[0] == '0' && setting.length == 0 && \
	setting.precision == 1 && setting.width > 0)
		str = ft_write_empty_line(str, setting.width, 1);
	if (setting.length <= (int)ft_strlen(str) && \
	setting.width <= (int)ft_strlen(str))
	{
		result = ft_rewrite_format(format, str, i, setting);
		free(str);
		return (result);
	}
	str = ft_ifhex2(str, setting);
	result = ft_rewrite_format(format, str, i, setting);
	free(str);
	return (result);
}
