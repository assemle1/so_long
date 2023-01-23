/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:56:47 by astalha           #+#    #+#             */
/*   Updated: 2023/01/23 19:08:28 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

void	get_pos(t_infos *my_infos, char c)
{
	int	i;
	int	j;

	i = 0;
	while (my_infos->matrix[i])
	{
		j = 0;
		while (my_infos->matrix[i][j])
		{
			if (my_infos->matrix[i][j] == c)
			{
				my_infos->xp = i;
				my_infos->yp = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	close_window(t_infos *my_infos)
{
	if (my_infos->window_ptr)
		mlx_destroy_window(my_infos->mlx_ptr, my_infos->window_ptr);
	freealloc2(my_infos->matrix);
	exit(0);
}

void	start(t_infos *my_infos)
{
	my_infos->mlx_ptr = mlx_init();
	my_infos->window_ptr = NULL;
	make_textures(my_infos);
	get_pos(my_infos, 'P');
	my_infos->steps = 0;
	my_infos->col = counter(my_infos->matrix, 'C');
	my_infos->stat = 0;
	my_infos->window_ptr = mlx_new_window(my_infos->mlx_ptr,
			(int)ft_strlen(my_infos->matrix[0]) * 64,
			matlen(my_infos->matrix) * 64, "so_long");
	place_images(my_infos);
	mlx_key_hook(my_infos->window_ptr, key_movs, my_infos);
	mlx_hook(my_infos->window_ptr, 17, 0, close_window, my_infos);
	mlx_loop(my_infos->mlx_ptr);
}

void	freealloc2(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free (ptr[i]);
		i++;
	}
	free(ptr);
}
