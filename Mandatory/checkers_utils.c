/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:12:26 by astalha           #+#    #+#             */
/*   Updated: 2023/01/21 19:10:09 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

int	matlen(char **matrix)
{
	int	i;

	i = 1;
	while (matrix[i])
		i++;
	return (i);
}

int	lines_1(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	collums_1(char **matrix, int j)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		if (matrix[i][j] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	counter(char **matrix, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}
