#pragma once
#include <SFML/Graphics.hpp>
#include <vector>


class GUI
{
public:
	GUI(sf::RenderWindow* _window);
	void render_objects();
	void draw_gui();
	void check_hovered_items(int _mouse_pos_x, int _mouse_pos_y);
	void update(const sf::Event& _event);

	template<typename T>
	void add_drawable(T _drawable);

private:
	std::vector<std::unique_ptr<sf::Drawable>> drawable_objects_;
	sf::RenderWindow* window_ = nullptr;
};

template<typename T>
inline void GUI::add_drawable(T _drawable)
{
	drawable_objects_.emplace_back(std::make_unique<T>(_drawable));
}