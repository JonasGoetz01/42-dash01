/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 09:45:35 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/04 10:48:45 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

static field	*get_fields(char *map);

static field	**get_field_rows(char **map_array, int row_num);

field	**get_map(char *file)
{
	int		fd;
	char	*line;
	char	*lines;
	char	**map_array;
	int		row_num;

	fd = open(file, O_RDONLY);
	lines = ft_strdup("");
	if (!lines || fd < 0)
		return (NULL);
	row_num = 1;
	while (line != NULL)
	{
		line = get_next_line(fd);
		lines = ft_strjoin(lines, line);
		lines = ft_strjoin(lines, "\n");
		free(line);
		row_num++;
	}
	close(fd);
	map_array = ft_split(lines, '\n');
	return (get_field_rows(map_array, row_num));
}

field	**get_field_rows(char **map_array, int row_num)
{
	field	**map;
	int		i;

	map = ft_calloc(row_num, sizeof(field *));
	if (!map)
		return (NULL);
	i = 0;
	while (i < row_num)
	{
		map[i] = get_fields(map_array[i]);
		i++;
	}
	return (map);
}

field	*get_fields(char *map)
{
	int		i;
	int		count;
	int		row_len;
	field	*fields;

	row_len = ft_strlen(map);
	count = row_len / 2;
	fields = ft_calloc(count, sizeof(field));
	if (!fields)
		return (NULL);
	i = 0;
	while (i < row_len - 1)
	{
		fields[i].type = map[i];
		fields[i].is_start = 0;
		fields[i].is_end = 0;
		if (map[i + 1] == 'M')
			fields[i].is_start = 1;
		if (map[i + 1] == 'G')
			fields[i].is_end = 1;
		fields[i].cost_mult = map[i + 1] - '0';
		i += 2;
	}
	return (fields);
}
