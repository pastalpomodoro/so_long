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



int	main()
{
	t_game *game;
	int start;
	// int p_largeur;
	// int p_hauteur;

	start = 0;
	game = malloc(sizeof(t_game));
	game->map_ber = fill_map_ber();

	if (parsing(game->map_ber) == 0)
	{
		write(1, "PARSING:\nwrong input", 20);
		return (0);
	}
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->win = mlx_new_window(game->mlx, size_x_map(game->map_ber[0]) * 40, num_line_map() * 40, "so_long");
	if (!game->win)
		return (0);

	if (!start)
	{
		file_to_image(game);
		fill_screen(game);
		start++;
	}

	mlx_loop(game->mlx);
	ft_free(game->map_ber);
	free(game);
}
