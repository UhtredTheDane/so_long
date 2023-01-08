#ifndef PLAYER_H
# define PLAYER_H

# include <stddef.h>
# include "../mlx_linux/mlx.h"
# include "img.h"

typedef struct s_player
{
	size_t	i;
	size_t	j;
	size_t  direction;
	size_t	moves_nb;
	t_img	*sprites_set[4];
}	t_player;

t_player *init_player(void *mlx, size_t i, size_t j);

#endif