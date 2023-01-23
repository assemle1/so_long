/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_img_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:07:31 by astalha           #+#    #+#             */
/*   Updated: 2023/01/23 18:16:31 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/bonus.h"

void	img_to_win(t_infos *my_infos, void *obj, int j, int i)
{
	mlx_put_image_to_window(my_infos->mlx_ptr, my_infos->window_ptr, obj, j, i);
}

int	if_not_works(t_infos *my_infos)
{
	my_infos->game_stat = 3;
	return (!my_infos->player || !my_infos->s_player || !my_infos->space
		||!my_infos->wall || !my_infos->collect || !my_infos->c_exit
		|| !my_infos->o_exit || !my_infos->enemy);
}

void	find_collect(t_infos *my_infos, int j, int i)
{
	if (my_infos->collecte_stat == 1)
		image_to_window(my_infos, 'C', j * 64, i * 64);
	else if (my_infos->collecte_stat == 2)
		image_to_window(my_infos, 'm', j * 64, i * 64);
	else if (my_infos->collecte_stat == 3)
		image_to_window(my_infos, 'b', j * 64, i * 64);
	else if (my_infos->collecte_stat == 4)
		image_to_window(my_infos, 'm', j * 64, i * 64);
}
