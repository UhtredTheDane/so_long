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