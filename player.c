/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgastelu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:00:40 by tgastelu          #+#    #+#             */
/*   Updated: 2024/11/28 17:04:12 by tgastelu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"
int *find_p_pos(char **map)
{
	int *tab;
	int y;
	int x;

	tab = malloc(sizeof(int) * 2);
	if (!tab)
		return (NULL);
	y = -1;
	while (y++, map[y])
	{
		x = -1;
		while (x++, map[y][x])
		{
			if (map[y][x] == 'P')
			{
				tab[0] = y;
				tab[1] = x;
				return (tab);
			}
		}
	}
	return (tab);
}
int	mooving_player(int keycode, void *stru)
{
	t_game	*game;
	int temp_x;
	int temp_y;

	game = (t_game *)stru;
	temp_y = game->y;
	temp_x = game->x;
	if (keycode == 65361 && game->x > 0) // Freccia sinistra
		game->x -= 40;
	else if (keycode == 65362 && game->y > 0) // Freccia su
		game->y -= 40;
	else if (keycode == 65363 && game->x < 896) // Freccia destra
		game->x += 40;
	else if (keycode == 65364 && game->y < 512) // Freccia giù
		game->y += 40;
	else if (keycode == 65307) // ESC
		exit(0);
	mlx_put_image_to_window(game->mlx, game->win, game->floor, temp_x, temp_y);
	mlx_put_image_to_window(game->mlx, game->win,
		game->player, game->x, game->y);
	return (0);
}

void	player_settings(t_game *game)
{
	int *tab;

	tab = find_p_pos(game->map_ber);
	printf("%d    %d", tab[0], tab[1]);
	game->y = tab[0];
	game->x = tab[1];
	mlx_key_hook(game->win, mooving_player, game);
}
