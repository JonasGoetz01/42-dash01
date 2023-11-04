/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 09:45:35 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/04 13:30:51 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"
#include "../includes/a-star.h"

field	**get_map(char *file)
{
	int		fd;
	char	*line;
	char	*lines;
	char	**map_array;
	int		row_num;
	char	*temp;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	row_num = 1;
	line = get_next_line(fd);
	lines = ft_strjoin("", line);
	free(line);
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp = ft_strjoin(lines, line);
		free(lines);
		lines = ft_strdup(temp);
		free(line);
		free(temp);
		row_num++;
	}
	close(fd);
	map_array = ft_split(lines, '\n');
	printf("row_num: %d\n", row_num);
	return (get_field_rows(map_array, row_num));
}

field	**get_field_rows(char **map_array, int row_num)
{
	field	**map;
	int		i;

	map = ft_calloc(row_num + 1, sizeof(field *));
	if (!map)
		return (NULL);
	i = 0;
	while (i < row_num)
	{
		map[i] = get_fields(map_array[i]);
		i++;
	}
	map[i] = NULL;
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
		fields[field_index].cost_mult = map[char_index + 1] - '0';
		fields[field_index].is_start = 0;
		fields[field_index].is_end = 0;
		if (map[char_index + 1] == 'M')
			fields[field_index].is_start = 1;
		if (map[char_index + 1] == 'G')
			fields[field_index].is_end = 1;
		char_index += 2;
		field_index++;
	}
	fields[field_index].type = -1;
	fields[field_index].cost_mult = -1;
	fields[field_index].is_start = -1;
	fields[field_index].is_end = -1;
	return (fields);
}
