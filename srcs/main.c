/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:47:54 by agengemb          #+#    #+#             */
/*   Updated: 2022/12/19 14:19:31 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
int check_format(char	*file_name)
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

int	main(int argc, char **argv)
{
	int	map_fd;
	
	char	*line;
	size_t row_nb;
	t_queue	*queue;
	t_queue	*elem;
	t_canvas	*canvas;
	
	//MAP
	if (argc != 2)
		return (0);
	map_fd = open(argv[1], O_RDONLY);
	if (map_fd == -1 || !check_format(argv[1]))
	{
		printf("pas pu ouvrir le fichier\n");
		return (0);
	}
	line = "";
	queue = NULL;
	while (line != NULL)
	{
		line = get_next_line(map_fd);
		if (line != NULL)
		{
			if (!queue)
				row_nb = ft_strlen(line) - 1;
			else
			{
				if (row_nb != ft_strlen(line) - 1)
				{
					printf("Error\n");
					return (0);
				}
			}
			elem = ft_queuenew(line);
			queue_add(&queue, elem);
		}
	}
	canvas = create_canvas(queue, ft_queuesize(queue), row_nb);
	if (!canvas)
		return (0);
	for (int i = 0; i < canvas->map->line_nb; i++)
	{
		for (int j = 0; j < canvas->map->row_nb; j++)
			mlx_put_image_to_window(canvas->mlx, canvas->window, canvas->map->block_map[i][j].img->img, j * 48, i * 48);
	}	
	mlx_loop(canvas->mlx);
	return (0);
}
