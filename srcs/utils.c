/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 22:12:57 by agengemb          #+#    #+#             */
/*   Updated: 2023/01/11 01:45:29 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	keyboard_manage(int keycode, t_canvas *canvas)
{
	if (keycode == XK_Escape)
		ft_exit(canvas);
	else if (keycode == XK_w)
		move_player(canvas, canvas->map->player, 0);
	else if (keycode == XK_d)
		move_player(canvas, canvas->map->player, 1);
	else if (keycode == XK_s)
		move_player(canvas, canvas->map->player, 2);
	else if (keycode == XK_a)
		move_player(canvas, canvas->map->player, 3);
	show_map(canvas);
}

int is_alpha(int color)
{
	return ((color >> 24)& 0xFF);
}

/*
 *Description:
 *
 * Calculates the length of the string pointed to by s, 
 * excluding the terminating null byte.
 */

size_t	ft_strlen2(const char *s)
{
	size_t	length;

	length = 0;
	while (*(s + length))
		length++;
	return (length);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void free_queue(t_queue *queue)
{
	while (!queue)
		queue_pop(&queue);
}
