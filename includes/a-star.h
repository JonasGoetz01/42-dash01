#ifndef A_STAR_H
#define A_STAR_H

#include "../includes/parsing.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void gen_fastest_routes(field** map);
bool is_valid(int x, int y, int map_size_x, int map_size_y);
bool is_end(int x, int y, int end_x, int end_y);
int heuristic(int x1, int y1, int x2, int y2);
bool a_star(field ** map, int i, int j, int k);
void print_path(node* current, int i, int j, int k);
size_t get_map_size_y(field** map);
size_t get_map_size_x(field** map);

#endif // A-STAR_H