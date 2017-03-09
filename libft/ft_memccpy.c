/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerkeb <akerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 12:00:25 by akerkeb           #+#    #+#             */
/*   Updated: 2014/11/27 04:17:36 by akerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memccpy(void *dst, const void *src	, int c, size_t n)
{
	size_t		i;
	char		*dst2;
	const char	*src2;

	dst2 = dst;
	src2 = src;
	i = 0;
	while (i < n)
	{
		dst2[i] = src2[i];
		if (src2[i] == c)
		{
			return (dst + i + 1);
		}
		i++;
	}
	return (NULL);
}
