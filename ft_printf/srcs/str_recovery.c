/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_recovery.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:34:37 by agengemb          #+#    #+#             */
/*   Updated: 2022/08/06 15:08:52 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	str_recovery(va_list *it)
{
	char	*s;

	s = va_arg(*it, char *);
	if (!s)
		s = "(null)";
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}
