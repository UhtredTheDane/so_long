/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_recovery.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:55:17 by agengemb          #+#    #+#             */
/*   Updated: 2022/08/06 15:08:19 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	ft_toupper_bis(unsigned int i, char c)
{
	(void) i;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

char	*hexa_upper_case(char *s)
{
	char	*res;

	res = ft_strmapi(s, &ft_toupper_bis);
	free(s);
	return (res);
}

char	*hexa_convert(unsigned long n)
{
	size_t			size;
	unsigned long	n_bis;
	char			*hexa_base;
	char			*hexa_nb;

	hexa_base = "0123456789abcdef";
	size = 0;
	n_bis = n;
	while (n_bis)
	{
		n_bis /= 16;
		size++;
	}
	hexa_nb = malloc(sizeof(char) * (size + 1));
	if (!hexa_nb)
		return (NULL);
	*(hexa_nb + size) = '\0';
	while (n)
	{
		*(hexa_nb + --size) = hexa_base[n % 16];
		n /= 16;
	}
	return (hexa_nb);
}

size_t	hexa_recovery(char c, va_list *it)
{
	unsigned int	integer;
	size_t			size;
	char			*s;

	integer = va_arg(*it, unsigned int);
	size = 1;
	if (integer != 0)
	{
		s = hexa_convert(integer);
		if (!s)
			return (0);
		if (c == 'X')
		{
			s = hexa_upper_case(s);
			if (!s)
				return (0);
		}
		ft_putstr_fd(s, 1);
		size = ft_strlen(s);
		free(s);
	}
	else
		ft_putstr_fd("0", 1);
	return (size);
}
