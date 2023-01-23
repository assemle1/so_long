/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 01:08:36 by astalha           #+#    #+#             */
/*   Updated: 2023/01/23 01:12:31 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/bonus.h"

void	print_uwon(void)
{
	ft_printf(" _   _    __        __   ___    _   _ \n");
	ft_printf("| | | |   \\ \\      / /  / _ \\  | \\ | |\n");
	ft_printf("| | | |    \\ \\ /\\ / /  | | | | |  \\| |\n");
	ft_printf("| |_| |     \\ V  V /   | |_| | | |\\  |\n");
	ft_printf(" \\___/       \\_/\\_/     \\___/  |_| \\_|\n");
}

void	print_ulost(void)
{
	ft_printf("oooo  oooo oooooo        ooooooo    oooooooo8  ooooooooooo \n");
	ft_printf(" 888    88  888        o888   888o 888         88  888  88 \n");
	ft_printf(" 888    88  888        888     888  888oooooo      888     \n");
	ft_printf(" 888    88  888      o 888o   o888         888     888     \n");
	ft_printf("  888oo88  o888ooooo88   88ooo88   o88oooo888     o888o    \n");
}

void	print_msg(t_infos *my_infos)
{
	if (my_infos->game_stat == 1)
		print_uwon();
	if (my_infos->game_stat == 2)
		print_ulost();
	if (!my_infos->game_stat)
		ft_printf("you closed the game XX\n");
	else
		return ;
}

int	close_x(t_infos *my_infos)
{
	my_infos->game_stat = 0;
	print_msg(my_infos);
	if (my_infos->window_ptr)
	{
		if (!my_infos->window_ptr)
			mlx_destroy_window(my_infos->mlx_ptr, NULL);
		else
			mlx_destroy_window(my_infos->mlx_ptr, my_infos->window_ptr);
	}
	free(my_infos->en);
	freealloc2(my_infos->matrix);
	exit(0);
}

int	close_window(t_infos *my_infos)
{
	print_msg(my_infos);
	if (my_infos->window_ptr)
	{
		if (!my_infos->window_ptr)
			mlx_destroy_window(my_infos->mlx_ptr, NULL);
		else
			mlx_destroy_window(my_infos->mlx_ptr, my_infos->window_ptr);
	}
	free(my_infos->en);
	freealloc2(my_infos->matrix);
	exit(0);
}
