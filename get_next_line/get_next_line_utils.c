/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvermot- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:08:15 by vvermot-          #+#    #+#             */
/*   Updated: 2021/10/19 17:08:17 by vvermot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

unsigned long int	ft_strlen(const char *s)
{
	unsigned long int	i;

	i = -1;
	while (s[++i])
		;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*ret;

	i = -1;
	while (s1[++i])
		;
	ret = (char *)malloc(i * sizeof(const char) + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (s1[i] != '\n' && s1[i])
	{
		ret[i] = s1[i];
		i++;
		if (s1[i] == '\n')
			ret[i] = s1[i];
	}
	if (ret[i] == '\n')
		ret[++i] = '\0';
	else
		ret[i] = '\0';
	return (ret);
}

// Copie un string d'une longueur maximale de len commencant a l'index start
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*ret;

	i = 0;
	if (!s)
		return (NULL);
	if (start + len > ft_strlen(s))
		ret = malloc(sizeof(char) * ft_strlen(s) + 1);
	else
		ret = (char *)malloc(len * sizeof(char) + 1);
	if (!ret)
		return (NULL);
	while (s[start] && i < len && start < ft_strlen(s))
		ret[i++] = s[start++];
	ret[i] = '\0';
	return (ret);
}

char	*ft_strchr(const char *s, int c)
{
	c = (char)c;
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == '\0' && c == '\0')
		return ((char *)s);
	return (0);
}
