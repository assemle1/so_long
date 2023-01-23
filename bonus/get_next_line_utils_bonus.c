/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 01:53:02 by astalha           #+#    #+#             */
/*   Updated: 2023/01/21 19:38:07 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/bonus.h"

int	check(char *line)
{
	while (*line)
	{
		if (*line == '\n')
			return (0);
		line++;
	}
	return (1);
}

size_t	ft_strlen(const char	*str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dstsize)
		return ;
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
}

char	*ft_strdup(char *src)
{
	int			i;
	int			l;
	char		*str;

	i = 0;
	while (src[i])
		i++;
	l = i;
	str = (char *) malloc((i + 1) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (i < l)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = 0;
	return ((char *)str);
}
