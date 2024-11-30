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

/*void put_pixel_player(s_game *game)
{
	int i;
	int f;
	unsigned int color;
	char *pixel_addr;

	game->addr = mlx_get_data_addr(game->player, &game->bits_per_pixel, &game->size_line, &game->endian);
	i = 0;
	while (i < 40)
	{
		f = 0;
		while (f < 40)
		{
			pixel_addr = game->addr + ((i) * game->size_line + ((f) * game->bits_per_pixel/8));
			color = *(unsigned int *)pixel_addr;
			if (color != 0)
				mlx_pixel_put(game->mlx, game->win, game->x + f, game->y + i, color);
			//printf("%u\n", color);        
			f++;
		}
		i++;
	}
}*/

int	mooving_player(int keycode, void *stru)
{
	t_game	*game;

	game = (t_game *)stru;
	if (keycode == 65361 && game->x > 0) // Freccia sinistra
		game->x -= 64;
	else if (keycode == 65362 && game->y > 0) // Freccia su
		game->y -= 64;
	else if (keycode == 65363 && game->x < 896) // Freccia destra
		game->x += 64;
	else if (keycode == 65364 && game->y < 512) // Freccia giù
		game->y += 64;
	else if (keycode == 65307) // ESC
		exit(0);
	mlx_clear_window(game->mlx, game->win);
	mlx_put_image_to_window(game->mlx, game->win, game->mappe, 0, 0);
	//put_pixel_player(game);
	mlx_put_image_to_window(game->mlx, game->win,
		game->player, game->x, game->y);
	return (0);
}

void	player_settings(t_game *game)
{
	int	p_largeur;
	int	p_hauteur;

	game->x = 0;
	game->y = 0;
	game->player = mlx_xpm_file_to_image(game->mlx,
			"sprites/player/player_1.xpm", &p_largeur, &p_hauteur);
	mlx_key_hook(game->win, mooving_player, game);
	// game->addr = mlx_get_data_addr(game->player, &game->bits_per_pixel, &game->size_line, &game->endian);
	// my_mlx_pixel_put(game, 300, 159, 0x00FF0000);
	// mlx_put_image_to_window(game->mlx, game->win, game->player, game->x, game->y);
}
