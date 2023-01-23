/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_img_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 19:38:24 by astalha           #+#    #+#             */
/*   Updated: 2023/01/23 18:13:36 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/bonus.h"

void	make_textures(t_infos *my_infos)
{
	int	size;

	size = 64;
	my_infos->player = mlx_xpm_file_to_image(my_infos->mlx_ptr,
			"./textures_bonus/player.xpm", &size, &size);
	my_infos->s_player = mlx_xpm_file_to_image(my_infos->mlx_ptr,
			"./textures_bonus/S_player.xpm", &size, &size);
	my_infos->space = mlx_xpm_file_to_image(my_infos->mlx_ptr,
			"./textures_bonus/space.xpm", &size, &size);
	my_infos->wall = mlx_xpm_file_to_image(my_infos->mlx_ptr,
			"./textures_bonus/wall.xpm", &size, &size);
	my_infos->collect = mlx_xpm_file_to_image(my_infos->mlx_ptr,
			"./textures_bonus/collecte.xpm", &size, &size);
	my_infos->c_exit = mlx_xpm_file_to_image(my_infos->mlx_ptr,
			"./textures_bonus/C_door.xpm", &size, &size);
	my_infos->o_exit = mlx_xpm_file_to_image(my_infos->mlx_ptr,
			"./textures_bonus/O_door.xpm", &size, &size);
	my_infos->enemy = mlx_xpm_file_to_image(my_infos->mlx_ptr,
			"./textures_bonus/enemy.xpm", &size, &size);
	my_infos->mid_collecte = mlx_xpm_file_to_image(my_infos->mlx_ptr,
			"./textures_bonus/mid_collecte.xpm", &size, &size);
	my_infos->big_collecte = mlx_xpm_file_to_image(my_infos->mlx_ptr,
			"./textures_bonus/big_collecte.xpm", &size, &size);
	if (if_not_works(my_infos))
		close_window(my_infos);
}

void	image_to_window(t_infos *my_infos, char obj, int j, int i)
{
	if (obj == '1')
		img_to_win(my_infos, my_infos->wall, j, i);
	else if (obj == '0')
		img_to_win(my_infos, my_infos->space, j, i);
	else if (obj == 'P')
		img_to_win(my_infos, my_infos->player, j, i);
	else if (obj == 'p')
		img_to_win(my_infos, my_infos->s_player, j, i);
	else if (obj == 'C')
		img_to_win(my_infos, my_infos->collect, j, i);
	else if (obj == 'E')
		img_to_win(my_infos, my_infos->o_exit, j, i);
	else if (obj == 'e')
		img_to_win(my_infos, my_infos->c_exit, j, i);
	else if (obj == 'N')
		img_to_win(my_infos, my_infos->enemy, j, i);
	else if (obj == 'm')
		img_to_win(my_infos, my_infos->mid_collecte, j, i);
	else if (obj == 'b')
		img_to_win(my_infos, my_infos->big_collecte, j, i);
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
		find_collect(my_infos, j, i);
	if (my_infos->matrix[i][j] == 'E')
	{
		if (!my_infos->col)
			image_to_window(my_infos, 'E', j * 64, i * 64);
		else
			image_to_window(my_infos, 'e', j * 64, i * 64);
	}
	if (my_infos->matrix[i][j] == 'N')
		image_to_window(my_infos, 'N', j * 64, i * 64);
}

void	print_to_window(t_infos	*my_infos)
{
	char	*msg;
	char	*num;
	int		l;
	int		lm;

	l = (int)ft_strlen(my_infos->matrix[0]);
	lm = matlen(my_infos->matrix);
	num = ft_itoa(my_infos->steps);
	msg = join(ft_strdup("steps : "), num);
	mlx_string_put(my_infos->mlx_ptr, my_infos->window_ptr,
		10, (matlen(my_infos->matrix) + 0.1) * 64, 0xFFFFF, msg);
	free(msg);
	free(num);
	num = ft_itoa(my_infos->col);
	msg = join(ft_strdup("collectibles left : "), num);
	mlx_string_put(my_infos->mlx_ptr, my_infos->window_ptr,
		(l / 1.2) * 64, (lm + 0.1) * 64, 0xFFFFF, msg);
	free(msg);
	free(num);
	if (!my_infos->col)
		mlx_string_put(my_infos->mlx_ptr, my_infos->window_ptr, (l / 2) * 64,
			(lm + 0.1) * 64, 0xFFFFF, "door stat : OPEN");
	else
		mlx_string_put(my_infos->mlx_ptr, my_infos->window_ptr, (l / 2) * 64,
			(lm + 0.1) * 64, 0xFFFFF, "door stat : CLOSED");
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
	print_to_window(my_infos);
}
