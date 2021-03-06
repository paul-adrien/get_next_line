/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pa <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:33:37 by pa                #+#    #+#             */
/*   Updated: 2018/11/29 10:48:44 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int i;
	int n;

	i = 0;
	n = ft_strlen(dest);
	while (src[i] != '\0')
		dest[n++] = src[i++];
	dest[n] = '\0';
	return (dest);
}
