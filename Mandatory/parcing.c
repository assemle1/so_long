/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:00:44 by astalha           #+#    #+#             */
/*   Updated: 2023/01/21 22:36:48 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

void	message(int m)
{
	if (m == 1)
		ft_putstr_fd("Error : args are not as wanted \n", 2);
	else if (m == 2)
		ft_putstr_fd(
			"Error : file of the map must be extended by .ber extension\n", 2);
	else if (m == 3)
		ft_putstr_fd("Error : file not exist\n", 2);
	else if (m == 4)
		ft_putstr_fd("Error : map contains inknowing caracters\n", 2);
}

char	*one_string(int ac, char **av)
{
	int		fd;
	char	*strmap;
	char	*read;

	if (ac != 2)
		return (message(1), NULL);
	if (ft_strncmp(ft_strrchr(av[1], '.'), ".ber", 4))
		return (message(2), NULL);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (message(3), NULL);
	strmap = ft_strdup("");
	while (1)
	{
		read = get_next_line(fd);
		if (!read)
			break ;
		strmap = join(strmap, read);
		free(read);
	}
	if (!check_for_impopsters(strmap) || strmap[0] == 0)
		return (free(strmap), message(4), NULL);
	return (strmap);
}

char	**matrix(int ac, char **av, t_infos *my_infos)
{
	char	*strmap;

	strmap = one_string(ac, av);
	if (!strmap)
		return (NULL);
	my_infos->matrix = ft_split(strmap, '\n');
	if (!checkerror(my_infos->matrix))
		return (freealloc2(my_infos->matrix), NULL);
	free(strmap);
	return (my_infos->matrix);
}
