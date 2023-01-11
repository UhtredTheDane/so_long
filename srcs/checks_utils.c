/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:05:59 by agengemb          #+#    #+#             */
/*   Updated: 2023/01/11 20:44:51 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checks.h"

int	check_remaining(t_map *map, t_block **block_map, size_t	i, size_t j)
{
	if (block_map[i][j].type == 'E' || block_map[i][j].type == 'C')
	{
		free_block_map(block_map, map->line_nb);
		ft_printf("Error\nIl n'existe pas de chemin valide\n");
		return (0);
	}
	return (1);
}
int	check_min(t_map	*map)
{
	if (map->player && map->exit && map->collectibles_nb)
		return (1);
	ft_printf("Error\nIl n y a pas au moins un joueur, une sortie ou un collectible\n");
	return (0);
}
