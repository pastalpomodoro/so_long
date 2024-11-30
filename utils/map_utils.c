/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgastelu <tgastelu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:17:45 by tgastelu          #+#    #+#             */
/*   Updated: 2024/11/29 17:36:51 by tgastelu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	num_line_map(void)
{
	char	*buffer;
	int		status;
	int		size;
	int		fd;

	fd = open("mappe.ber", O_RDONLY);
	size = 1;
	buffer = malloc(2);
    if (!buffer)
        return (0);
    buffer[1] = '\0';
	status = read(fd, buffer, 1);
	while (status != 0)
	{
		if (buffer[0] == '\n')
			size++;
		status = read(fd, buffer, 1);
	}
	free(buffer);
	close(fd);
	return (size);
}

int size_x_map(char *line)
{
	int i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

int size_full_map()
{
    int fd;
    char *buffer;
    int size;
    int r;

    buffer = malloc(2);
    if (!buffer)
        return (0);
    buffer[1] = '\0';
    fd = open("mappe.ber", O_RDONLY);
    r = read(fd, buffer, 1);
    size = -1;
    while (size++, r > 0)
        r = read(fd, buffer, 1);
    free(buffer);
    close(fd);
    return (size);
}

char *fill_mapp_ber()
{
    int fd;
    char *buffer;
    char *str;
    int r;
    int i;

    i = size_full_map();
    str = malloc(i + 1);
    if (!str)
        return (NULL);
    str[i] = '\0';
    buffer = malloc(2);
    if (!buffer)
        return (NULL);
    buffer[1] = '\0';
    fd = open("mappe.ber", O_RDONLY);
    r = read(fd, buffer, 1);
    i = -1;
    while (i++, r > 0)
    {
        str[i] = buffer[0];
        r = read(fd, buffer, 1);
    }
    free(buffer);
    close(fd);
    return (str);
}
char **fill_map_ber()
{
    char *str;
    char **map;

    str = fill_mapp_ber();
    map = ft_split(str, '\n');
    free(str);
    return (map);
}