#pragma once
#include <SFML/Graphics.hpp>
#include <type_traits>
#include <algorithm>
#include <numeric>
#include <ranges>
#include <map>
#include <assert.h>
#include <iostream>
#include "GUI.hpp"

template<typename T>
void render(T& _render_target,sf::RenderWindow& _window)
{
	auto [w, h, ps] = _render_target.get_bounds();

	for (auto const & [o_map_id, o_map] : _render_target.cells) {
		for (auto const & [i_map_id, cell] : o_map) {
			/*if (i_map_id == o_map_id)
			{
				cell.is_alive = true;
			}*/
			sf::RectangleShape rectangle(sf::Vector2f(9, 9));
			rectangle.setPosition(sf::Vector2f((o_map_id * 10), (i_map_id * 10)));
			rectangle.setOutlineThickness(1.0f);
			rectangle.setOutlineColor(sf::Color::Color(127,127,127,255));
			//std::cout << rectangle.getPosition().x << ',' << rectangle.getPosition().y << '\n';

			if (cell.is_alive)
			{
				rectangle.setFillColor(sf::Color::Black);
				//std::cout << "alive cell" << '\n';
			}
			_window.draw(rectangle);
			//_window.display();
		}
	}
}