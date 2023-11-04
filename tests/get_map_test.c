/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:31:24 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/04 11:45:05 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

// int	main(void)
// {
// 	field	**map;
// 	int		i;
// 	int		j;

// 	map = get_map("map.txt");
// 	i = 0;
// 	while (map[i])
// 	{
// 		j = 0;
// 		while (map[i][j].type)
// 		{
// 			ft_printf("%c", map[i][j].type);
// 			j++;
// 		}
// 		ft_printf("\n");
// 		i++;
// 	}
// 	return (0);
// }

#include <stdio.h>
#include "../includes/parsing.h"

void print_fields(field *fields) {
    int i = 0;
    while (fields[i].type != -1) {
        printf("Field %d: type=%c, cost_mult=%d, is_start=%d, is_end=%d\n",
               i, fields[i].type, fields[i].cost_mult, fields[i].is_start, fields[i].is_end);
        i++;
    }
}

void print_map(field **map, int row_num) {
    for (int i = 0; i < row_num; i++) {
        printf("Row %d:\n", i);
        print_fields(map[i]);
    }
}

int main() {
    char *test_file = "test.txt"; // replace with your test file
    field **map = get_map(test_file);
    if (map == NULL) {
        printf("Failed to parse map\n");
        return 1;
    }
    print_map(map, row_num); // replace row_num with the actual number of rows in your map
    return 0;
}