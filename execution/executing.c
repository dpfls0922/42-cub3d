/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:32:42 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/26 23:00:01 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/executing.h"

t_dda	*apply_dda(t_game *game, t_raycast *ray, t_dda *dda)
{
	bool	hit;

	init_dda(dda, ray, game->mlx);
	hit = false;
	while (hit == false)
	{
		if (dda->side_dist_x < dda->side_dist_y)
		{
			dda->side_dist_x += dda->delta_dist_x;
			dda->map_x += dda->step_x;
			dda->side = WALL_X;
		}
		else
		{
			dda->side_dist_y += dda->delta_dist_y;
			dda->map_y += dda->step_y;
			dda->side = WALL_Y;
		}
		hit = check_wall(game->mlx, dda);
	}
	return (dda);
}

void	shoot_ray(t_game *game, t_raycast *ray, t_dda *dda)
{
	apply_dda(game, ray, dda);
	if (dda->side == WALL_X)
		dda->perp_wall_dist = dda->side_dist_x - dda->delta_dist_x;
	else
		dda->perp_wall_dist = dda->side_dist_y - dda->delta_dist_y;
	if (dda->perp_wall_dist == 0)
		dda->perp_wall_dist = 1e30;
	dda->wall_height = (int)((double)HEIGHT / dda->perp_wall_dist);
	ray->start = -(dda->wall_height) / 2 + HEIGHT / 2;
	if (ray->start < 0)
		ray->start = 0;
	ray->end = dda->wall_height / 2 + HEIGHT / 2;
	if (ray->end >= HEIGHT)
		ray->end = HEIGHT - 1;
	find_collision_wall_direction(ray, *dda, dda->side);
}

void	draw_vertical_line(t_game *game, t_raycast ray, int line, t_dda *dda)
{
	int	y;

	y = 0;
	(void) game;
	(void) ray;
	(void) line;
	(void) dda;
	while (y < HEIGHT)
	{
		// if (y < ray.start && y < 이미지 높이 && x < 이미지 너비)
		// 	배경
		// else if (y >= ray.start && y <= ray.end && y < 이미지 높이 && x < 이미지 너비)
		// 	스프라이트
		// else if (y > ray.end && y < 이미지 높이 && x x < 이미지 너비)
		// 배경
		y++;
	}
}

void	raycasting(t_game *game)
{
	t_dda		dda;
	t_raycast	ray;
	double		camera;
	int			i;

	i = 0;
	while (i <= WIDTH)
	{
		camera = 2 * i / (double)WIDTH - 1;
		ray.ray_dir_x = game->player->dir_x + game->player->plane_x * camera;
		ray.ray_dir_y = game->player->dir_y + game->player->plane_y * camera;
		shoot_ray(game, &ray, &dda);
		draw_vertical_line(game, ray, i, &dda);
		i++;
	}
}

void	executing(t_game *game)
{
	// t_mlx	mlx;

	// mlx.init = mlx_init();
	// mlx.win = mlx_new_window(mlx.init, WIDTH, HEIGHT, "cub3D");
	// mlx.game = game;
	init_direction_vectors(game);
	init_raycast(game);
	// game->img->init = mlx_new_image(game->mlx->init, WIDTH, HEIGHT);
	// if (mlx.img == NULL) error 처리
	// mlx_put_image_to_window(game->mlx.init, mlx.win, game->img->init, 0, 0);
	// texture
	// raycasting(&mlx);
	key_pressed(game);
	mlx_loop(game->mlx->init);
	// exit;
}

