/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerkeb <akerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:42:45 by akerkeb           #+#    #+#             */
/*   Updated: 2014/11/17 15:45:08 by akerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
	int i;
	int mem;

	i = 0;
	mem = -1;
	while (s[i] != '\0')
	{
		if ((char)c == s[i])
			mem = i;
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	if (mem != -1)
		return ((char *)&s[mem]);
	return (NULL);
}
