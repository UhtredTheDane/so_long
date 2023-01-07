#ifndef PLAYER_H
# define PLAYER_H

#include <stddef.h>
#include "img.h"

typedef struct s_player
{
	size_t	i;
	size_t	j;
	size_t  direction;
	t_img	*sprites_set[4];
}	t_player;

t_player *init_player(void *mlx, size_t i, size_t j);

#endif