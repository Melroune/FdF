/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerkeb <akerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 16:31:23 by akerkeb           #+#    #+#             */
/*   Updated: 2014/11/27 08:52:55 by akerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

static int		ft_is_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\t' || c == '\r' || c == '\f'
	|| c == '\v');
}

char			*ft_strtrim(char const *s)
{
	char	*res;
	int		start;
	int		end;
	int		i;

	start = 0;
	if (!s)
		return (NULL);
	while (s && ft_is_space(s[start]))
		start++;
	end = ft_strlen((char *)s) - 1;
	res = (char *)malloc(sizeof(char) * (end - start + 1));
	while (s && ft_is_space(s[end]))
		end--;
	if (res && s)
	{
		i = -1;
		while ((++i + start) <= end)
			res[i] = s[start + i];
		res[i] = 0;
		return (res);
	}
	return (NULL);
}
