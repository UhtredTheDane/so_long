/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:21:56 by agengemb          #+#    #+#             */
/*   Updated: 2023/01/11 04:19:42 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/block.h"

void	init_block(t_block *block, char symbol, t_img **tiles_set)
{
	block->type = symbol;
	if (symbol == '0' || symbol == 'P')
		block->img = tiles_set[0];
	else if (symbol == '1')
		block->img = tiles_set[1];
	else if (symbol == 'C')
		block->img = tiles_set[2];
	else if (symbol == 'E')
		block->img = tiles_set[3];
}

void	free_block_map(t_block **block_map, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index)
	{
		free(block_map[i]);
		++i;
	}
	free(block_map);
}
