#include "GUI.hpp"

GUI::GUI(sf::RenderWindow* _window): window_(_window)
{
}

void GUI::render_objects()
{
	for (auto& drawable_object : drawable_objects_)
	{
		window_->draw(*(drawable_object.get()));
	}
}

void GUI::draw_gui()
{
	render_objects();
}

void GUI::check_hovered_items(int _mouse_pos_x, int _mouse_pos_y)
{
}

void GUI::update(const sf::Event& _event)
{
	/*for (auto& drawable_object : drawable_objects_)
	{
		drawable_object->update();
	}*/
}
