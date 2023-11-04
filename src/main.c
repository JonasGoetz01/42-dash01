#include "../includes/a-star.h"

// print the easy route by going right/left and up/down to the goal without thinking of the best route and print it
void print_easy_route(field** map) {
	int map_size_x = get_map_size_x(map);
	int map_size_y = get_map_size_y(map);

	int myx = -1;
	int myy = -1;
	int goal_x = -1;
	int goal_y = -1;

	for (int y = 0; y < map_size_y; ++y) {
		for (int x = 0; x < map_size_x; ++x) {
			if (map[y][x].is_start) {
				myx = x;
				myy = y;
			} else if (map[y][x].is_end) {
				goal_x = x;
				goal_y = y;
			}
		}
	}
	printf("055");
	if(myx < goal_x) {
		for(int i = myx; i < goal_x; i++) {
			write(1, "R", 1);
		}
	} else {
		for(int i = myx; i > goal_x; i--) {
			write(1, "L", 1);
		}
	}
	if(myy < goal_y) {
		for(int i = myy; i < goal_y; i++) {
			write(1, "D", 1);
		}
	} else {
		for(int i = myy; i > goal_y; i--) {
			write(1, "U", 1);
		}
	}
	write(1, "\n", 1);
}

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

	print_easy_route(map);
	gen_fastest_routes(map);

	return 0;
}