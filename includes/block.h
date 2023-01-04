/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:22:11 by agengemb          #+#    #+#             */
/*   Updated: 2022/12/19 14:12:10 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BLOCK_H
# define BLOCK_H

# include "img.h"

typedef struct s_block
{
	char	type;
	int	can_be_crossed;
	t_img	*img;
}			t_block;

int init_block(t_block *block, char symbol, t_img **tiles_set);
void	free_block_map(t_block **block_map, size_t index);

#endif
