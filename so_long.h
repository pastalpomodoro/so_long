/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgastelu <tgastelu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:53:52 by tgastelu          #+#    #+#             */
/*   Updated: 2024/11/28 18:57:29 by tgastelu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../../cercle_1/libft/libft.h"
# include "../../minilibx-linux/mlx.h"
# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>
# include<fcntl.h>

typedef struct game
{
	void	*mlx;
	void	*win;
	void	*mappe;
	void	*wall;
	void	*floor;
	void	*player;
	void	*addr;
	char	**map_ber;
	int		size_line;
	int		bits_per_pixel;
	int		endian;
	int		x;
	int		y;
}		t_game;

//utils
void	ft_free(char **map);
int		num_line_map(void);
int		size_x_map(char *line);
char	**fill_map_ber(void);

//get_next_line
void	char_set(char *str);
int		if_read(char *buffer, char *line, int fd);
char	*get_next_line(int fd);

//parsing
int		find(char **map);
int		parsing(char **map);

//game
void	player_settings(t_game *game);

#endif
