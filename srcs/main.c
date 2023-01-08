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

int	close_window(t_canvas *canvas)
{

	mlx_destroy_window(canvas->mlx, canvas->window);
	mlx_destroy_display(canvas->mlx);
	free(canvas->mlx);
	free(canvas);
	exit(0);
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
