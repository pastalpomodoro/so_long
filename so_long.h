#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct game
{
    void *mlx;
    void *win;
    void *mappe;
    void *player;
    void *addr;
    char **map_ber;
    int     size_line;
    int     bits_per_pixel;
    int     endian;
    int     x;
    int     y;
}               s_game;

#include "../../cercle_1/libft/libft.h"
#include "../../minilibx-linux/mlx.h"
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>

//get_next_line fonc
void	char_set(char *str);
int	if_read(char *buffer, char *line, int fd);
char *get_next_line(int fd);

int     parsing(char **map);
char	*mal_str_addchar(char *line, char c);
void    player_settings(s_game *game);

#endif