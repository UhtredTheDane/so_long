/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:54:11 by agengemb          #+#    #+#             */
/*   Updated: 2023/01/12 02:12:27 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checks.h"

int	check_remaining(t_map *map, t_block **copy_map, size_t i, size_t j)
{
	if (copy_map[i][j].type == 'E' || copy_map[i][j].type == 'C')
	{
		free_block_map(copy_map, map->line_nb);
		ft_printf("Error\nIl n'existe pas de chemin valide\n");
		return (0);
	}
	return (1);
}

int	check_min(t_map *map)
{
	if (map->player && map->exit && map->collectibles_nb)
		return (1);
	ft_printf("Error\nIl manque un joueur, une sortie ou un collectible\n");
	return (0);
}
