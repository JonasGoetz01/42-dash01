#include <stdio.h>
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

int main(void) {
	// map1
	char *test_file = "map1.txt";
	printf("parsing first file\n");
	field **map = get_map(test_file);
	if (!map) {
		printf("Failed to parse map\n");
		return 1;
	}
	print_map(map, 8);
	free(map);
	//map2
	test_file = "map2.txt";
	map = get_map(test_file);
	if (!map) {
		printf("Failed to parse map\n");
		return 1;
	}
	print_map(map, 8);
	free(map);
	// map3
	test_file = "map3.txt";
	map = get_map(test_file);
	if (!map) {
		printf("Failed to parse map\n");
		return 1;
	}
	print_map(map, 8);
	free(map);
	return (0);
}
