#pragma once
#include <SFML/Graphics.hpp>
#include <functional>

class Button : sf::Drawable
{
public:
	Button(std::string _label, int _x, int _y, int _width, int _height,std::function<void()> _callback);
	Button(std::string _label, int _x, int _y, int _width, int _height);

	bool is_hovered(int mouse_pos_x, int mouse_pos_y);
	virtual void draw(sf::RenderWindow& _window, sf::RenderStates states) const;

private:
	void default_callback();


private:
	std::function<void()> callback_;
	std::string label_;
	unsigned int id_;
	int x_;
	int y_;
	int width_;
	int height_;
};