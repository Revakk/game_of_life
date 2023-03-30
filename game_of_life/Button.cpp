#include "Button.hpp"
#include <iostream>

Button::Button(std::string _label, sf::Vector2f _pos, sf::Vector2f _size, std::function<void()> _callback):
	label_(_label),pos_(_pos),size_(_size),clicked_callback_(_callback)
{
	
}

Button::Button(std::string _label, sf::Vector2f _pos, sf::Vector2f _size):
	label_(_label), pos_(_pos), size_(_size),clicked_callback_(std::bind(&Button::default_callback,this))
{
}

void Button::update(const sf::Event& _event)
{
	if (_event.type == sf::Event::MouseMoved)
	{
		hovered_callback();
	}
}

/*
* @brief this function should implement "collision" detection with mouse
*/
bool Button::is_hovered(int mouse_pos_x, int mouse_pos_y)
{
	return false;
}


void Button::draw(sf::RenderTarget& _window, sf::RenderStates states) const
{
	sf::RectangleShape button_rect;
	button_rect.setPosition(pos_);
	button_rect.setSize(sf::Vector2f(size_));
	button_rect.setOutlineThickness(2.5f);
	button_rect.setOutlineColor(sf::Color::Black);
	_window.draw(button_rect);
}

void Button::hovered_callback()
{
	std::cout << "Button " << label_ << " is hovered" << '\n';
}

void Button::default_callback()
{
	std::cout << "Button " << label_ << " has been clicked" << '\n';
}
