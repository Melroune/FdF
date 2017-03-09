/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerkeb <akerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 16:05:07 by akerkeb           #+#    #+#             */
/*   Updated: 2014/11/27 01:39:42 by akerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void *ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*s2;

	if (s == NULL)
		return (NULL);
	s2 = (char *)s;
	i = 0;
	while (i < n)
	{
		if (s2[i] == (char)c)
			return ((void *)&s2[i]);
		i++;
	}
	return (NULL);
}
