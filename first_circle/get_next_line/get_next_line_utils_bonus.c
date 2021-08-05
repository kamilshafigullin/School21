/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 11:16:58 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/07/11 11:22:35 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_strjoin(char *s1, char *s2)
{
	char		*x;
	int			i;
	int			a;

	if (!s1 || !s2)
		return (NULL);
	x = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!x)
		return (NULL);
	i = 0;
	a = 0;
	while (s1[i] != '\0')
		x[a++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		x[a++] = s2[i++];
	x[a] = '\0';
	return (x);
}

char	*ft_strchr(const char *s, int c)
{
	if (c == '\0')
	{
		s = s + ft_strlen((char *)s);
		return ((char *)s);
	}
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	l;

	i = 0;
	if (!s)
		return (NULL);
	l = ft_strlen(s);
	if (len > l)
		len = l;
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	while (i < len && start <= l)
	{
		ptr[i] = s[i + start];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;	

	d = dst;
	s = src;
	if (!dst && !src)
		return (NULL);
	while (n--)
		*d++ = *s++;
	return (dst);
}
