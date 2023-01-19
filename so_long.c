/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:23:35 by astalha           #+#    #+#             */
/*   Updated: 2023/01/19 01:30:54 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void    make_textures(t_infos *my_infos)
{
    int size = 64;
    my_infos->player = mlx_xpm_file_to_image(my_infos->mlx_ptr,"./textures/player.xpm",&size,&size);
    my_infos->s_player = mlx_xpm_file_to_image(my_infos->mlx_ptr,"./textures/S_player.xpm",&size,&size);
    my_infos->space = mlx_xpm_file_to_image(my_infos->mlx_ptr,"./textures/space.xpm",&size,&size);
    my_infos->wall = mlx_xpm_file_to_image(my_infos->mlx_ptr,"./textures/wall.xpm",&size,&size);
    my_infos->collect = mlx_xpm_file_to_image(my_infos->mlx_ptr,"./textures/collecte.xpm",&size,&size);
    my_infos->c_exit = mlx_xpm_file_to_image(my_infos->mlx_ptr,"./textures/C_door.xpm",&size,&size);
    my_infos->o_exit = mlx_xpm_file_to_image(my_infos->mlx_ptr,"./textures/O_door.xpm",&size,&size);
    if (!my_infos->player || !my_infos->s_player || !my_infos->space || !my_infos->wall || !my_infos->collect || !my_infos->c_exit|| !my_infos->o_exit)
        exit(0);
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
            {
                if (!my_infos->col)
                    mlx_put_image_to_window(my_infos->mlx_ptr,my_infos->window_ptr,my_infos->player,j * 64,i * 64);
                else
                    mlx_put_image_to_window(my_infos->mlx_ptr,my_infos->window_ptr,my_infos->s_player,j * 64,i * 64);
            }
            if (my_infos->matrix[i][j] == 'C')
                mlx_put_image_to_window(my_infos->mlx_ptr,my_infos->window_ptr,my_infos->collect,j * 64,i * 64);
            if (my_infos->matrix[i][j] == 'E')
            {
                if (!my_infos->col)
                    mlx_put_image_to_window(my_infos->mlx_ptr,my_infos->window_ptr,my_infos->o_exit,j * 64,i * 64);
                else
                    mlx_put_image_to_window(my_infos->mlx_ptr,my_infos->window_ptr,my_infos->c_exit,j * 64,i * 64);
            }
            j++;
        }
        i++;
    }
}
void    get_pos(t_infos *my_infos,char c)
{
    int i = 0;
    int j;

    while (my_infos->matrix[i])
    {
        j = 0;
        while(my_infos->matrix[i][j])
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

void    mov_up(t_infos *my_infos)
{
    if (my_infos->matrix[my_infos->xp - 1][my_infos->yp] == 'E' && my_infos->stat)
        exit(0);
    if (my_infos->matrix[my_infos->xp - 1][my_infos->yp] == '1' || my_infos->matrix[my_infos->xp - 1][my_infos->yp] == 'E')
        return ;
    else
    {
        if (my_infos->matrix[my_infos->xp - 1][my_infos->yp] == 'C')
            my_infos->col--;
        my_infos->matrix[my_infos->xp - 1][my_infos->yp] = 'P';
        my_infos->matrix[my_infos->xp][my_infos->yp] = '0';
        my_infos->xp -= 1;
         my_infos->steps++;
        ft_printf("steps : %d\n",my_infos->steps);
    }
}
void    mov_dn(t_infos *my_infos)
{
     if (my_infos->matrix[my_infos->xp + 1][my_infos->yp] == 'E' && my_infos->stat)
        exit(0);
    if (my_infos->matrix[my_infos->xp + 1][my_infos->yp] == '1' || my_infos->matrix[my_infos->xp + 1][my_infos->yp] == 'E')
        return ;
    else
    {
        if (my_infos->matrix[my_infos->xp + 1][my_infos->yp] == 'C')
            my_infos->col--;
        my_infos->matrix[my_infos->xp + 1][my_infos->yp] = 'P';
        my_infos->matrix[my_infos->xp][my_infos->yp] = '0';
        my_infos->xp += 1;
         my_infos->steps++;
        ft_printf("steps : %d\n",my_infos->steps);
    }
}
void    mov_rt(t_infos *my_infos)
{
     if (my_infos->matrix[my_infos->xp][my_infos->yp + 1] == 'E' && my_infos->stat)
        exit(0);
    if (my_infos->matrix[my_infos->xp][my_infos->yp + 1] == '1' || my_infos->matrix[my_infos->xp][my_infos->yp + 1] == 'E')
        return ;
    else
    {
        if (my_infos->matrix[my_infos->xp][my_infos->yp + 1] == 'C')
            my_infos->col--;
        my_infos->matrix[my_infos->xp][my_infos->yp + 1] = 'P';
        my_infos->matrix[my_infos->xp][my_infos->yp] = '0';
        my_infos->yp += 1;
         my_infos->steps++;
        ft_printf("steps : %d\n",my_infos->steps);
    }
}
void    mov_lt(t_infos *my_infos)
{
    if (my_infos->matrix[my_infos->xp][my_infos->yp - 1] == 'E' && my_infos->stat)
        exit(0);
    if (my_infos->matrix[my_infos->xp][my_infos->yp - 1] == '1' || my_infos->matrix[my_infos->xp][my_infos->yp - 1] == 'E')
        return ;
    else
    {
        if (my_infos->matrix[my_infos->xp][my_infos->yp - 1] == 'C')
            my_infos->col--;
        my_infos->matrix[my_infos->xp][my_infos->yp - 1] = 'P';
        my_infos->matrix[my_infos->xp][my_infos->yp] = '0';
        my_infos->yp -= 1;
        my_infos->steps++;
        ft_printf("steps : %d\n",my_infos->steps);
    }
}
int     key_movs(int    key, t_infos  *my_infos)
{
    mlx_clear_window(my_infos->mlx_ptr, my_infos->window_ptr);
    if (key == K_UP)
        mov_up(my_infos);
    if (key == K_DN)
        mov_dn(my_infos);
    if (key == K_RT)
        mov_rt(my_infos);
    if (key == K_LT)
        mov_lt(my_infos);
    if (key == K_EX)
        return ( mlx_destroy_window(my_infos->mlx_ptr, my_infos->window_ptr), exit(0), 0);
    if (!my_infos->col)
        my_infos->stat = 1;
      place_images(my_infos);  
        return 0;
}
void    start(t_infos *my_infos)
{
    my_infos->mlx_ptr = mlx_init();
    make_textures(my_infos);
    get_pos(my_infos,'P');
    my_infos->steps = 0;
    my_infos->col = counter(my_infos->matrix, 'C');
    my_infos->stat = 0;
    my_infos->window_ptr = mlx_new_window(my_infos->mlx_ptr, (int)ft_strlen(my_infos->matrix[0]) * 64, matlen(my_infos->matrix) * 64, "so_long");
    place_images(my_infos);
    mlx_key_hook(my_infos->window_ptr, key_movs, my_infos);
    mlx_loop(my_infos->mlx_ptr);
}

int main(int    ac, char **av)
{
    t_infos     my_infos;

    my_infos.matrix = Matrix(ac, av, &my_infos);
    if (!my_infos.matrix)
        return (0);
    if (!valid_path(&my_infos))
        exit(0);
    start(&my_infos);
}