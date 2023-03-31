#pragma once
#include <SFML/Graphics.hpp>
#include <functional>

class Button
{
public:
	Button(std::string _label, sf::Vector2f _pos, sf::Vector2f _size,std::function<void()> _callback, bool _clickable);
	Button(std::string _label, sf::Vector2f _pos, sf::Vector2f _size,bool _clickable);

	void update(const sf::Event& _event);
	void draw(sf::RenderTarget& _window);
	void set_callback(std::function<void()> _func) { clicked_callback_ = _func; };


private:
	void default_callback();
	void hovered_callback();
	bool is_hovered(int mouse_pos_x, int mouse_pos_y);
	

private:
	std::string label_;
	sf::Vector2f pos_;
	sf::Vector2f size_;
	std::function<void()> clicked_callback_;
	bool hovered_state_ = false;
	bool clickable_;
	sf::Color color_ = sf::Color(127,127,127,127);
	sf::RectangleShape button_rect_;
	sf::Font font_;
};