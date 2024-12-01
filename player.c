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
int *find_pos(char **map, char c)
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
			if (map[y][x] == c)
			{
				tab[0] = y;
				tab[1] = x;
				return (tab);
			}
		}
	}
	return (tab);
}
int open_dor(t_game *game)
{
	int y;
	int x;
	int i;
	int *tab;

	i = 0;
	y = -1;
	while (y++, game->map_ber[y])
	{
		x = -1;
		while (x++, game->map_ber[y][x])
		{
			if (game->map_ber[y][x] == 'C')
				return (0);
			if (game->map_ber[y][x] == 'E')
				i = 1;	
		}
	}
	printf("\n%i\n", i);
	if (i == 1)
	{
		tab = find_pos(game->map_ber, 'E');
		game->map_ber[tab[0]][tab[1]] = '0';
		mlx_put_image_to_window(game->mlx, game->win, game->open_door, tab[0] * 40, tab[1] * 40);
	}
	return (1);
}

int if_wall(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'E')
		return (0);
	return (1);
}
int	mooving_player(int keycode, void *stru)
{
	t_game	*game;
	int temp_x;
	int temp_y;

	game = (t_game *)stru;
	temp_y = game->y;
	temp_x = game->x;
	if (keycode == 65361 && if_wall(game->map_ber, game->x - 1, game->y)) // Freccia sinistra
		game->x -= 1;
	else if (keycode == 65362 && if_wall(game->map_ber, game->x, game->y - 1)) // Freccia su
		game->y -= 1;
	else if (keycode == 65363 && if_wall(game->map_ber, game->x + 1, game->y)) // Freccia destra
		game->x += 1;
	else if (keycode == 65364 && if_wall(game->map_ber, game->x, game->y + 1)) // Freccia giù
		game->y += 1;
	else if (keycode == 65307) // ESC
		exit(0);
	if (game->map_ber[game->y][game->x] == 'C')
		game->map_ber[game->y][game->x] = '0';
	open_dor(game);
	int y = -1;
	while (y++, game->map_ber[y])
		printf("%s\n", game->map_ber[y]);
	mlx_put_image_to_window(game->mlx, game->win,
		game->floor, temp_x * 40, temp_y * 40);
	mlx_put_image_to_window(game->mlx, game->win,
		game->player, game->x * 40, game->y * 40);
	return (0);
}

void	player_settings(t_game *game)
{
	int *tab;

	tab = find_pos(game->map_ber, 'P');
	game->y = tab[0];
	game->x = tab[1];
	mlx_key_hook(game->win, mooving_player, game);
	free(tab);
}
