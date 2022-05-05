/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkitoko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 09:18:34 by gkitoko           #+#    #+#             */
/*   Updated: 2022/05/04 09:18:38 by gkitoko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <fcntl.h>
#include "./minilibx-linux/mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>
# include <unistd.h>
#include "ft_printf/ft_printf.h"
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

typedef struct s_map
{
	char **v_map;
	int v_width;
	int v_height;

} t_map;

typedef struct s_img
{
	void *v_img;
	char	*v_relative_path;
	int		v_img_width;
	int		v_img_height;

} t_img;

typedef struct s_data
{
	void	*v_mlx_ptr;
	void	*v_win_ptr;
	t_img	v_perso;

} t_data;

// FOR THE GET_NEXT_LINE/
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *str, int c);
char	*ft_get_line(char *save);
char	*ft_save(char *save);
char	*read_line(int fd, char *save);
char	*get_next_line(int fd);
size_t	ft_strlen( char *str);

// FOR THE CHECKERS/
void checker(int ac, char **ag);
void check_map_content(t_map map);
void check_if_map_is_rect(t_map map);
int is_wall(char *line);
void check_is_wall(t_map map);
int is_collector(char c);
int is_player(char p);
int is_collector(char c);
int is_exit(char e);
int valid_player(t_map map);
int valid_collector(t_map map);
int valid_exit(t_map map);

// FOR THE LIBFT/
int	ft_putstr_fd(char *s, int fd);
int	ft_putchar_fd(char c, int fd);
static int	ft_ischarset(char c, char sep);
static int	ft_countwords(char const *str, char sep);
static char	*ft_dup(char const *str, char sep);
char	**ft_split(char const *s, char c);
int	ft_strncmp(const char *str1, const char *str2, size_t n);

// FOR THE PROG_MANAGEMENT/
void	ft_error(void);
void	free_double_str(char **str);

// FOR THE MAIN/
int	handle_no_event(void *data);
int	handle_input(int keysym, t_data *data);
int	handle_keypress(int keysym, t_data *data);
int	handle_keyrelease(int keysym, void *data);
int	render(t_data *data);

# endif