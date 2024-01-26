/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:59:33 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/26 23:01:16 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/executing.h"

void	init_direction_vectors(t_game *game)
{
	game->player->pos_x = game->player->y;
	game->player->pos_y = game->player->x;
	game->player->dir_x = 0;
	game->player->dir_y = 0;
	if (game->direction == 'S')
		game->player->dir_y = 1;
	else if (game->direction == 'N')
		game->player->dir_y = -1;
	else if (game->direction == 'E')
		game->player->dir_x = 1;
	else if (game->direction == 'W')
		game->player->dir_x = -1;
}

void	init_raycast(t_game *game)
{
	double	dir_x;
	double	dir_y;

	dir_x = 0;
	dir_y = 0;
	if (game->direction == 'S')
		dir_y = 1;
	else if (game->direction == 'N')
		dir_y = -1;
	else if (game->direction == 'E')
		dir_x = 1;
	else if (game->direction == 'W')
		dir_x = -1;
	game->player->plane_x = -(dir_y) * 0.66;
	game->player->plane_y = dir_x * 0.66;
}

void	init_side_dist(t_dda *dda, t_game *game, t_raycast *ray)
{
	if (ray->ray_dir_x < 0)
	{
		dda->step_x = -1;
		dda->side_dist_x = (game->player->pos_x - dda->map_x)
			* dda->delta_dist_x;
	}
	else
		dda->side_dist_x = (dda->map_x + 1.0 - game->player->pos_x)
			* dda->delta_dist_x;
	if (ray->ray_dir_y < 0)
	{
		dda->step_y = -1;
		dda->side_dist_y = (game->player->pos_y - dda->map_y)
			* dda->delta_dist_y;
	}
	else
		dda->side_dist_y = (dda->map_y + 1.0 - game->player->pos_y)
			* dda->delta_dist_y;
}

void	init_dda(t_dda *dda, t_raycast *ray, t_game *game)
{
	dda->map_x = (int)(game->player->pos_x);
	dda->map_y = (int)(game->player->pos_y);
	if (ray->ray_dir_x == 0)
		dda->delta_dist_x = 1e30;
	else
		dda->delta_dist_x = ft_abs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		dda->delta_dist_y = 1e30;
	else
		dda->delta_dist_y = ft_abs(1 / ray->ray_dir_y);
	dda->step_x = 1;
	dda->step_y = 1;
	init_side_dist(dda, game, ray);
}
