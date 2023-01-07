/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:00:21 by agengemb          #+#    #+#             */
/*   Updated: 2022/12/19 14:01:09 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include "../get_next_line/get_next_line.h"
# include "../mlx_linux/mlx.h"
# include "queue.h"
# include "canvas.h"
# include "data.h"

int check_format(char	*file_name);
size_t	ft_strlen(const char *s);
void show_map(t_canvas *canvas);
void show_block(t_canvas *canvas, t_data *background, size_t i, size_t j);


#endif
