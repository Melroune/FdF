/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerkeb <akerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 14:57:01 by akerkeb           #+#    #+#             */
/*   Updated: 2014/11/27 01:09:22 by akerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_length(int nb)
{
	int length;

	if (nb >= 0)
		length = 1;
	else
		length = 2;
	while (nb >= 10 || nb <= -10)
	{
		nb = nb / 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*result;
	int		sign;

	sign = 1;
	i = ft_length(n);
	if (n < 0)
		sign = -1;
	result = (char *)ft_memalloc(sizeof(char) * i + 1);
	if (result == NULL)
		return (NULL);
	result[i--] = '\0';
	while (i >= (sign < 0) ? 1 : 0)
	{
		if (n < 0)
			result[i] = (-(n % 10) + '0');
		if (n >= 0)
			result[i] = ((n % 10) + '0');
		n = n / 10;
		i--;
	}
	if (sign < 0)
		result[0] = '-';
	return (result);
}
