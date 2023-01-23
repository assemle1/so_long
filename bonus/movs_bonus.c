/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movs_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:38:36 by astalha           #+#    #+#             */
/*   Updated: 2023/01/23 01:45:38 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/bonus.h"

void	mov_up(t_infos *my_infos)
{
	if (my_infos->matrix[my_infos->xp - 1]
		[my_infos->yp] == 'E' && my_infos->stat)
		close_window(my_infos);
	if (my_infos->matrix[my_infos->xp - 1]
		[my_infos->yp] == 'N')
	{
		my_infos->game_stat = 2;
		close_window(my_infos);
	}
	if (my_infos->matrix[my_infos->xp - 1][my_infos->yp] == '1'
		|| my_infos->matrix[my_infos->xp - 1][my_infos->yp] == 'E')
		return ;
	else
	{
		if (my_infos->matrix[my_infos->xp - 1][my_infos->yp] == 'C')
			my_infos->col--;
		my_infos->matrix[my_infos->xp - 1][my_infos->yp] = 'P';
		my_infos->matrix[my_infos->xp][my_infos->yp] = '0';
		my_infos->xp -= 1;
		my_infos->steps++;
	}
}

void	mov_dn(t_infos *my_infos)
{
	if (my_infos->matrix[my_infos->xp + 1]
		[my_infos->yp] == 'E' && my_infos->stat)
		close_window(my_infos);
	if (my_infos->matrix[my_infos->xp + 1]
		[my_infos->yp] == 'N')
	{
		my_infos->game_stat = 2;
		close_window(my_infos);
	}
	if (my_infos->matrix[my_infos->xp + 1][my_infos->yp] == '1'
		|| my_infos->matrix[my_infos->xp + 1][my_infos->yp] == 'E')
		return ;
	else
	{
		if (my_infos->matrix[my_infos->xp + 1][my_infos->yp] == 'C')
			my_infos->col--;
		my_infos->matrix[my_infos->xp + 1][my_infos->yp] = 'P';
		my_infos->matrix[my_infos->xp][my_infos->yp] = '0';
		my_infos->xp += 1;
		my_infos->steps++;
	}
}

void	mov_rt(t_infos *my_infos)
{
	if (my_infos->matrix[my_infos->xp]
		[my_infos->yp + 1] == 'E' && my_infos->stat)
		close_window(my_infos);
	if (my_infos->matrix[my_infos->xp]
		[my_infos->yp + 1] == 'N')
	{
		my_infos->game_stat = 2;
		close_window(my_infos);
	}
	if (my_infos->matrix[my_infos->xp][my_infos->yp + 1] == '1'
		|| my_infos->matrix[my_infos->xp][my_infos->yp + 1] == 'E')
		return ;
	else
	{
		if (my_infos->matrix[my_infos->xp][my_infos->yp + 1] == 'C')
			my_infos->col--;
		my_infos->matrix[my_infos->xp][my_infos->yp + 1] = 'P';
		my_infos->matrix[my_infos->xp][my_infos->yp] = '0';
		my_infos->yp += 1;
		my_infos->steps++;
	}
}

void	mov_lt(t_infos *my_infos)
{
	if (my_infos->matrix[my_infos->xp]
		[my_infos->yp - 1] == 'E' && my_infos->stat)
		close_window(my_infos);
	if (my_infos->matrix[my_infos->xp]
		[my_infos->yp - 1] == 'N')
	{
		my_infos->game_stat = 2;
		close_window(my_infos);
	}
	if (my_infos->matrix[my_infos->xp][my_infos->yp - 1] == '1'
		|| my_infos->matrix[my_infos->xp][my_infos->yp - 1] == 'E')
		return ;
	else
	{
		if (my_infos->matrix[my_infos->xp][my_infos->yp - 1] == 'C')
			my_infos->col--;
		my_infos->matrix[my_infos->xp][my_infos->yp - 1] = 'P';
		my_infos->matrix[my_infos->xp][my_infos->yp] = '0';
		my_infos->yp -= 1;
		my_infos->steps++;
	}
}

int	key_movs(int key, t_infos *my_infos)
{
	mlx_clear_window(my_infos->mlx_ptr, my_infos->window_ptr);
	if (key == K_UP)
		mov_up(my_infos);
	if (key == K_DN)
		mov_dn(my_infos);
	if (key == K_RT)
		mov_rt(my_infos);
	if (key == K_LT)
		mov_lt(my_infos);
	if (key == K_EX)
	{
		my_infos->game_stat = 0;
		close_window(my_infos);
	}
	if (!my_infos->col)
		my_infos->stat = 1;
	place_images(my_infos);
	return (0);
}
