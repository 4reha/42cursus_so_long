/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_play.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadd <ael-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:30:56 by ael-hadd          #+#    #+#             */
/*   Updated: 2022/01/16 15:34:58 by ael-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	game_events(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_UP)
	{
		game->y_player -= 1;
		player_w(game);
	}
	else if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		game->y_player += 1;
		player_s(game);
	}
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		game->x_player += 1;
		player_d(game);
	}
	else if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		game->x_player -= 1;
		player_a(game);
	}
}

static int	keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC || keycode == KEY_Q)
	{
		exit_game(game);
	}
	else if (!game->endgame)
	{
		game_events(keycode, game);
	}
	return (0);
}

void	gameplay(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, keypress, game);
	mlx_hook(game->win, 17, 1L << 17, exit_game, game);
}
