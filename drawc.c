/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/06 06:01:36 by akerkeb           #+#    #+#             */
/*   Updated: 2014/12/12 14:22:51 by akerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_one(t_env *e, t_pt2d pt1, t_pt2d pt2)
{
	pt2.x = e->xd + (e->x + 1 - e->y) * ((1 / e->xm) * e->zoom) + e->ym / 2;
	pt2.y = e->yd + (e->x + 1 + e->y) * ((1 / e->xm) * e->zoom) / 2 -
	(e->tab[e->y][e->x + 1] * e->zm);
	if (e->tab[e->y][e->x] > 5 && e->tab[e->y][e->x + 1] > 5)
		put_line(e, pt1, pt2, 0xFFF8DC);
	else if (e->tab[e->y][e->x] > 5 || e->tab[e->y][e->x + 1] > 5)
		put_line(e, pt1, pt2, 0xCD853F);
	else
		put_line(e, pt1, pt2, 0x228B22);
}

void	draw_two(t_env *e, t_pt2d pt1, t_pt2d pt2)
{
	pt2.x = e->xd + (e->x - (e->y + 1)) * ((1 / e->xm) * e->zoom) + e->ym / 2;
	pt2.y = e->yd + (e->x + e->y + 1) *
	(1 / e->xm) * e->zoom / 2 - (e->tab[e->y + 1][e->x] * e->zm);
	if (e->tab[e->y][e->x] > 5 && e->tab[e->y + 1][e->x] > 5)
		put_line(e, pt1, pt2, 0xFFF8DC);
	else if (e->tab[e->y][e->x] > 5 || e->tab[e->y + 1][e->x] > 5)
		put_line(e, pt1, pt2, 0xCD853F);
	else
		put_line(e, pt1, pt2, 0x228B22);
}

void	draw(t_env *e)
{
	int		color;
	t_pt2d	pt1;
	t_pt2d	pt2;

	e->y = 0;
	while (e->y < e->ym)
	{
		e->x = 0;
		while (e->x < e->xm)
		{
			pt1.x = e->xd + (e->x - e->y) * ((1 / e->xm) * e->zoom)
			+ e->ym / 2;
			pt1.y = e->yd + (e->x + e->y) * ((1 / e->xm) * e->zoom) / 2 -
			(e->tab[e->y][e->x] * e->zm);
			if (e->x < e->xm - 1)
				draw_one(e, pt1, pt2);
			if (e->y < e->ym - 1)
				draw_two(e, pt1, pt2);
			e->x++;
		}
		e->y++;
	}
}

void	ft_zoom(int keycode, t_env *e)
{
	if (keycode == 65453 && e->zm != 0.5)
	{
		e->zoom -= 100;
		e->zm -= 0.5;
	}
	if (keycode == 65451)
	{
		e->zoom += 100;
		e->zm += 0.5;
	}
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 65307)
		exit(0);
	if (keycode <= 65364 && keycode >= 65361 || keycode == 65451 ||
		keycode == 65453)
	{
		if (keycode == 65361)
			e->xd += 25;
		if (keycode == 65362)
			e->yd += 25;
		if (keycode == 65363)
			e->xd -= 25;
		if (keycode == 65364)
			e->yd -= 25;
		ft_zoom(keycode, e);
		mlx_destroy_image(e->mlx, e->img);
		e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
		mlx_clear_window(e->mlx, e->win);
		expose_hook(e);
	}
	return (0);
}
