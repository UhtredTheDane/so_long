/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:43:38 by agengemb          #+#    #+#             */
/*   Updated: 2022/12/19 13:45:44 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H

# include <stdlib.h>
# include <stddef.h>
# include "../mlx_linux/mlx.h"
# include "map.h"
# include "queue.h"


typedef struct s_canvas
{
	void *mlx;
	void *window;	
	t_map	*map;
}			t_canvas;

t_canvas *create_canvas(t_queue *queue, size_t line_nb, size_t  row_nb);

#endif
