#include "../includes/a-star.h"

/**
 * W = 0
 * A = 1
 * E = 2
*/
int skills[3] = {5, 5, 0};
int cost = -1;

int heuristic(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

bool is_valid(int x, int y, int map_size_x, int map_size_y) {
	return x >= 0 && x < map_size_x && y >= 0 && y < map_size_y;
}

bool is_end(int x, int y, int goal_x, int goal_y) {
	return x == goal_x && y == goal_y;
}

void print_path(node* current, int i, int j, int k) {
    // Print i, j, k only once at the beginning of the line
    if (current->parent == NULL) {
		char chr;
		chr = i + '0';
		write(1, &chr, 1);
		chr = j + '0';
		write(1, &chr, 1);
		chr = k + '0';
		write(1, &chr, 1);
    }
    if (current->parent != NULL) {
        print_path(current->parent, i, j, k);
        int x_diff = current->x - current->parent->x;
        int y_diff = current->y - current->parent->y;
        if (x_diff == 1) {
            write(1, "R", 1);
        } else if (x_diff == -1) {
            write(1, "L", 1);
        } else if (y_diff == 1) {
            write(1, "D", 1);
        } else if (y_diff == -1) {
            write(1, "U", 1);
        }
    }
}


size_t get_map_size_x(field** map) {
	size_t map_size_x = 0;
	while (map[0][map_size_x].cost_mult != -1) {
		map_size_x++;
	}
	return map_size_x;
}

size_t get_map_size_y(field** map) {
	size_t map_size_y = 0;
	while (map[map_size_y]) {
		map_size_y++;
	}
	return map_size_y;
}

double get_cost(int mult, char type)
{
	/**
	 * 0 -> 4
	 * 1 -> 3
	 * 2 -> 2.5
	 * 3 -> 2
	 * 4 -> 1.5
	 * 5 -> 1
	*/
	double multiplier[6] = {4.0, 3.0, 2.5, 2.0, 1.5, 1.0};

	if(type == 'W')
		return multiplier[skills[0]] *= mult;
	else if(type == 'A')
		return multiplier[skills[1]] *= mult;
	else if(type == 'E')
		return multiplier[skills[2]] *= mult;
	return 100000;
}

void gen_fastest_routes(field** map)
{
	for (int i = 0; i <= 5; ++i) {
        for (int j = 0; j <= 5; ++j) {
            for (int k = 0; k <= 5; ++k) {
                // Check if the sum is not more than 10
                if (i + j + k <= 10) {
                    skills[0] = i;
					skills[1] = j;
					skills[2] = k;
					if (a_star(map, i, j, k))
					{
						// return;
					}
                }
            }
        }
    }
}

bool a_star(field** map, int i, int j, int k) {

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

	if (myx == -1 || myy == -1 || goal_x == -1 || goal_y == -1) {
		return false;
	}

	
	node* open_list[map_size_x * map_size_y];
	node* closed_list[map_size_x * map_size_y];
	int open_list_size = 0;
	int closed_list_size = 0;

	node* start_node = malloc(sizeof(node));
	start_node->x = myx;
	start_node->y = myy;
	start_node->g = 0;
	start_node->h = heuristic(myx, myy, goal_x, goal_y);
	start_node->f = start_node->g + start_node->h;
	start_node->parent = NULL;

	open_list[open_list_size++] = start_node;

	while (open_list_size > 0) {
		node* current = open_list[0];
		int current_index = 0;
		for (int i = 1; i < open_list_size; i++) {
			if (open_list[i]->f < current->f) {
				current = open_list[i];
				current_index = i;
			}
		}

		if (is_end(current->x, current->y, goal_x, goal_y)) {
			if(cost == -1 || cost > current->g)
			{
				cost = current->g;
				print_path(current, i, j, k);
				write(1, "\n", 1);
				free(current);
				return true;
			}
			return false;
		}

		open_list[current_index] = open_list[--open_list_size];
		closed_list[closed_list_size++] = current;

		int x = current->x;
		int y = current->y;

		int dx[4] = {1, -1, 0, 0};
		int dy[4] = {0, 0, 1, -1};

		for (int i = 0; i < 4; i++) {
			int new_x = x + dx[i];
			int new_y = y + dy[i];

			if (!is_valid(new_x, new_y, map_size_x, map_size_y)) {
				continue;
			}

			int g = current->g + get_cost(map[new_y][new_x].cost_mult, map[new_y][new_x].type);
			int h = heuristic(new_x, new_y, goal_x, goal_y);
			int f = g + h;

			node* child = malloc(sizeof(node));
			child->x = new_x;
			child->y = new_y;
			child->g = g;
			child->h = h;
			child->f = f;
			child->parent = current;

			bool in_closed_list = false;
			for (int j = 0; j < closed_list_size; j++) {
				if (closed_list[j]->x == child->x && closed_list[j]->y == child->y) {
					in_closed_list = true;
					break;
				}
			}
			if (in_closed_list) {
				continue;
			}

			bool in_open_list = false;
			int open_list_index = -1;
			for (int j = 0; j < open_list_size; j++) {
				if (open_list[j]->x == child->x && open_list[j]->y == child->y) {
					in_open_list = true;
					open_list_index = j;
					break;
				}
			}
			if (in_open_list) {
				if (child->f < open_list[open_list_index]->f) {
					open_list[open_list_index] = child;
				} else {
					free(child);
				}
			} else {
				open_list[open_list_size++] = child;
			}
		}
	}
	return false;
}
