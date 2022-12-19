/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:21:56 by agengemb          #+#    #+#             */
/*   Updated: 2022/12/19 14:14:07 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/block.h"

int init_block(t_block *block, char symbol, t_img **tiles_set)
{
	block->type = symbol;
	if (symbol == '0' || symbol == 'P')
	{
		block->can_be_crossed = 1;
		block->img = tiles_set[0];
	}
	else if (symbol == '1')
	{
		block->img = tiles_set[1];
		block->can_be_crossed = 0;
	}
	else if (symbol == 'C')
	{
		block->img = tiles_set[2];
		block->can_be_crossed = 1;
	}
	else if (symbol == 'E')
	{
		block->img = tiles_set[3];
		block->can_be_crossed = 1;
	}
	else
		return (0);
}
