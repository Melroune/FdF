/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerkeb <akerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 21:33:02 by akerkeb           #+#    #+#             */
/*   Updated: 2014/12/13 00:22:52 by akerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <mlx.h>
# include "libft.h"
# include <stdio.h>
# include <math.h>

# define HEIGHT 1300
# define WIDTH 1300

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	int			**tab;
	float		ym;
	float		xm;
	char		*str;
	int			bpp;
	int			sl;
	int			endian;
	int			xd;
	int			yd;
	int			zoom;
	float		zm;
	int			x;
	int			y;
	int			fd;
	char		**split;
}				t_env;

typedef struct	s_delta
{
	int			dx;
	int			dy;
	int			yincr;
	int			xincr;
}				t_d;

typedef struct	s_pt2d
{
	float		x;
	float		y;
	int			z;
	int			color;
}				t_pt2d;

int				get_next_line(int fd, char **line);
char			**ft_strsplit(char const *s, char c);
void			ft_sizetab(int fd, float *c, float *l);
int				**ft_gridtab(int fd, int x, float *y);
int				ft_atoi(const char *str);
void			put_line(t_env *env, t_pt2d pt1, t_pt2d pt2, int color);
void			print_line_dx(t_env *env, t_d d, t_pt2d pt, t_pt2d pt2);
int				expose_hook(t_env *e);
void			ft_fln(t_env *e);
int				key_hook(int keycode, t_env *e);
void			draw(t_env *env);
int				key_hook(int keycode, t_env *env);
void			ft_zoom(int keycode, t_env *e);
int				expose_hook(t_env *env);

#endif
