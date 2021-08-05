#include "libftprintf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					min;
	unsigned long int	res;

	i = 0;
	min = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			min *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (res > 9223372036854775807 && min == 1)
		return (-1);
	if (res - 1 > 9223372036854775807 && min == -1)
		return (0);
	return (res * min);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putstr_final(char *str, int j, va_list ag)
{
	int	i;

	i = 0;
	while (str[j] != '\0')
		j++;
	while (i < j)
	{
		ft_putchar(str[i]);
		i++;
	}
	free(str);
	va_end(ag);
	return (i);
}

char	*ft_strdup(const char *str)
{
	char		*dub;
	size_t		i;

	i = 0;
	dub = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (dub == NULL)
	{
		return (NULL);
	}
	while (str[i])
	{
		dub[i] = str[i];
		i++;
	}
	dub[i] = '\0';
	return (dub);
}
