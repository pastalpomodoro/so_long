#include "so_long.h"

int num_line_map()
{
    char *buffer;
    int status;
    int size;
    int fd;

    fd = open("mappe.ber", O_RDONLY);
    size = 1;
    buffer = malloc(1);
    status = read(fd, buffer, 1);
    while (status)
    {
        if (buffer[0] == '\n')
            size++;
        status = read(fd, buffer, 1);
    }
    close(fd);
    return (size);
}

char **fill_map_ber()
{
    char **map;
    int fd;
    int i;

    i = 0;
    fd = open("mappe.ber", O_RDONLY);
    map = malloc(sizeof(char *) * num_line_map());
    i = 0;
    map[i] = get_next_line(fd);
    while (map[i] != NULL)
    {
        i++;
        map[i] = get_next_line(fd);
    }
    close(fd);
    return(map);
}
int main()
{
    s_game *game;
    // int p_largeur;
    // int p_hauteur;

    game = malloc(sizeof(s_game));
    game->map_ber = fill_map_ber();

    printf("%d", parsing(game->map_ber));
    // game->mlx = mlx_init();
    // game->win = mlx_new_window(game->mlx, 960, 576, "so_long");
    // game->mappe = mlx_xpm_file_to_image(game->mlx, "map.xpm", &p_largeur, &p_hauteur);
    // mlx_put_image_to_window(game->mlx, game->win, game->mappe, 0, 0);
    // player_settings(game);

    // mlx_loop(game->mlx);
}