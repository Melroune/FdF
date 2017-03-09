/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerkeb <akerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 22:06:39 by akerkeb           #+#    #+#             */
/*   Updated: 2014/12/01 07:00:04 by akerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

static int		ft_cont(char const *str1, char c)
{
	int		j;
	int		k;

	j = 0;
	k = 0;
	while (str1[j] != '\0')
	{
		while (str1[j] == c)
			j++;
		if (str1[j] == '\0')
			k--;
		while (str1[j] != c && str1[j] != '\0')
			j++;
		k++;
	}
	return (k);
}

static int		ft_strclen(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	m;
	int		nbr;
	char	**str;

	m = 0;
	if (!s || !c)
		return (NULL);
	nbr = ft_cont(s, c);
	str = (char **)malloc(sizeof(char *) * ((size_t)nbr + 1));
	if (!str || s == 0)
		return (NULL);
	while (nbr--)
	{
		while (*s == c && *s != '\0')
			s++;
		str[m] = ft_strsub((const char *)s, 0, ft_strclen((char *)s, c));
		if (str[m] == NULL)
			return (NULL);
		s += ft_strclen((char *)s, c);
		m++;
	}
	str[m] = NULL;
	return (str);
}
