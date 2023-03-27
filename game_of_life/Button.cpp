#include "Button.hpp"
#include <iostream>

Button::Button(std::string _label, int _x, int _y, int _width, int _height, std::function<void()> _callback):
	label_(_label),x_(_x),y_(_y),width_(_width),height_(_height)
{
}

Button::Button(std::string _label, int _x, int _y, int _width, int _height):
	label_(_label), x_(_x), y_(_y), width_(_width), height_(_height)
{
}


/*
* @brief this function should implement "collision" detection with mouse
*/
bool Button::is_hovered(int mouse_pos_x, int mouse_pos_y)
{
	return false;
}


/*
* @brief this function will be called in GUI class which will call this function on every sf::Drawable object, if its hovered it should appear more bright than default
*/
void Button::draw(sf::RenderWindow& _window, sf::RenderStates states) const
{
}

void Button::default_callback()
{
	std::cout << "Button " << label_ << " has been clicked" << '\n';
}
