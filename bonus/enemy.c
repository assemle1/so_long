/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 01:10:40 by astalha           #+#    #+#             */
/*   Updated: 2023/01/23 01:43:00 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/bonus.h"

void	enemy_event(t_infos *my_infos, void fct(), int stat)
{
	mlx_clear_window(my_infos->mlx_ptr, my_infos->window_ptr);
	fct(my_infos);
	fct(my_infos);
	my_infos->collecte_stat = stat;
	place_images(my_infos);
}

int	mov_enemy(t_infos *my_infos)
{
	static int	l;

	if (l == 5000)
		enemy_event(my_infos, mov_en_up, 1);
	if (l == 10000)
		enemy_event(my_infos, mov_en_rt, 2);
	if (l == 15000)
		enemy_event(my_infos, mov_en_dn, 3);
	if (l == 20000)
	{
		enemy_event(my_infos, mov_en_lt, 4);
		l = 0;
	}
	l++;
	return (0);
}

void	find_ennemy(t_infos	*my_infos)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	my_infos->num_en = counter(my_infos->matrix, 'N');
	my_infos->en = malloc((my_infos->num_en) * (sizeof(t_enemy)));
	if (!my_infos->en)
		close_window(my_infos);
	while (my_infos->matrix[i])
	{
		j = 0;
		while (my_infos->matrix[i][j])
		{
			if (my_infos->matrix[i][j] == 'N')
			{
				my_infos->en[k].ex = i;
				my_infos->en[k].ey = j;
				k++;
			}
			j++;
		}
		i++;
	}
}

int	conditions(t_infos *my_infos, int x, int y)
{
	return (my_infos->matrix[x][y] == 'C'
			|| my_infos->matrix[x][y] == '1'
			|| my_infos->matrix[x][y] == 'E'
			|| my_infos->matrix[x][y] == 'N');
}
