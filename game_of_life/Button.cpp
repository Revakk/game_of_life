#include "Button.hpp"
#include <iostream>

Button::Button(std::string _label, sf::Vector2f _pos, sf::Vector2f _size, std::function<void()> _callback, bool _clickable):
	label_(_label),pos_(_pos),size_(_size),clicked_callback_(_callback)
{
	button_rect_.setPosition(pos_);
	button_rect_.setSize(sf::Vector2f(size_));
	button_rect_.setOutlineThickness(0.5f);
	button_rect_.setOutlineColor(sf::Color::Black);
	button_rect_.setFillColor(color_);
	font_.loadFromFile("fonts/font.ttf");
}

Button::Button(std::string _label, sf::Vector2f _pos, sf::Vector2f _size, bool _clickable):
	label_(_label), pos_(_pos), size_(_size),clicked_callback_(std::bind(&Button::default_callback,this))
{
	button_rect_.setPosition(pos_);
	button_rect_.setSize(sf::Vector2f(size_));
	button_rect_.setOutlineThickness(0.5f);
	button_rect_.setOutlineColor(sf::Color::Black);
	button_rect_.setFillColor(color_);
	font_.loadFromFile("fonts/font.ttf");
}

void Button::update(const sf::Event& _event)
{
	if (_event.type == sf::Event::MouseMoved)
	{
		if (is_hovered(_event.mouseMove.x, _event.mouseMove.y))
		{
			hovered_state_ = true;
			hovered_callback();
		}
		else
		{
			hovered_state_ = false;
		}
	}
	if (_event.type == sf::Event::MouseButtonPressed)
	{
		/*
		if (hovered_state_)
		{
			std::cout << "mouse pressed" << '\n';
			clicked_callback_();
		}*/

		if (is_hovered(_event.mouseButton.x, _event.mouseButton.y))
		{
			clicked_callback_();
		}
	}
}

/*
* @brief this function should implement "collision" detection with mouse
*/
bool Button::is_hovered(int mouse_pos_x, int mouse_pos_y)
{
	if (button_rect_.getGlobalBounds().intersects(sf::FloatRect(mouse_pos_x, mouse_pos_y, 1, 1)))
	{
		color_.a = 255;
		return true;
	}
	else
	{
		color_.a = 127;
		return false;
	}	
}


void Button::draw(sf::RenderTarget& _window)
{
	sf::Text text(label_,font_,11);
	text.setPosition(pos_+sf::Vector2f(2.5f,0.0f));
	text.setFillColor(sf::Color(0, 0,0, 255));
	text.setOutlineColor(sf::Color(100, 100, 100, 100));
	//text.setColor(sf::Color(0, 0,0, 255));

	button_rect_.setFillColor(color_);

	_window.draw(button_rect_);
	_window.draw(text);
}

void Button::hovered_callback()
{

	std::cout << "Button " << label_ << " is hovered" << '\n';
}

void Button::default_callback()
{
	std::cout << "Button " << label_ << " has been clicked" << '\n';
}
