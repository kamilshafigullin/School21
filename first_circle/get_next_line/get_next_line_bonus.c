/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 17:18:39 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/07/11 18:43:40 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	size_t		len;
	char		*ptr;

	len = ft_strlen(s1) + 1;
	ptr = malloc(len);
	if (!ptr)
		return (NULL);
	ptr = ft_memcpy(ptr, s1, len);
	return (ptr);
}

void	ft_strdel(char **ptr)
{
	if (ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

char	*ft_out(int fd, char *line, char **aux)
{
	char	*ptr;
	int		len;

	len = 0;
	while (aux[fd][len] != '\n')
		len++;
	line = ft_substr(aux[fd], 0, len + 1);
	ptr = ft_strdup(ft_strchr(aux[fd], '\n') + 1);
	free(aux[fd]);
	aux[fd] = ptr;
	return (line);
}

char	*get_line(int fd, char **aux, char *ptr)
{
	int			i;
	char		*str;
	char		*line;

	i = BUFFER_SIZE;
	while (i > 0)
	{
		if (ft_strchr(aux[fd], '\n'))
			return (ft_out(fd, line, aux));
		i = read(fd, ptr, i);
		ptr[i] = '\0';
		if (!ft_strchr(aux[fd], '\n') && i == 0)
		{
			line = ft_strdup(aux[fd]);
			ft_strdel(&aux[fd]);
			if (*line)
				return (line);
		}
		str = ft_strjoin(aux[fd], ptr);
		free(aux[fd]);
		aux[fd] = str;
	}
	ft_strdel(&line);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*aux[4096];
	char		ptr[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, ptr, 0) == -1)
		return (NULL);
	if (!aux[fd])
		aux[fd] = ft_strdup("");
	return (get_line(fd, aux, ptr));
}
