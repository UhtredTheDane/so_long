#include "../includes/player.h"

t_player *init_player(void *mlx, size_t i, size_t j)
{
    t_player *player;

    player = malloc(sizeof(t_player));
    if (!player)
        return (NULL);
    player->i = i;
    player->j = j;
    player->direction = 2;
	player->moves_nb = 0;
    player->sprites_set[0] = init_new_img(mlx, "Images/Sprites/XPM/top_player.xpm");
	if (!player->sprites_set[0])
		return (NULL);
	player->sprites_set[1] = init_new_img(mlx, "Images/Sprites/XPM/right_player.xpm");
	if (!player->sprites_set[1])
	{
		free_set(mlx, player->sprites_set, 1);
		return (NULL);
	}
	player->sprites_set[2] = init_new_img(mlx, "Images/Sprites/XPM/bot_player.xpm");
	if (!player->sprites_set[2])
	{
		free_set(mlx, player->sprites_set, 2);
		return (NULL);
	}
	player->sprites_set[3] = init_new_img(mlx, "Images/Sprites/XPM/left_player.xpm");
	if (!player->sprites_set[3])
	{
		free_set(mlx, player->sprites_set, 3);
		return (NULL);
	}
	return (player);
}

void move_player(t_canvas *canvas, t_player *player, size_t direction)
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

void make_move(t_canvas *canvas, t_player *player, size_t i, size_t j)
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
		else if (canvas->map->block_map[i][j].type == 'E')	
		{
			if (!canvas->map->collectibles_nb)
			{
				canvas->map->block_map[i][j].type = 'P';
				show_map(canvas);
				printf("Bravo, vous avez gagné !\n");
				exit(0);
				//clean_exit()
			}
		}
		canvas->map->block_map[i][j].type = 'P';
		++player->moves_nb;
		printf("Vous avez fait %ld mouvements.\n", player->moves_nb);
	} 
}
