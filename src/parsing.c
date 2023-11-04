/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 09:45:35 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/04 12:05:47 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

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
	line = get_next_line(fd);
	while (line != NULL)
	{
		line = get_next_line(fd);
		lines = ft_strjoin(lines, line);
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
	int		char_index;
	int		field_index;
	int		count;
	int		row_len;
	field	*fields;

	row_len = ft_strlen(map);
	count = row_len / 2;
	fields = ft_calloc(count + 1, sizeof(field));
	if (!fields)
		return (NULL);
	char_index = 0;
	field_index = 0;
	while (char_index < row_len - 1)
	{
		fields[field_index].type = map[char_index];
		fields[field_index].is_start = 0;
		fields[field_index].is_end = 0;
		if (map[char_index + 1] == 'M')
			fields[field_index].is_start = 1;
		if (map[char_index + 1] == 'G')
			fields[field_index].is_end = 1;
		fields[field_index].cost_mult = map[char_index + 1] - '0';
		char_index += 2;
		field_index++;
	}
	return (fields);
}
