#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class GUI
{
public:
	GUI(sf::Window* _window);
	void render_objects();

private:
	std::vector<std::unique_ptr<sf::Drawable>> drawable_objects_;

};                                                                   