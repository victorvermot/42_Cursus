/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvermot- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:08:07 by vvermot-          #+#    #+#             */
/*   Updated: 2021/10/19 17:08:10 by vvermot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void	get_content(char *buf, char **ret)
{
	printf("%s", buf);
	int	i;

	i = -1;
	while (buf[++i] != '\n' && buf[i])
	{
		*(ret[i]) = buf[i];
	}
	*(ret[i]) = '\n';
}

char	*get_new_line(char *str)
{
	printf("%s", str);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char static	*ret;
	int			i;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (read(fd, buf, BUFFER_SIZE) < 1)
		return (NULL);
	get_content(buf, &ret);
	free(buf);
	//printf("%s", ret);
	return (ret);
}

int main()
{
	static int	fd;
	int	i;

	i = 1;
	fd = open("test.txt", O_RDONLY);
	while (i < 3)
	{
		get_next_line(fd);
		i++;
	}
}
