/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 05:00:17 by agengemb          #+#    #+#             */
/*   Updated: 2023/01/11 05:00:38 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKS_H
# define CHECKS_H

# include <stddef.h>
# include "../ft_printf/includes/ft_printf.h"
# include "block.h"
# include "map.h"
# include "so_long.h"

typedef struct s_map	t_map;
int	check_format(char *file_name);
int	check_row_nb(char *line, size_t *row_nb);
int	check_block(void *mlx, t_map *map, char symbol, size_t *position);
int	check_path(t_map *map, t_block **block_map, int i_start, int j_start);

#endif
