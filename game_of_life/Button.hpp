#pragma once
#include <SFML/Graphics.hpp>
#include <functional>

class Button : sf::Drawable
{
public:
	Button(std::string _label, int _x, int _y, int _width, int _height,std::function<void()> _callback);
	Button(std::string _label, int _x, int _y, int _width, int _height);

	bool is_hovered(int mouse_pos_x, int mouse_pos_y);
	void draw(sf::RenderWindow& _window, sf::RenderStates states);

private:

	std::string label_;
	unsigned int id_;
};