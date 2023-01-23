/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 00:17:08 by astalha           #+#    #+#             */
/*   Updated: 2023/01/22 19:11:54 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/bonus.h"

void	flood_fill(t_infos *my_infos, int x, int y)
{
	if (ft_strchr("1EFN\n", my_infos->copy[x][y]))
		return ;
	my_infos->copy[x][y] = 'F';
	flood_fill(my_infos, x, y - 1);
	flood_fill(my_infos, x, y + 1);
	flood_fill(my_infos, x + 1, y);
	flood_fill(my_infos, x - 1, y);
}

void	copy(t_infos *my_infos)
{
	int	i;

	i = 0;
	my_infos->copy = (char **) malloc(
			(matlen(my_infos->matrix) + 1) * sizeof(char *));
	if (!my_infos->copy)
		return ;
	while (i < matlen(my_infos->matrix))
	{
		my_infos->copy[i] = ft_strdup(my_infos->matrix[i]);
		i++;
	}
	my_infos->copy[i] = NULL;
}

int	valid_path(t_infos *my_infos)
{
	copy(my_infos);
	get_pos(my_infos, 'P');
	flood_fill(my_infos, my_infos->xp, my_infos->yp);
	if (counter(my_infos->copy, 'C'))
		return (ft_putstr_fd("Error : no path for collectibles\n", 2), 0);
	get_pos(my_infos, 'E');
	if (my_infos->copy[my_infos->xp - 1][my_infos->yp] != 'F'
			&& my_infos->copy[my_infos->xp + 1][my_infos->yp] != 'F'
			&& my_infos->copy[my_infos->xp][my_infos->yp - 1] != 'F'
			&& my_infos->copy[my_infos->xp][my_infos->yp + 1] != 'F')
		return (ft_putstr_fd(
				"Error : no valid path, player can't exit\n", 2), 0);
	freealloc2(my_infos->copy);
	return (1);
}
