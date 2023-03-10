/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 04:40:47 by agengemb          #+#    #+#             */
/*   Updated: 2023/01/11 04:47:04 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/player.h"

t_player	*init_player(void *mlx, size_t i, size_t j)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->i = i;
	player->j = j;
	player->direction = 2;
	player->moves_nb = 0;
	player->sprites_set = malloc(sizeof(t_img) * 4);
	if (!player->sprites_set)
		return (NULL);
	player->sprites_set[0] = init_img(mlx, "Images/Sprites/XPM/t_player.xpm");
	player->sprites_set[1] = init_img(mlx, "Images/Sprites/XPM/r_player.xpm");
	player->sprites_set[2] = init_img(mlx, "Images/Sprites/XPM/b_player.xpm");
	player->sprites_set[3] = init_img(mlx, "Images/Sprites/XPM/l_player.xpm");
	if (!player->sprites_set[0] || !player->sprites_set[1]
		|| !player->sprites_set[2] || !player->sprites_set[3])
	{
		free_set(mlx, player->sprites_set, 4);
		free(player);
		return (NULL);
	}
	return (player);
}

void	move_player(t_canvas *canvas, t_player *player, size_t direction)
{
	player->direction = direction;
	if (direction == 0)
		make_move(canvas, player, player->i - 1, player->j);
	else if (direction == 1)
		make_move(canvas, player, player->i, player->j + 1);
	else if (direction == 2)
		make_move(canvas, player, player->i + 1, player->j);
	else
		make_move(canvas, player, player->i, player->j - 1);
}

void	make_move(t_canvas *canvas, t_player *player, size_t i, size_t j)
{
	if (canvas->map->block_map[i][j].type != '1')
	{
		canvas->map->block_map[player->i][player->j].type = '0';
		player->i = i;
		player->j = j;
		if (canvas->map->block_map[i][j].type == 'C')
		{
			canvas->map->block_map[i][j].type = '0';
			canvas->map->block_map[i][j].img = canvas->map->tiles_set[0];
			--canvas->map->collectibles_nb;
		}
		else if (&(canvas->map->block_map[i][j]) == canvas->map->exit)
		{
			if (!canvas->map->collectibles_nb)
			{
				canvas->map->block_map[i][j].type = 'P';
				show_map(canvas);
				ft_printf("Bravo, vous avez gagn?? !\n");
				ft_exit(canvas);
			}
		}
		canvas->map->block_map[i][j].type = 'P';
		++player->moves_nb;
		ft_printf("Vous avez fait %d mouvements.\n", player->moves_nb);
	}
}
