#include "../includes/a-star.h"

int main(int argc, char *argv[]) {
	
	if (argc != 2) {
		printf("Usage: %s <map_file>\n", argv[0]);
		return 1;
	}

	field **map = get_map(argv[1]);
	if (!map) {
		printf("Error: Invalid map file\n");
		return 1;
	}

	size_t map_size_x = get_map_size_x(map);
	size_t map_size_y = get_map_size_y(map);

	int start_x, start_y, end_x, end_y;
	for (size_t i = 0; i < map_size_x; i++) {
		for (size_t j = 0; j < map_size_y; j++) {
			if (map[i][j].is_start) {
				start_x = i;
				start_y = j;
			}
			if (map[i][j].is_end) {
				end_x = i;
				end_y = j;
			}
		}
	}
	a_star(start_x, start_y, end_x, end_y, map);
	printf("\n");

	return 0;
}