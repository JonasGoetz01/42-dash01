/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:31:24 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/04 10:59:43 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

int	main(void)
{
	field	**map;
	int		i;
	int		j;

	map = get_map("map.txt");
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j].type)
		{
			ft_printf("%c", map[i][j].type);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	return (0);
}
