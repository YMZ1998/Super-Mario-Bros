#pragma once

#include "Global.hpp"
#include <vector>

unsigned char map_collision(float i_x, float i_y, const std::vector<Cell>& i_check_cells, const Map& i_map);
