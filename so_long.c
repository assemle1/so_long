/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:23:35 by astalha           #+#    #+#             */
/*   Updated: 2023/01/21 00:58:05 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_infos	my_infos;

	my_infos.matrix = matrix(ac, av, &my_infos);
	if (!my_infos.matrix)
		return (exit(0), 0);
	if (!valid_path(&my_infos))
		return (freealloc2(my_infos.matrix),
			freealloc2(my_infos.copy), exit(0), 0);
	start(&my_infos);
}
