/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:00:44 by astalha           #+#    #+#             */
/*   Updated: 2023/01/18 23:56:50 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char *one_string(int ac, char **av)
{
    int fd;
    char *strmap = ft_strdup("");
    char *read = ft_strdup("");

    if (ac != 2)
        return (ft_putstr_fd("Error : args are not as wanted \n",2) ,NULL);
    if (ft_strncmp(ft_strrchr(av[1],'.'), ".ber", 4))
            return (ft_putstr_fd("Error : file of the map must be extended by .ber extension\n",2), NULL);
    fd = open(av[1], O_RDONLY);
    if (fd < 0)
        return (ft_putstr_fd("Error : file not exist\n",2) ,NULL);
    while (read)
    {
        read = get_next_line(fd);
        strmap = join(strmap, read);
    }
    if (!check_for_impopsters(strmap) || strmap[0] == 0)
        return (free(strmap),ft_putstr_fd("Error : map contains inknowing caracters\n",2),NULL);
    return  (strmap);
}

char    **Matrix(int    ac, char **av, t_infos *my_infos)
{
    if (!one_string(ac, av))
        return (NULL);
    my_infos->matrix = ft_split(one_string(ac, av), '\n');
    if (!checkERROR(my_infos->matrix))
        return NULL;
    return my_infos->matrix;
}