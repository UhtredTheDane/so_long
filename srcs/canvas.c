/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:43:39 by agengemb          #+#    #+#             */
/*   Updated: 2023/01/12 02:11:04 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/canvas.h"

void	destroy_canvas(t_canvas *canvas)
{
	mlx_destroy_window(canvas->mlx, canvas->window);
	mlx_destroy_display(canvas->mlx);
	free(canvas->mlx);
	free(canvas);
}

t_canvas	*create_canvas(t_queue *queue, size_t line_nb, size_t row_nb)
{
	t_canvas	*new_canvas;

	new_canvas = malloc(sizeof(t_canvas));
	if (!new_canvas)
		return (NULL);
	new_canvas->mlx = mlx_init();
	if (!(new_canvas->mlx))
		return (NULL);
	new_canvas->window = mlx_new_window(new_canvas->mlx, row_nb * 48,
			line_nb * 48, "so_long");
	if (!(new_canvas->window))
	{
		free(new_canvas->mlx);
		free(new_canvas);
		return (NULL);
	}
	new_canvas->map = create_map(new_canvas->mlx, queue, line_nb, row_nb);
	if (!(new_canvas->map))
	{
		destroy_canvas(new_canvas);
		return (NULL);
	}
	return (new_canvas);
}
