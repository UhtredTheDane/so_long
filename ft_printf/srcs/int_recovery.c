/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_recovery.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:32:41 by agengemb          #+#    #+#             */
/*   Updated: 2022/08/06 15:08:27 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	int_recovery(char c, va_list *it)
{
	char	*s;
	int		size;

	if (c == 'u')
		s = ft_utoa((va_arg(*it, unsigned int)));
	else
		s = ft_itoa(va_arg(*it, int));
	ft_putstr_fd(s, 1);
	size = ft_strlen(s);
	free(s);
	return (size);
}
