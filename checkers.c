/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:10:07 by astalha           #+#    #+#             */
/*   Updated: 2023/01/20 20:32:59 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checkwals(char **matrix)
{
	int	l;
	int	lo;

	lo = ft_strlen(matrix[0]);
	l = matlen(matrix);
	if (!collums_1(matrix, 0) || !collums_1(matrix, lo - 1)
		|| !lines_1(matrix[0]) || !lines_1(matrix[l - 1]))
		return (0);
	return (1);
}

int	check_pce(char **matrix)
{
	if (1 != counter(matrix, 'P'))
		return (
			ft_putstr_fd("Error : there is no start or more than one\n", 2), 0);
	else if (1 != counter(matrix, 'E'))
		return (
			ft_putstr_fd("Error : there is no exit or more than one\n", 2), 0);
	else if (1 > counter(matrix, 'C'))
		return (
			ft_putstr_fd("Error : not enough collectibles\n", 2), 0);
	return (1);
}

int	checkshape(char **matrix)
{
	int		l;
	size_t	lo;
	int		i;

	i = 0;
	l = matlen(matrix);
	lo = ft_strlen(matrix[0]);
	while (matrix[i])
	{
		if (lo != ft_strlen(matrix[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_for_impopsters(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr("PCE01\n", str[i]))
			return (0);
		if (!str[i + 1] && str[i] == '\n')
			return (0);
		if (str[i + 1])
		{
			if ((str[i] == '\n' && str[i + 1] == '\n')
				|| (str[i] == '\n' && i == 0))
				return (0);
		}
		i++;
	}
	return (1);
}

int	checkerror(char **matrix)
{
	if (!check_pce(matrix))
		return (0);
	else if (!checkshape(matrix))
		return (ft_putstr_fd("Error : map is not rectangle\n", 2), 0);
	else if (!checkwals(matrix))
		return (ft_putstr_fd("Error : walls are not entred as wanted\n", 2), 0);
	return (1);
}
