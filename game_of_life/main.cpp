#include "Common.hpp"
#include <thread>
#include "GUI.hpp"
#include "Button.hpp"

int main()
{
	World<Cell> world;
	std::vector<Cell> alive_cells = world.initialize_cells();;

	auto custom_width = world.world_size.width * world.world_size.pixel_size + 200;
	auto custom_height = world.world_size.height * world.world_size.pixel_size + 200;

	


	sf::RenderWindow window(sf::VideoMode(custom_width, custom_height), "Game of lajf");
	GUI gui(&window);

	gui.add_drawable(Button("label",sf::Vector2f(200,200), sf::Vector2f(100,10)));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::White);
		update(world, alive_cells);
		
		render(world,window);
		gui.draw_gui();
		
		
		window.display();
		std::this_thread::sleep_for(std::chrono::duration<int>(1));
		
	}
	
	return 0;
}