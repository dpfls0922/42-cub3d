/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:37:09 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/15 15:55:39 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game(t_game *game, char *file)
{
}

int	main(int argc, char **argv)
{
	t_game	game;


	if (argc != 2)
		error("Error\n");
	// argv[1] 입력값 유효성 체크 추가하기

	// init_game(game, argv[1]);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	mlx_loop(game.mlx);
}