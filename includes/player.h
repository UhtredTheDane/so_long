/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 05:11:03 by agengemb          #+#    #+#             */
/*   Updated: 2023/01/11 05:12:24 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include <stddef.h>
# include "../mlx_linux/mlx.h"
# include "../ft_printf/includes/ft_printf.h"
# include "img.h"
# include "map.h"
# include "canvas.h"

typedef struct s_canvas	t_canvas;

typedef struct s_player
{
	size_t	i;
	size_t	j;
	size_t	direction;
	size_t	moves_nb;
	t_img	**sprites_set;
}	t_player;

t_player	*init_player(void *mlx, size_t i, size_t j);
void		make_move(t_canvas *canvas, t_player *player, size_t i, size_t j);
void		move_player(t_canvas *canvas, t_player *player, size_t direction);
#endif
