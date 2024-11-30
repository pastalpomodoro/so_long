#include "so_long.h"

// void fill_screen(t_game *game)
// {
// 	int x;
// 	int y;
// 	int fd;
// 	int size;
// 	char *buffer;
	
// 	fd = open("mappe.ber", O_RDONLY);
// 	buffer = malloc(2);
// 	buffer[1] = '\0';
// 	read(fd, buffer, 1);
// 	x = 0;
// 	y = 0;
// 	size = size_x_map(game->map_ber[0]);
// 	while (*buffer)
// 	{
// 		if (buffer[0] == '1')
// 			mlx_put_image_to_window(game->mlx, game->win, game->wall, x * 40, y * 40);
// 		if (buffer[0] == '0')
// 			mlx_put_image_to_window(game->mlx, game->win, game->floor, x * 40, y * 40);
// 		if (buffer[0] == 'P')
// 			mlx_put_image_to_window(game->mlx, game->win, game->player, x * 40, y * 40);
// 		x++;
// 		if (x == size)
// 		{
// 			x = 0;
// 			y++;
// 		}
// 		read(fd, buffer, 1);
// 	}
// 	close(fd);
// }
void    fill_screen(t_game *game)
{
    int x;
    int y;

    y = -1;
    while (y++, game->map_ber[y])
    {
        x = -1;
        while (x++, game->map_ber[y][x])
        {
            if (game->map_ber[y][x] == '0')
                mlx_put_image_to_window(game->mlx,  game->win, game->floor, x * 40, y * 40);
            if (game->map_ber[y][x] == 'C')
                mlx_put_image_to_window(game->mlx,  game->win, game->banana, x * 40, y * 40);
            if (game->map_ber[y][x] == 'E')
                mlx_put_image_to_window(game->mlx,  game->win, game->door, x * 40, y * 40);
            if (game->map_ber[y][x] == '1')
                mlx_put_image_to_window(game->mlx,  game->win, game->wall, x * 40, y * 40);
            if (game->map_ber[y][x] == 'P')
                mlx_put_image_to_window(game->mlx,  game->win, game->player, x * 40, y * 40);
        }
    }
}
void	file_to_image(t_game *game)
{
	int		largeur;
	int		hauteur;

	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &largeur, &hauteur);
	game->floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &largeur, &hauteur);
	game->player = mlx_xpm_file_to_image(game->mlx, "textures/king.xpm", &largeur, &hauteur);
    game->door = mlx_xpm_file_to_image(game->mlx, "textures/door.xpm", &largeur, &hauteur);
    game->banana = mlx_xpm_file_to_image(game->mlx, "textures/banana.xpm", &largeur, &hauteur);
}