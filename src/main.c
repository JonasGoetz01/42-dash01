#include "../includes/parsing.h"
#include "../includes/a-star.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

	int start_x, start_y, end_x, end_y;
	for (int i = 0; i < map_size_x; i++) {
		for (int j = 0; j < map_size_y; j++) {
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
	a_star(start_x, start_y, end_x, end_y);
	printf("\n");

	return 0;
}