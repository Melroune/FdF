/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 22:54:45 by akerkeb           #+#    #+#             */
/*   Updated: 2015/02/22 08:37:19 by akerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fln(t_env *e)
{
	if ((e->mlx = mlx_init()) == NULL)
		exit(1);
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "fenetre42");
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->str = mlx_get_data_addr(e->img, &(e->bpp), &(e->sl), &(e->endian));
}

int		expose_hook(t_env *e)
{
	draw(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

void	mlx(t_env *e)
{
	mlx_key_hook(e->win, key_hook, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop(e->mlx);
}

int		main(int ac, char **av)
{
	t_env e;

	e.xd = 450;
	e.yd = 200;
	e.zoom = 800;
	e.zm = 4;
	if (ac != 2)
	{
		ft_putstr_fd("Map error", 2);
		return (0);
	}
	e.fd = open(av[1], O_RDONLY);
	if (e.fd == -1)
		ft_putstr_fd("Map error", 2);
	else
	{
		ft_sizetab(e.fd, &e.xm, &e.ym);
		close(e.fd);
		e.fd = open(av[1], O_RDONLY);
		e.tab = ft_gridtab(e.fd, e.xm, &e.ym);
		close(e.fd);
		ft_fln(&e);
		mlx(&e);
	}
	return (0);
}
