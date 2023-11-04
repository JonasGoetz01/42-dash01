/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 09:43:26 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/04 12:57:08 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../libs/printf/ft_printf.h"
# include "../libs/get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct field
{
	char	type;
	int		cost_mult;
	int		is_start;
	int		is_end;
}	field;

field	**get_map(char *file);

#endif