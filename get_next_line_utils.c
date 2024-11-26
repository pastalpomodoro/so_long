/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgastelu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:30:06 by tgastelu          #+#    #+#             */
/*   Updated: 2024/11/18 17:30:31 by tgastelu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"so_long.h"

void	char_set(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = '\0';
		i++;
	}
}

int	if_read(char *buffer, char *line, int fd)
{
	if (read(fd, buffer, 100) < 0)
	{
		char_set(line);
		return (-1);
	}
	return (1);
}
