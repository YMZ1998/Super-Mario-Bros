#pragma once

#include "Global.hpp"
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>

void draw_map(unsigned i_view_x, const sf::Image& i_map_sketch, sf::RenderWindow& i_window, const sf::Texture& i_map_texture, const Map& i_map);
