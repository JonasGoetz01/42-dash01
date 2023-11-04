/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 09:43:26 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/04 10:40:10 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../libs/printf/ft_printf.h"
# include <fcntl.h>

typedef struct field
{
	char	type;
	int		cost_mult;
	int		is_start;
	int		is_end;
}			field;

#endif