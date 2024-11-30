/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgastelu <tgastelu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:51:58 by tgastelu          #+#    #+#             */
/*   Updated: 2024/11/29 17:41:27 by tgastelu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void fill_screen(t_game *game)
{
	int x;
	int y;
	int fd;
	int size;
	char *buffer;
	
	fd = open("mappe.ber", O_RDONLY);
	buffer = malloc(2);
	buffer[1] = '\0';
	read(fd, buffer, 1);
	x = 0;
	y = 0;
	size = size_x_map(game->map_ber[0]);
	while (*buffer)
	{
		if (buffer[0] == '1')
			mlx_put_image_to_window(game->mlx, game->win, game->wall, x * 40, y * 40);
		if (buffer[0] == '0')
			mlx_put_image_to_window(game->mlx, game->win, game->floor, x * 40, y * 40);
		if (buffer[0] == 'P')
			mlx_put_image_to_window(game->mlx, game->win, game->player, x * 40, y * 40);
		x++;
		if (x == size)
		{
			x = 0;
			y++;
		}
		read(fd, buffer, 1);
	}
	close(fd);
}
void	file_to_image(t_game *game)
{
	int		wall_largeur;
	int		wall_hauteur;
	int		king_largeur;
	int		king_hauteur;
	int 	floor_largeur;
	int		floor_hauteur;

	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &wall_largeur, &wall_hauteur);
	game->floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &floor_largeur, &floor_hauteur);
	game->player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &king_largeur, &king_hauteur);
}
int	main()
{
	// t_game *game;
	// int p_largeur;
	// int p_hauteur;
	char **map;

	// game = malloc(sizeof(t_game));
	map = fill_map_ber();

	if (parsing(map) == 0)
	{
		write(1, "PARSING:\nwrong input", 20);
		return (0);
	}
	ft_free(map);
	// game->mlx = mlx_init();
	// file_to_image(game);
	// printf("%d", size_x_map(game->map_ber[0]));
	// game->win = mlx_new_window(game->mlx, size_x_map() * 40, num_line_map() * 40, "so_long");
	// // game->mappe = mlx_xpm_file_to_image(game->mlx, "map.xpm", &p_largeur, &p_hauteur);
	// // mlx_put_image_to_window(game->mlx, game->win, game->mappe, 0, 0);
	// // player_settings(game);
	// fill_screen(game);

	// mlx_loop(game->mlx);
}
