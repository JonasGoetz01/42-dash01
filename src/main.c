#include "../includes/a-star.h"

void print_easy_route(char *map_file) {
    int fd = open(map_file, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return;
    }

    char *line = NULL;
    int myx = -1, myy = -1, goal_x = -1, goal_y = -1;
	int y = 0;
    while ((line = get_next_line(fd)) != NULL) {
        for (int i = 0; line[i] != '\0'; i += 2) {
            if (line[i] == 'M' && line[i + 1] == 'M') {
                myx = i / 2;
                myy = y;
            } else if (line[i] == 'G' && line[i + 1] == 'G') {
                goal_x = i / 2;
                goal_y = y;
            }
        }
        free(line);
		y++;
    }

    close(fd);

	write(1, "055", 3);

    if (myx < goal_x) {
        for (int i = myx; i < goal_x; i++) {
            write(1, "R", 1);
        }
    } else {
        for (int i = myx; i > goal_x; i--) {
            write(1, "L", 1);
        }
    }

    if (myy < goal_y) {
        for (int i = myy; i < goal_y; i++) {
            write(1, "D", 1);
        }
    } else {
        for (int i = myy; i > goal_y; i--) {
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

	print_easy_route(argv[1]);

	field **map = get_map(argv[1]);
	if (!map) {
		printf("Error: Invalid map file\n");
		return 1;
	}

	gen_fastest_routes(map);

	return 0;
}