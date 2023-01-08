#include "../includes/show.h"

void show_player(t_canvas *canvas, t_data *background, size_t i, size_t j)
{
	t_data player;
	int pixel;
	size_t x;
	size_t y;

	if (canvas->map->player->direction == 0)
		player.img = canvas->map->player->sprites_set[0]->img;
	else if (canvas->map->player->direction == 1)
		player.img = canvas->map->player->sprites_set[1]->img;
	else if (canvas->map->player->direction == 2)
		player.img = canvas->map->player->sprites_set[2]->img;
	else
		player.img = canvas->map->player->sprites_set[3]->img;
	player.addr = mlx_get_data_addr(player.img, &player.bits_per_pixel, &player.line_length, &player.endian);
	pixel = 0;
	y = 0;
	while (y < 40)
	{
		x = 0;
		while (x < 17)
		{
			pixel = y * player.line_length + x * (player.bits_per_pixel / 8);
			if (!is_alpha(*(int *)(player.addr + pixel)))
				my_mlx_pixel_put(background, x + 50 * j, y + 48 * i, *(int *)(player.addr + pixel));
			++x;
		}
		++y;
	}
}

void show_block(t_canvas *canvas, t_data *background, size_t i, size_t j)
{
	t_data block;
	size_t	y;
	size_t	x;
	int	pixel;

	block.img = canvas->map->block_map[i][j].img->img;
	block.addr = mlx_get_data_addr(block.img, &block.bits_per_pixel, &block.line_length, &block.endian);
	y = 0;
	while (y < 48)
	{
		x = 0;
		while (x < 48)
		{
			pixel = y * block.line_length + x * (block.bits_per_pixel / 8);
			my_mlx_pixel_put(background, x + 48 * j , y + 48 * i, *(int *)(block.addr + pixel));
			if (canvas->map->block_map[i][j].type == 'P')
				show_player(canvas, background, i, j);
			++x;
		}
		++y;
	}
}

void show_map(t_canvas *canvas)
{
	t_data background;
	size_t	i;
	size_t	j;

	background.img = mlx_new_image(canvas->mlx, canvas->map->row_nb * 48, canvas->map->line_nb * 48);
	background.addr = mlx_get_data_addr(background.img, &background.bits_per_pixel, &background.line_length, &background.endian);	
	i = 0;
	while (i < canvas->map->line_nb)
	{
		j = 0;
		while (j < canvas->map->row_nb)
		{
			show_block(canvas, &background, i, j);
			++j;
		}
		++i;
	}
	mlx_put_image_to_window(canvas->mlx, canvas->window, background.img, 0, 0);
	free(background.img);
}