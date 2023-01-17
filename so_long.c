/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:23:35 by astalha           #+#    #+#             */
/*   Updated: 2023/01/17 02:24:44 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void    make_textures(t_infos *my_infos)
{
    int size = 64;
    my_infos->player = mlx_xpm_file_to_image(my_infos->mlx_ptr,"./textures/player.xpm",&size,&size);
    my_infos->space = mlx_xpm_file_to_image(my_infos->mlx_ptr,"./textures/space.xpm",&size,&size);
    my_infos->wall = mlx_xpm_file_to_image(my_infos->mlx_ptr,"./textures/wall.xpm",&size,&size);
    my_infos->collect = mlx_xpm_file_to_image(my_infos->mlx_ptr,"./textures/collecte.xpm",&size,&size);
    my_infos->exit = mlx_xpm_file_to_image(my_infos->mlx_ptr,"./textures/C_door.xpm",&size,&size);
}
void    place_images(t_infos    *my_infos)
{
    int i,j;
    i = 0;
    while (my_infos->matrix[i])
    {
        j = 0;
        while (my_infos->matrix[i][j])
        {
            if (my_infos->matrix[i][j] == '1')
                mlx_put_image_to_window(my_infos->mlx_ptr,my_infos->window_ptr,my_infos->wall,j * 64,i * 64);
            if (my_infos->matrix[i][j] == '0')
                mlx_put_image_to_window(my_infos->mlx_ptr,my_infos->window_ptr,my_infos->space,j * 64,i * 64);
            if (my_infos->matrix[i][j] == 'P')
                mlx_put_image_to_window(my_infos->mlx_ptr,my_infos->window_ptr,my_infos->player,j * 64,i * 64);
            if (my_infos->matrix[i][j] == 'C')
                mlx_put_image_to_window(my_infos->mlx_ptr,my_infos->window_ptr,my_infos->collect,j * 64,i * 64);
            if (my_infos->matrix[i][j] == 'E')
                mlx_put_image_to_window(my_infos->mlx_ptr,my_infos->window_ptr,my_infos->exit,j * 64,i * 64);
            j++;
        }
        i++;
    }
}

void    start(t_infos *my_infos)
{
    my_infos->mlx_ptr = mlx_init();
    make_textures(my_infos);
    my_infos->window_ptr = mlx_new_window(my_infos->mlx_ptr, (int)ft_strlen(my_infos->matrix[0]) * 64, matlen(my_infos->matrix) * 64, "so_long");
    place_images(my_infos);
    mlx_loop(my_infos->mlx_ptr);
}
int main(int    ac, char **av)
{
    t_infos     my_infos;

    my_infos.matrix = Matrix(ac, av, &my_infos);
    if (!my_infos.matrix)
        return (0);
        start(&my_infos);
    // dimenstions(my_infos.matrix);
   
}