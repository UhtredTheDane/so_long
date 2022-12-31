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

typedef struct s_backtrack_data
{
	int	c_remaining;
	size_t	last_direction;
}	t_backtrack_data;

#endif
