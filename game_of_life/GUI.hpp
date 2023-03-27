#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class GUI
{
public:
	GUI(sf::Window* _window);

private:
	std::vector<std::unique_ptr<sf::Drawable>> drawable_objects_;

};