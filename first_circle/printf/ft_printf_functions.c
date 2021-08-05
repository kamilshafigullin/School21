#include "libftprintf.h"

int	ft_strlen_nul(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	i++;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strlen_str(const char *str, int i)
{
	while (str[i] != '\0')
		i++;
	return (i);
}
