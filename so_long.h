/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:26:15 by astalha           #+#    #+#             */
/*   Updated: 2023/01/19 00:34:51 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <mlx.h>
#include "./ft_printf/ft_printf.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define K_UP 126
# define K_LT 123
# define K_RT 124
# define K_DN 125
# define K_EX 53

typedef  struct s_infos
{
    char    **matrix;
    char    **copy;
    void    *window_ptr;
    void    *mlx_ptr;
    void    *player;
    void    *s_player;
    void    *space;
    void    *wall;
    void    *collect;
    void    *c_exit;
    void    *o_exit;
    int     steps;
    int     stat;
    int     col;
    int     xp;
    int     yp;
}               t_infos;

//get
int		check(char *line);
size_t	ft_strlen(const char	*str);
void	ft_strlcpy(char *dst, char *src, size_t dstsize);
void	cpy(char *s1, char *s2, int j);
char	*join(char *s1, char *s2);
char	*justrest(char *hold);
char	*get_the_line(char *hold);
char	*ft_strdup(char *src);
char	*get_next_line(int fd);

char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void    ft_putstr_fd(char *s, int fd);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *s, char c);
int     ft_strchr(char *s, char c);

char *one_string(int ac, char **av);
char    **Matrix(int    ac, char **av, t_infos *my_infos);
int     checkwals(char **matrix);
int check_PCE(char **matrix);
int checkshape(char **matrix);
int     check_for_impopsters(char *str);
int checkERROR(char **matrix);
int     valid_path(t_infos  *my_infos);

int     matlen(char **matrix);
int     lines_1(char *str);
int     collums_1(char    **matrix, int j);
int     counter(char **matrix, char c);
void    get_pos(t_infos *my_infos,char c);

#endif