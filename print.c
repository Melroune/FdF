/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 12:04:31 by akerkeb           #+#    #+#             */
/*   Updated: 2014/12/12 12:51:31 by akerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mlx_img_put(t_env *e, t_pt2d *p)
{
	int		in;

	in = (e->bpp >> 3) * (((int)p->y * (e->sl >> 2)) + (int)p->x);
	if (in >= 0 && in <= (e->bpp >> 3) * (((int)HEIGHT * (e->sl >> 2)) +
	(int)WIDTH) && in > (e->bpp >> 3) * (((int)p->y * (e->sl >> 2))) &&
	in < (e->bpp >> 3) * (((int)p->y * (e->sl >> 2)) + WIDTH))
	{
		e->str[in + 0] = p->color & 0xff;
		e->str[in + 1] = (p->color & 0xff00) >> 8;
		e->str[in + 2] = (p->color & 0xff0000) >> 16;
	}
}

void	print_line_dx(t_env *env, t_d d, t_pt2d pt, t_pt2d pt2)
{
	int i;
	int error;

	i = 0;
	error = d.dx / 2;
	while (i < d.dx)
	{
		pt.x += d.xincr;
		error += d.dy;
		if (error > d.dx)
		{
			error -= d.dx;
			pt.y += d.yincr;
		}
		mlx_img_put(env, &pt);
		i++;
	}
}

void	print_line_dy(t_env *env, t_d d, t_pt2d pt, t_pt2d pt2)
{
	int i;
	int error;

	i = 0;
	error = d.dy / 2;
	while (i < d.dy)
	{
		pt.y += d.yincr;
		error += d.dx;
		if (error > d.dy)
		{
			error -= d.dy;
			pt.x += d.xincr;
		}
		mlx_img_put(env, &pt);
		i++;
	}
}

void	put_line(t_env *env, t_pt2d pt1, t_pt2d pt2, int color)
{
	t_d		d;

	d.xincr = 1;
	if (pt1.x > pt2.x)
		d.xincr = -1;
	pt1.color = color;
	d.yincr = 1;
	if (pt1.y > pt2.y)
		d.yincr = -1;
	d.dx = abs(pt2.x - pt1.x);
	d.dy = abs(pt2.y - pt1.y);
	mlx_img_put(env, &pt1);
	mlx_img_put(env, &pt2);
	if (d.dx > d.dy)
		print_line_dx(env, d, pt1, pt2);
	else
		print_line_dy(env, d, pt1, pt2);
}
