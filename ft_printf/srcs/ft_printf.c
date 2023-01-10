/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 16:45:00 by agengemb          #+#    #+#             */
/*   Updated: 2022/08/06 15:07:53 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	printf_menu(char c, va_list *it)
{
	if (c == 'c')
		return (char_recovery(it));
	else if (c == 's')
		return (str_recovery(it));
	else if (c == 'p')
		return (p_recovery(it));
	else if (c == 'd' || c == 'i' || c == 'u')
		return (int_recovery(c, it));
	else if (c == 'x' || c == 'X')
		return (hexa_recovery(c, it));
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	it;
	size_t	i;
	int		size;

	if (format == NULL)
		return (-1);
	va_start(it, format);
	i = 0;
	size = 0;
	while (*(format + i))
	{
		if (*(format + i) == '%')
			size += printf_menu(*(format + ++i), &it);
		else
		{
			ft_putchar_fd(*(format + i), 1);
			size++;
		}
		i++;
	}
	return (size);
}
