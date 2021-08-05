#include "libftprintf.h"

char	*ft_write_str_space(char *str, int len)
{
	char	*new;
	int		i;
	int		space_len;

	space_len = len - ft_strlen(str);
	new = (char *)malloc(sizeof(char) * len + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (i < space_len)
		new[i++] = ' ';
	space_len = 0;
	while (str[space_len] != '\0')
		new[i++] = str[space_len++];
	new[i] = '\0';
	free(str);
	return (new);
}

char	*ft_write_str_space_minus(char *str, int len)
{
	char	*new;
	int		i;
	int		space_len;
	int		j;

	space_len = len - ft_strlen(str);
	new = (char *)malloc(sizeof(char) * len + 1);
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (str[j] != '\0')
		new[i++] = str[j++];
	while (space_len--)
		new[i++] = ' ';
	new[i] = '\0';
	free(str);
	return (new);
}

char	*ft_write_str_precision(char *str, int precision)
{
	char	*new;
	int		i;

	new = (char *)malloc(sizeof(char) * precision + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (i < precision)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	free(str);
	return (new);
}

char	*ft_strdup_malloc(char *str)
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
	free(str);
	return (dub);
}

char	*ft_ifstring(va_list ag, const char *format, t_struct setting, int *j)
{
	char	*str;
	char	*input;
	char	*result;
	int		i;

	i = *j;
	input = va_arg(ag, char *);
	if (input == NULL)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(input);
	if (setting.zero == 1)
		return (NULL);
	str = ft_ifstring2(str, setting);
	result = ft_rewrite_format(format, str, i, setting);
	*j = i + ft_strlen(str);
	free(str);
	return (result);
}
