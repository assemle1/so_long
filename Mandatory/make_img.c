/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:54:05 by astalha           #+#    #+#             */
/*   Updated: 2023/01/21 22:31:22 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

void	make_textures(t_infos *my_infos)
{
	int	size;

	size = 64;
	my_infos->player = mlx_xpm_file_to_image(my_infos->mlx_ptr,
			"./textures/player.xpm", &size, &size);
	my_infos->s_player = mlx_xpm_file_to_image(my_infos->mlx_ptr,
			"./textures/S_player.xpm", &size, &size);
	my_infos->space = mlx_xpm_file_to_image(my_infos->mlx_ptr,
			"./textures/space.xpm", &size, &size);
	my_infos->wall = mlx_xpm_file_to_image(my_infos->mlx_ptr,
			"./textures/wall.xpm", &size, &size);
	my_infos->collect = mlx_xpm_file_to_image(my_infos->mlx_ptr,
			"./textures/collecte.xpm", &size, &size);
	my_infos->c_exit = mlx_xpm_file_to_image(my_infos->mlx_ptr,
			"./textures/C_door.xpm", &size, &size);
	my_infos->o_exit = mlx_xpm_file_to_image(my_infos->mlx_ptr,
			"./textures/O_door.xpm", &size, &size);
	if (!my_infos->player || !my_infos->s_player || !my_infos->space
		||!my_infos->wall || !my_infos->collect || !my_infos->c_exit
		|| !my_infos->o_exit)
		close_window(my_infos);
}

void	image_to_window(t_infos *my_infos, char obj, int j, int i)
{
	if (obj == '1')
		mlx_put_image_to_window(my_infos->mlx_ptr,
			my_infos->window_ptr, my_infos->wall, j, i);
	else if (obj == '0')
		mlx_put_image_to_window(my_infos->mlx_ptr,
			my_infos->window_ptr, my_infos->space, j, i);
	else if (obj == 'P')
		mlx_put_image_to_window(my_infos->mlx_ptr,
			my_infos->window_ptr, my_infos->player, j, i);
	else if (obj == 'p')
		mlx_put_image_to_window(my_infos->mlx_ptr,
			my_infos->window_ptr, my_infos->s_player, j, i);
	else if (obj == 'C')
		mlx_put_image_to_window(my_infos->mlx_ptr,
			my_infos->window_ptr, my_infos->collect, j, i);
	else if (obj == 'E')
		mlx_put_image_to_window(my_infos->mlx_ptr,
			my_infos->window_ptr, my_infos->o_exit, j, i);
	else if (obj == 'e')
		mlx_put_image_to_window(my_infos->mlx_ptr,
			my_infos->window_ptr, my_infos->c_exit, j, i);
}

void	find_img(t_infos *my_infos, int j, int i)
{
	if (my_infos->matrix[i][j] == '1')
		image_to_window(my_infos, '1', j * 64, i * 64);
	if (my_infos->matrix[i][j] == '0')
		image_to_window(my_infos, '0', j * 64, i * 64);
	if (my_infos->matrix[i][j] == 'P')
	{
		if (!my_infos->col)
			image_to_window(my_infos, 'P', j * 64, i * 64);
		else
			image_to_window(my_infos, 'p', j * 64, i * 64);
	}
	if (my_infos->matrix[i][j] == 'C')
		image_to_window(my_infos, 'C', j * 64, i * 64);
	if (my_infos->matrix[i][j] == 'E')
	{
		if (!my_infos->col)
			image_to_window(my_infos, 'E', j * 64, i * 64);
		else
			image_to_window(my_infos, 'e', j * 64, i * 64);
	}
}

void	place_images(t_infos *my_infos)
{
	int	i;
	int	j;

	i = 0;
	while (my_infos->matrix[i])
	{
		j = 0;
		while (my_infos->matrix[i][j])
		{
			find_img(my_infos, j, i);
			j++;
		}
		i++;
	}
}
