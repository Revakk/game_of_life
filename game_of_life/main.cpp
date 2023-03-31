#include "Common.hpp"
#include <thread>
#include "GUI.hpp"
#include "Button.hpp"
#include <variant>




int main()
{
	World<Cell> world;
	std::vector<Cell> alive_cells = world.initialize_cells();	
	bool simulation_running = false;


	auto custom_width = world.world_size.width * world.world_size.pixel_size + 50;
	auto custom_height = world.world_size.height * world.world_size.pixel_size;

	Button start_button("Start", sf::Vector2f(custom_width - 40, 20), sf::Vector2f(35, 15),true);
	
	start_button.set_callback([]() {std::cout << "Clicked from the callback function" << '\n'; });

	
	sf::RenderWindow window(sf::VideoMode(custom_width, custom_height), "Game of lajf");
	/*GUI gui(&window);

	gui.add_drawable(Button("label",sf::Vector2f(200,200), sf::Vector2f(100,10)));*/

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			start_button.update(event);

			if (!simulation_running)
			{
				world.modify_world(alive_cells, event);
			}
			
		}
		window.clear(sf::Color::White);
		
		update(world, alive_cells,simulation_running);
		
		render(world,window);
		//gui.draw_gui();
		
		
		
		start_button.draw(window);
		window.display();
		//std::this_thread::sleep_for(std::chrono::duration<int>(1));
		
	}
	
	return 0;
}