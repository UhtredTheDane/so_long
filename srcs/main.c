/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:47:54 by agengemb          #+#    #+#             */
/*   Updated: 2022/12/19 17:59:54 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/data.h"

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

//ne pas oublier fermeture plus free
int	main(int argc, char **argv)
{
	int	map_fd;
	t_canvas	*canvas;
	t_queue *queue;
	size_t row_nb;
	t_data img;
	
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
	


	img.img = mlx_new_image(canvas->mlx, canvas->map->row_nb * 48, canvas->map->line_nb * 48);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 100, 100, 0x0084C3BD);



	
	mlx_put_image_to_window(canvas->mlx, canvas->window, img.img, 0, 0);

/*
	for (int i = 0; i < canvas->map->line_nb; i++)
	{
		for (int j = 0; j < canvas->map->row_nb; j++)
			mlx_put_image_to_window(canvas->mlx, canvas->window, canvas->map->block_map[i][j].img->img, j * 48, i * 48);
	}*/

	mlx_loop(canvas->mlx);
	return (0);
}
