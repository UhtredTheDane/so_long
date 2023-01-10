/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:18:06 by agengemb          #+#    #+#             */
/*   Updated: 2022/08/06 15:08:07 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	count_numbers(unsigned int n)
{
	size_t	res;

	if (n == 0)
		return (1);
	res = 0;
	while (n != 0)
	{
		n /= 10;
		res++;
	}
	return (res);
}

static char	*make_string(unsigned int n)
{
	char	*res;
	int		i;
	int		reste;
	size_t	size;

	size = count_numbers(n);
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	i = size;
	res[i] = '\0';
	while (--i >= 0)
	{
		reste = n % 10;
		res[i] = reste + '0';
		n /= 10;
	}
	return (res);
}

char	*ft_utoa(unsigned int n)
{
	return (make_string(n));
}
