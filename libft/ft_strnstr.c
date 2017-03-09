/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerkeb <akerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 12:06:14 by akerkeb           #+#    #+#             */
/*   Updated: 2014/11/27 01:47:32 by akerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s2 == NULL || s2[0] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		if (i == n)
			return (NULL);
		if (s2[j] == s1[i])
			j++;
		else
			j = 0;
		if (s2[j] == '\0')
			return ((char *)&s1[i - (j - 1)]);
		i++;
	}
	return (NULL);
}
