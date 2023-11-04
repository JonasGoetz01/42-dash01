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

	gen_fastest_routes(map);

	return 0;
}