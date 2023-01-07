/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:47:54 by agengemb          #+#    #+#             */
/*   Updated: 2023/01/03 23:21:09 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/data.h"
#include <X11/keysym.h>

int	check_format(char *file_name)
{
	size_t	size_name;

	size_name = ft_strlen(file_name);
	if (file_name[size_name - 1] != 'r')
		return (0);
	else if (file_name[size_name - 2] != 'e')
		return (0);
	else if (file_name[size_name - 3] != 'b')
		return (0);
	else if (file_name[size_name - 4] != '.')
		return (0);
	else
		return (1);
}

int	check_row_nb(char *line, size_t *row_nb)
{
	if (ft_strlen(line) - 1 != *row_nb)
	{
		printf("Error\n");
		return (0);
	}
	return (1);
}

t_queue	*load_map_in_queue(int map_fd, size_t *row_nb)
{
	char	*line;
	t_queue	*queue;
	t_queue	*elem;

	line = "";
	queue = NULL;
	while (line != NULL)
	{
		line = get_next_line(map_fd);
		if (line != NULL)
		{
			if (!queue)
				*row_nb = ft_strlen(line) - 1;
			else
				if (!check_row_nb(line, row_nb))
					return (NULL);
			elem = ft_queuenew(line);
			queue_add(&queue, elem);
		}
	}
	return (queue);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	keyboard_manage(int keycode, t_canvas *canvas)
{
	t_player *player;
	t_data background;
	size_t i;
	size_t j;

	player = canvas->map->player;
	i = player->i;
	j = player->j;
	printf("i player: %ld et j player: %ld\n", i, j);
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(canvas->mlx, canvas->window);
		mlx_destroy_display(canvas->mlx);
		free(canvas->mlx);
		free(canvas);	
		exit(0);
	}
	else if (keycode == XK_w)
	{
		player->direction = 0;
		if (canvas->map->block_map[i - 1][j].type != '1')
		{
			canvas->map->block_map[i][j].type = '0';
			--player->i;
			canvas->map->block_map[i - 1][j].type = 'P';
		}
	}
	else if (keycode == XK_d)
	{
		player->direction = 1;
		if (canvas->map->block_map[i][j + 1].type != '1')
		{
			canvas->map->block_map[i][j].type = '0';
			++player->j;
			canvas->map->block_map[i][j + 1].type = 'P';
		}
	}
	else if (keycode == XK_s)
	{
		player->direction = 2;
		if (canvas->map->block_map[i + 1][j].type != '1')
		{
			canvas->map->block_map[i][j].type = '0';
			++player->i;
			canvas->map->block_map[i + 1][j].type = 'P';
		}
	}
	else if (keycode == XK_a)
	{
		player->direction = 3;
		if (canvas->map->block_map[i][j - 1].type != '1')
		{
			canvas->map->block_map[i][j].type = '0';
			--player->j;
			canvas->map->block_map[i][j - 1].type = 'P';
		}
	}
	show_map(canvas);
}

int	close_window2(t_canvas *canvas)
{

	mlx_destroy_window(canvas->mlx, canvas->window);
	mlx_destroy_display(canvas->mlx);
	free(canvas->mlx);
	free(canvas);
	exit(0);
}
int is_alpha(int color)
{
	return ((color >> 24)& 0xFF);
}

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

//ne pas oublier fermeture plus free
int	main(int argc, char **argv)
{
	int	map_fd;
	t_canvas	*canvas;
	t_queue *queue;
	size_t row_nb;


	if (argc != 2)
		return (0);
	map_fd = open(argv[1], O_RDONLY);
	if (map_fd == -1 || !check_format(argv[1]))
	{
		printf("pas pu ouvrir le fichier\n");
		return (0);
	}
	queue = load_map_in_queue(map_fd, &row_nb);
	if (!queue)
		return (0);
	canvas = create_canvas(queue, ft_queuesize(queue), row_nb);
	if (!canvas)
		return (0);
	
	
	show_map(canvas);
	//mlx_put_image_to_window(canvas->mlx, canvas->window, canvas->map->player->sprites_set[0]->img, 0, 0);
	mlx_key_hook(canvas->window, keyboard_manage, canvas);
	mlx_hook(canvas->window, 17, 0, close_window2, canvas);

	mlx_loop(canvas->mlx);
	return (0);
}
