/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 22:12:57 by agengemb          #+#    #+#             */
/*   Updated: 2022/11/28 22:17:28 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
 * Description:
 *
 * Copy up to size - 1 characters form the NUL-terminated string src to dst, 
 * NUL-terminating the result.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && *(src + i))
		{
			*(dst + i) = *(src + i);
			i++;
		}
		*(dst + i) = '\0';
	}
	while (*(src + i))
		i++;
	return (i);
}

/*
 *Description:
 *
 * Calculates the length of the string pointed to by s, 
 * excluding the terminating null byte.
 */

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (*(s + length))
		length++;
	return (length);
}
