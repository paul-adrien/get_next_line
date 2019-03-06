/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:16:28 by plaurent          #+#    #+#             */
/*   Updated: 2019/03/04 17:12:54 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static unsigned int	st_length_line(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

static char			*st_strjoin(char *s1, char *s2)
{
	char		*str;
	int			nb;

	nb = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = ft_strnew(nb)))
		return (NULL);
	str = ft_strncat(ft_strcpy(str, s1), s2, ft_strlen(s2));
	free(s1);
	return (str);
}

static char			*st_refresh_str(char *str)
{
	if (ft_strchr(str, '\n'))
		ft_strcpy(str, ft_strchr(str, '\n') + 1);
	else if (st_length_line(str) > 0)
		ft_strcpy(str, ft_strchr(str, '\0'));
	else
		return (NULL);
	return (str);
}

int					get_next_line(int const fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char	*str[1024];
	int			size;

	if (fd < 0 || BUFF_SIZE < 1 || !line || read(fd, buff, 0) < 0 ||
			(!(str[fd]) && (str[fd] = ft_strnew(0)) == NULL))
		return (-1);
	while (!(ft_strchr(str[fd], '\n')) &&
	(size = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[size] = '\0';
		if (!(str[fd] = st_strjoin(str[fd], buff)))
			return (-1);
	}
	*line = ft_strsub(str[fd], 0, st_length_line(str[fd]));
	if (!(st_refresh_str(str[fd])))
	{
		ft_strdel(&str[fd]);
		return (0);
	}
	return (1);
}
