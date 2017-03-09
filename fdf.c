/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 12:22:03 by akerkeb           #+#    #+#             */
/*   Updated: 2014/12/12 12:49:45 by akerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_sizetab(int fd, float *c, float *l)
{
	char	*line;
	char	**split;
	int		test;
	int		limit;

	*l = 0;
	*c = 0;
	while (get_next_line(fd, &line) == 1)
	{
		split = ft_strsplit(line, ' ');
		limit = 0;
		while (split[limit] != NULL)
			limit++;
		if (*l == 0)
			*c = limit;
		else if (*c != limit)
		{
			ft_putstr("map error\n");
			exit(-1);
		}
		(*l)++;
	}
	(*l)++;
}

void	ft_pp(t_env *e, char *line, int x, int i)
{
	int		j;

	e->split = ft_strsplit(line, ' ');
	j = 0;
	if (!(e->tab[i] = (int *)malloc(sizeof(int) * x)))
		return ;
	while (e->split[j])
	{
		e->tab[i][j] = ft_atoi(e->split[j]);
		j++;
	}
}

int		**ft_gridtab(int fd, int x, float *y)
{
	int		i;
	int		j;
	char	*line;
	t_env	e;

	i = 0;
	if (!(e.tab = (int **)malloc(sizeof(int *) * *y)))
		return (NULL);
	while (i < *y)
	{
		get_next_line(fd, &line);
		if (line[0] == '\0' && i != (*y - 1))
		{
			ft_putstr("Map error\n");
			exit (-1);
		}
		else if (line[0] == '\0' && i == (*y - 1))
			*y = (*y) - 1;
		else
		{
			ft_pp(&e, line, x, i);
		}
		i++;
	}
	return (e.tab);
}
