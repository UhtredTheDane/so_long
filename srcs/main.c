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

void ft_exit(t_canvas *canvas)
{
	free_set(canvas->mlx, canvas->map->tiles_set, 4);
	free_set(canvas->mlx, canvas->map->player->sprites_set, 4);
	free(canvas->map->player);
	free_block_map(canvas->map->block_map, canvas->map->line_nb);
	free(canvas->map);
	mlx_destroy_window(canvas->mlx, canvas->window);
	mlx_destroy_display(canvas->mlx);
	free(canvas->mlx);
	free(canvas);
	exit(0);
}

int	close_window(t_canvas *canvas)
{
	ft_exit(canvas);
}

int open_file(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1 || !check_format(file_name))
	{
		ft_printf("Error\nNom de fichier invalide ou inexistant\n");
		exit (0);
	}
	return (fd);
}

int	main(int argc, char **argv)
{
	int	map_fd;
	t_canvas	*canvas;
	t_queue *queue;
	size_t row_nb;

	if (argc != 2)
		return (0);
	map_fd = open_file(argv[1]);
	queue = load_map_in_queue(map_fd, &row_nb);
	close(map_fd);
	if (!queue)
	{
		free_queue(queue);
		return (0);
	}
	canvas = create_canvas(queue, ft_queuesize(queue), row_nb);
	free_queue(queue);
	if (!canvas)
		return (0);
	show_map(canvas);
	mlx_key_hook(canvas->window, keyboard_manage, canvas);
	mlx_hook(canvas->window, 17, 0, close_window, canvas);
	mlx_loop(canvas->mlx);
	return (0);
}
