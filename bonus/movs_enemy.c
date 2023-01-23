/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movs_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 23:45:39 by astalha           #+#    #+#             */
/*   Updated: 2023/01/23 01:41:28 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/bonus.h"

void	mov_en_up(t_infos *my_infos)
{
	int	i;

	i = 0;
	while (i < my_infos->num_en)
	{
		if (!my_infos->steps)
			return ;
		if (my_infos->matrix[my_infos->en[i].ex - 1][my_infos->en[i].ey] == 'P')
		{
			my_infos->game_stat = 2;
			close_window(my_infos);
		}
		if (conditions(my_infos, my_infos->en[i].ex - 1, my_infos->en[i].ey))
			i++;
		else
		{
			my_infos->matrix[my_infos->en[i].ex][my_infos->en[i].ey] = '0';
			my_infos->en[i].ex -= 1;
			my_infos->matrix[my_infos->en[i].ex][my_infos->en[i].ey] = 'N';
			i++;
		}
	}
}

void	mov_en_dn(t_infos *my_infos)
{
	int	i;

	i = 0;
	while (i < my_infos->num_en)
	{
		if (!my_infos->steps)
			return ;
		if (my_infos->matrix[my_infos->en[i].ex + 1][my_infos->en[i].ey] == 'P')
		{
			my_infos->game_stat = 2;
			close_window(my_infos);
		}
		if (conditions(my_infos, my_infos->en[i].ex + 1, my_infos->en[i].ey))
			i++;
		else
		{
			my_infos->matrix[my_infos->en[i].ex][my_infos->en[i].ey] = '0';
			my_infos->en[i].ex += 1;
			my_infos->matrix[my_infos->en[i].ex][my_infos->en[i].ey] = 'N';
			i++;
		}
	}
}

void	mov_en_rt(t_infos *my_infos)
{
	int	i;

	i = 0;
	while (i < my_infos->num_en)
	{
		if (!my_infos->steps)
			return ;
		if (my_infos->matrix[my_infos->en[i].ex][my_infos->en[i].ey + 1] == 'P')
		{
			my_infos->game_stat = 2;
			close_window(my_infos);
		}
		if (conditions(my_infos, my_infos->en[i].ex, my_infos->en[i].ey + 1))
			i++;
		else
		{
			my_infos->matrix[my_infos->en[i].ex][my_infos->en[i].ey] = '0';
			my_infos->en[i].ey += 1;
			my_infos->matrix[my_infos->en[i].ex][my_infos->en[i].ey] = 'N';
			i++;
		}
	}
}

void	mov_en_lt(t_infos *my_infos)
{
	int	i;

	i = 0;
	while (i < my_infos->num_en)
	{
		if (!my_infos->steps)
			return ;
		if (my_infos->matrix[my_infos->en[i].ex][my_infos->en[i].ey - 1] == 'P')
		{
			my_infos->game_stat = 2;
			close_window(my_infos);
		}
		if (conditions(my_infos, my_infos->en[i].ex, my_infos->en[i].ey - 1))
			i++;
		else
		{
			my_infos->matrix[my_infos->en[i].ex][my_infos->en[i].ey] = '0';
			my_infos->en[i].ey -= 1;
			my_infos->matrix[my_infos->en[i].ex][my_infos->en[i].ey] = 'N';
			i++;
		}
	}
}
