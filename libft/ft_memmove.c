/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerkeb <akerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 06:35:49 by akerkeb           #+#    #+#             */
/*   Updated: 2014/11/27 01:18:23 by akerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

void *ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = (char *)malloc(len * sizeof(char));
	if (tmp == NULL)
		return (dst);
	while (i < len && dst && src)
	{
		tmp[i] = ((char *)src)[i];
		i++;
	}
	i = 0;
	while (i < len && dst && src)
	{
		((char*)dst)[i] = tmp[i];
		i++;
	}
	free(tmp);
	return (dst);
}
