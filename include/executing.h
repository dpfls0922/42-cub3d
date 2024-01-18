/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:03:11 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/18 11:32:09 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTING_H
# define EXECUTING_H

# include <stdbool.h>
# include <math.h>
// #include "parsing.h"
# include "struct.h"
# include "../mlx/mlx.h"

# define WIDTH	1920
# define HEIGHT	1080
# define ROTATION_SPEED 40
# define MOVE_SPEED 0.08
# define LEFT 1
# define RIGHT 2
# define POS_X 1
# define POS_Y -1

# define KEY_ESC 53
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define KEY_EXIT 17

# define KEY_LEFT		123
# define KEY_RIGHT		124
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

/* init */
void	init_direction_vectors(t_mlx *mlx);
void	init_raycast(t_mlx *mlx);
void	init_side_dist(t_dda *dda, t_mlx *mlx, t_raycast *ray);
void	init_dda(t_dda *dda, t_raycast *ray, t_mlx *mlx);

/* move */
void		rotate_vectors(t_mlx *mlx, int orientation);
// static void	move_player(t_mlx *mlx, double x_change, double y_change);
// static void	handle_movement(t_mlx *mlx);
// void			handle_key(void *arg);

/* utils */
double	ft_abs(double num);
bool	check_wall(t_mlx *mlx, t_dda *dda);

/* executing */
t_dda	*apply_dda(t_mlx *mlx, t_raycast *ray, t_dda *dda);
void	shoot_ray(t_mlx *mlx, t_raycast *ray, t_dda *dda);
void	draw_vertical_line(t_mlx *mlx, t_raycast ray, int line, t_dda *dda);
void	raycasting(t_mlx *mlx);
void	executing(t_data *data);


#endif