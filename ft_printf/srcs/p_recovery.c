/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_recovery.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:32:19 by agengemb          #+#    #+#             */
/*   Updated: 2022/08/06 15:08:35 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	p_recovery(va_list *it)
{
	void	*p;
	char	*s;
	size_t	size;

	p = va_arg(*it, void *);
	if (!p)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	s = hexa_convert((unsigned long) p);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(s, 1);
	size = ft_strlen(s) + 2;
	free(s);
	return (size);
}
