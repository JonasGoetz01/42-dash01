/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 09:43:26 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/04 12:05:43 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../libs/printf/ft_printf.h"
# include "../libs/get_next_line/get_next_line.h"
# include <fcntl.h>

typedef struct field
{
	char	type;
	int		cost_mult;
	int		is_start;
	int		is_end;
}			field;

typedef struct node {
	int x;
	int y;
	int g;
	int h;
	int f;
	struct node* parent;
} node;

field	*get_fields(char *map);

field	**get_field_rows(char **map_array, int row_num);

field	**get_map(char *file);

#endif