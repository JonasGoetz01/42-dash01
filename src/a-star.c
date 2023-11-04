#include "../includes/a-star.h"

int heuristic(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

bool is_valid(int x, int y, field** map, int map_size_x, int map_size_y) {
	return x >= 0 && x < map_size_x && y >= 0 && y < map_size_y && map[x][y].type != 'W';
}

bool is_end(int x, int y, int end_x, int end_y) {
	return x == end_x && y == end_y;
}

void print_path(node* current) {
	if (current->parent != NULL) {
		print_path(current->parent);
		int x_diff = current->x - current->parent->x;
		int y_diff = current->y - current->parent->y;
		if (x_diff == 1) {
			printf("D");
		} else if (x_diff == -1) {
			printf("U");
		} else if (y_diff == 1) {
			printf("R");
		} else if (y_diff == -1) {
			printf("L");
		}
	}
}

size_t get_map_size_x(field** map) {
	size_t map_size_x = 0;
	while (map[0][map_size_x].type != -1) {
		map_size_x++;
	}
	return map_size_x;
}

size_t get_map_size_y(field** map) {
	size_t map_size_y = 0;
	while (map[0][map_size_y].type) {
		map_size_y++;
	}
	return map_size_y;
}

void a_star(int start_x, int start_y, int end_x, int end_y, field** map) {
	size_t map_size_x = get_map_size_x(map);
	size_t map_size_y = get_map_size_y(map);
	
	node* open_list[map_size_x * map_size_y];
	node* closed_list[map_size_x * map_size_y];
	int open_list_size = 0;
	int closed_list_size = 0;

	node* start_node = malloc(sizeof(node));
	start_node->x = start_x;
	start_node->y = start_y;
	start_node->g = 0;
	start_node->h = heuristic(start_x, start_y, end_x, end_y);
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

		if (is_end(current->x, current->y, end_x, end_y)) {
			print_path(current);
			return;
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

			if (!is_valid(new_x, new_y, map, map_size_x, map_size_y)) {
				continue;
			}

			int g = current->g + map[new_x][new_y].cost_mult;
			int h = heuristic(new_x, new_y, end_x, end_y);
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
}
