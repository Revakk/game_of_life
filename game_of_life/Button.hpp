#pragma once
#include <SFML/Graphics.hpp>
#include <functional>

class Button : public sf::Drawable
{
public:
	Button(std::string _label, sf::Vector2f _pos, sf::Vector2f _size,std::function<void()> _callback);
	Button(std::string _label, sf::Vector2f _pos, sf::Vector2f _size);

	void update(const sf::Event& _event);
	
	
protected:
	virtual void draw(sf::RenderTarget& _window, sf::RenderStates states) const;
	
private:
	void default_callback();
	void hovered_callback();
	bool is_hovered(int mouse_pos_x, int mouse_pos_y);
	

private:
	std::function<void()> clicked_callback_;
	sf::Color color_;
	std::string label_;
	unsigned int id_;
	sf::Vector2f pos_;
	sf::Vector2f size_;
};