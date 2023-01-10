/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_recovery.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:34:24 by agengemb          #+#    #+#             */
/*   Updated: 2022/08/06 15:07:36 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	char_recovery(va_list *it)
{
	char	c;

	c = va_arg(*it, int);
	ft_putchar_fd(c, 1);
	return (1);
}
