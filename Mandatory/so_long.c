/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:23:35 by astalha           #+#    #+#             */
/*   Updated: 2023/01/23 19:42:49 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

int	main(int ac, char **av)
{
	t_infos	my_infos;

	my_infos.matrix = matrix(ac, av, &my_infos);
	if (!my_infos.matrix)
		return (exit(0), 0);
	if ((int)ft_strlen(my_infos.matrix[0]) * 64 > 5120
		|| matlen(my_infos.matrix) * 64 > 2880)
	{
		ft_putstr_fd("Error : map has depassed the display", 2);
		ft_putstr_fd(" limits of this screen 5120 x 2880", 2);
		free(my_infos.matrix);
		exit(0);
	}
	if (!valid_path(&my_infos))
		return (freealloc2(my_infos.matrix),
			freealloc2(my_infos.copy), exit(0), 0);
	start(&my_infos);
}
