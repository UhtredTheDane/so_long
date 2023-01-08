/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:00:21 by agengemb          #+#    #+#             */
/*   Updated: 2023/01/08 04:58:45 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include "../mlx_linux/mlx.h"
#include <X11/keysym.h>
# include "canvas.h"
# include "data.h"
# include "checks.h"
# include "show.h"

typedef struct s_canvas t_canvas;

int	keyboard_manage(int keycode, t_canvas *canvas);
int is_alpha(int color);
size_t	ft_strlen(const char *s);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void    free_queue(t_queue *queue);
int close_window(t_canvas *canvas);

#endif
