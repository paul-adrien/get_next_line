/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 11:06:00 by plaurent          #+#    #+#             */
/*   Updated: 2018/11/29 13:36:19 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_realloc(int size, char *str)
{
	char *str2;

	//str2 = (char *)malloc(sizeof(char *) * size);
	str2 = ft_strdup(str);
	free(str);
	return (str2);
}

int		get_next_line(const int fd, char **line)
{
	int		i;
	int		res;
	char	buf;
	char	*str;

	i = -1;
	if ((res = read(fd, &buf, BUFF_SIZE)) == 1)
	{
		str = (char *)malloc(sizeof(char *));
		while (res == 1 && str[i] != '\n' && str[i] != EOF)
		{
			str[++i] = buf;
			str = ft_realloc((1 + i) * sizeof(char *), str);
			res = read(fd, &buf, BUFF_SIZE);
		}
		str[i] = '\0';
		*line = (char **)malloc(sizeof(char **) * 2);
		line = ft_strsub(str, 0, i);
	}
	free(str);
	return (1);
}
