#ifndef SHOW_H
# define SHOW_H

# include <stddef.h>
# include "../mlx_linux/mlx.h"
# include "canvas.h"
# include "data.h"
# include "utils.h"

void show_player(t_canvas *canvas, t_data *background, size_t i, size_t j);
void show_block(t_canvas *canvas, t_data *background, size_t i, size_t j);
void show_map(t_canvas *canvas);

#endif