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
		ft_printf("Error\nNom de fichier invalide ou inexistant\n");
		return (0);
	}
	//regarder le free de queue dans loadmap
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
