/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerkeb <akerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 16:19:10 by akerkeb           #+#    #+#             */
/*   Updated: 2014/11/27 01:41:49 by akerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*str;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (s && f)
	{
		str = (char *)malloc(sizeof(char) * ft_strlen((char *)s + 1));
		if (str == NULL)
			return (NULL);
		while (s[i] != '\0')
		{
			str[i] = f(j, s[i]);
			i++;
			j++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
