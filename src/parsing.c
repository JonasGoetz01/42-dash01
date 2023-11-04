/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 09:45:35 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/04 10:17:44 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

char	*get_map_char(char *file)
{
	int		fd;
	char	*line;
	char	*lines;
	char	**map;

	fd = open(file, O_RDONLY);
	lines = ft_strdup("");
	if (!lines || fd < 0)
		return (NULL);
	while (get_next_line(fd, &line) > 0)
	{
		lines = ft_strjoin(lines, line);
		lines = ft_strjoin(lines, "\n");
		free(line);
	}
	close(fd);
	map = ft_split(lines, '\n');
	return (map);
}



field	*get_fields(char *map)
{
	int		count;
	// ;

	count = ft_strlen(map) / 2;
}
