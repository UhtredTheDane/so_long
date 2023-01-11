/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 05:13:41 by agengemb          #+#    #+#             */
/*   Updated: 2023/01/11 05:14:08 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHOW_H
# define SHOW_H

# include <stddef.h>
# include "../mlx_linux/mlx.h"
# include "canvas.h"
# include "data.h"
# include "so_long.h"

typedef struct s_canvas	t_canvas;

void	show_player(t_canvas *canvas, t_data *background, size_t i, size_t j);
void	show_block(t_canvas *canvas, t_data *background, size_t i, size_t j);
void	show_map(t_canvas *canvas);

#endif
