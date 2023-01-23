/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:26:15 by astalha           #+#    #+#             */
/*   Updated: 2023/01/23 18:29:22 by astalha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define K_UP 126
# define K_LT 123
# define K_RT 124
# define K_DN 125
# define K_EX 53

typedef struct s_enemy
{
	int	ey;
	int	ex;
}			t_enemy;

typedef struct s_infos
{
	char	**matrix;
	char	**copy;
	void	*window_ptr;
	void	*mlx_ptr;
	void	*player;
	void	*s_player;
	void	*space;
	void	*wall;
	void	*collect;
	void	*mid_collecte;
	void	*big_collecte;
	void	*c_exit;
	void	*o_exit;
	void	*enemy;
	int		game_stat;
	int		steps;
	int		stat;
	int		col;
	int		xp;
	int		yp;
	int		num_en;
	int		collecte_stat;
	t_enemy	*en;
}				t_infos;

//printf
int			ft_printf(const char *format, ...);
void		put_char(char c, int *len);
void		ft_putadd(unsigned long long n, int *len);
void		print_hex(unsigned int n, int *len, char uplow);
void		ft_putnbr(int n, int *len);
void		ft_put_u(unsigned int nb, int *len);
void		ft_putstr(char *str, int *len);

//get
int			check(char *line);
size_t		ft_strlen(const char	*str);
void		ft_strlcpy(char *dst, char *src, size_t dstsize);
void		cpy(char *s1, char *s2, int j);
char		*join(char *s1, char *s2);
char		*justrest(char *hold);
char		*get_the_line(char *hold);
char		*ft_strdup(char *src);
char		*get_next_line(int fd);
//libft
char		**ft_split(char const *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		ft_putstr_fd(char *s, int fd);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strrchr(const char *s, char c);
int			ft_strchr(char *s, char c);
//parcing
char		*one_string(int ac, char **av);
char		**matrix(int ac, char **av, t_infos *my_infos);
int			checkwals(char **matrix);
int			check_pce(char **matrix);
int			checkshape(char **matrix);
int			check_for_impopsters(char *str);
int			checkerror(char **matrix);
int			valid_path(t_infos *my_infos);
int			matlen(char **matrix);
int			lines_1(char *str);
int			collums_1(char **matrix, int j);
int			counter(char **matrix, char c);
void		get_pos(t_infos *my_infos, char c);
//free
void		freealloc2(char **ptr);
int			close_window(t_infos *my_infos);
//movs
void		mov_up(t_infos *my_infos);
void		mov_dn(t_infos *my_infos);
void		mov_rt(t_infos *my_infos);
void		mov_lt(t_infos *my_infos);
int			key_movs(int key, t_infos *my_infos);
//make_imgs
void		make_textures(t_infos *my_infos);
void		image_to_window(t_infos *my_infos, char obj, int j, int i);
void		find_img(t_infos *my_infos, int j, int i);
void		place_images(t_infos *my_infos);
void		get_pos(t_infos *my_infos, char c);
void		start(t_infos *my_infos);

void		mov_en_up(t_infos *my_infos);
void		mov_en_dn(t_infos *my_infos);
void		mov_en_rt(t_infos *my_infos);
void		mov_en_lt(t_infos *my_infos);
char		*ft_itoa(int n);

void		print_uwon(void);
void		print_ulost(void);
void		print_msg(t_infos *my_infos);
int			close_x(t_infos *my_infos);
int			close_window(t_infos *my_infos);
void		enemy_event(t_infos *my_infos, void fct(), int stat);
int			mov_enemy(t_infos *my_infos);
void		find_ennemy(t_infos	*my_infos);
int			conditions(t_infos *my_infos, int x, int y);
void		img_to_win(t_infos *my_infos, void *obj, int j, int i);
int			if_not_works(t_infos *my_infos);
void		find_collect(t_infos *my_infos, int j, int i);

#endif
