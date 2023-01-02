/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack_data.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 22:38:24 by agengemb          #+#    #+#             */
/*   Updated: 2022/12/30 20:19:01 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BACKTRACK_DATA_H
# define BACKTRACK_DATA_H

# include <stddef.h>
# include "block.h"

typedef struct s_backtrack_data
{
	int	c_remaining;
	size_t	last_direction;
}	t_backtrack_data;

int choose_operate(t_block **block_map, size_t direction, int *position);
void    reverse_operate(size_t direction, int *position);
int is_useless(t_block **block_map, int *position, size_t direction, size_t last_direction);
int	find_path(t_block **block_map, int *position, t_backtrack_data *data, size_t cross_block_nb);

#endif
