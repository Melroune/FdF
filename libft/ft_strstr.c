/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerkeb <akerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:32:09 by akerkeb           #+#    #+#             */
/*   Updated: 2014/11/27 00:29:07 by akerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		k;

	i = 0;
	if (!s1)
		return (NULL);
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		k = 0;
		while (s1[i + k] && s2[k] && s1[i + k] == s2[k])
			k++;
		if (s2[k] == '\0')
			return ((char *)&s1[i]);
		i++;
	}
	return (NULL);
}
