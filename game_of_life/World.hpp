#pragma once
#include <map>

enum class MouseBTN
{
	NONE,
	LEFT_CLICK,
	RIGHT_CLICK,
	MIDDLE_CLICK
};

struct MouseWorldEvent
{
	sf::Vector2f last_pos;
	MouseBTN click = MouseBTN::NONE;
	bool holding = false;
};

void update_mouse_event(MouseWorldEvent& _last_event,sf::Event& _current_mouse_event)
{
	if (sf::Event::MouseMoved == _current_mouse_event.type)
	{
		_last_event.last_pos.x = _current_mouse_event.mouseMove.x;
		_last_event.last_pos.y = _current_mouse_event.mouseMove.y;
	}
	if (sf::Event::MouseButtonPressed == _current_mouse_event.type)
	{
		//switch(_current_mouse_event.mouseButton)
	}
}

struct WorldSize {
	size_t width;
	size_t height;
	size_t pixel_size;

};

template<typename Cell>
struct World {
	WorldSize world_size{ 20,20,25 };
	std::map<size_t,std::map<size_t,Cell>> cells;

	auto get_bounds() const;
	std::vector<Cell> initialize_cells();
	void modify_world(std::vector<Cell>& _world,sf::Event& _event);
	MouseWorldEvent mouse_event;
};

template<typename Cell>
auto World<Cell>::get_bounds() const {
	return std::make_tuple(world_size.width, world_size.height, world_size.pixel_size);
}

template<typename Cell>
std::vector<Cell> World<Cell>::initialize_cells() {

	//can do later random or fixed blocks

	//now initialize everything to 0
	std::vector<Cell> alive_cells;
	auto outer_map = std::map<size_t, std::map<size_t, Cell>>();
	for (size_t x = 0; x < world_size.width; ++x)
	{
		auto inner_map = std::map<size_t, Cell>();
		for (size_t y = 0; y < world_size.height;++y)
		{
			if (x == 10 && y == 11)
			{
				alive_cells.emplace_back(Cell(x, y, true));
				inner_map[y] = Cell(x, y, true);
			}
			/*else if (x == 2 && y == 2)
			{
				alive_cells.emplace_back(Cell(x, y, true));
				inner_map[y] = Cell(x, y, true);
			}*/
			else if (x == 10 && y == 12)
			{
				alive_cells.emplace_back(Cell(x, y, true));
				inner_map[y] = Cell(x, y, true);
			}
			else if (x == 11 && y == 11)
			{
				alive_cells.emplace_back(Cell(x, y, true));
				inner_map[y] = Cell(x, y, true);
			}
			else if (x == 11 && y == 12)
			{
				alive_cells.emplace_back(Cell(x, y, true));
				inner_map[y] = Cell(x, y, true);
			}
			else if (x == 12 && y == 13)
			{
				alive_cells.emplace_back(Cell(x, y, true));
				inner_map[y] = Cell(x, y, true);
			}
			else if (x == 12 && y == 14)
			{
				alive_cells.emplace_back(Cell(x, y, true));
				inner_map[y] = Cell(x, y, true);
			}
			else if (x == 13 && y == 13)
			{
				alive_cells.emplace_back(Cell(x, y, true));
				inner_map[y] = Cell(x, y, true);
			}
			else if (x == 13 && y == 14)
			{
				alive_cells.emplace_back(Cell(x, y, true));
				inner_map[y] = Cell(x, y, true);
			}
			else
			{
				inner_map[y] = Cell(x, y, false);
			}
			
			/*if (x == y) {
				alive_cells.emplace_back(Cell(x, y,true));
				inner_map[y] = Cell(x, y,true);
			}*/
			
		}
		outer_map[x] = inner_map;
	}

	cells = outer_map;

	return alive_cells;
}

sf::Vector2i find_corresponding_cell(sf::Vector2f& _mouse_input_pos,size_t _cell_size_in_px)
{
	int x = _mouse_input_pos.x / _cell_size_in_px;
	int y = _mouse_input_pos.y / _cell_size_in_px;

	return sf::Vector2i(x, y);
}

template<typename Cell>
void World<Cell>::modify_world(std::vector<Cell>& _alive_cells, sf::Event& _event)
{
	auto cell_size_in_px = world_size.pixel_size;
	
	//bool mouse_b_hold = false;

	auto mouse_pos = sf::Vector2f(_event.mouseButton.x, _event.mouseButton.y);
	
	if (sf::Event::MouseMoved == _event.type)
	{
		//std::cout << _event.mouseMove.x << ',' << _event.mouseMove.y << '\n';
		mouse_pos = sf::Vector2f(_event.mouseMove.x, _event.mouseMove.y);;
	}


	if (sf::Event::MouseButtonPressed == _event.type || mouse_event.holding)
	{
		mouse_event.holding = true;
		

		auto target_cell_pos = find_corresponding_cell(mouse_pos, cell_size_in_px);
		Cell target_cell{ target_cell_pos.x, target_cell_pos.y, false };


		if(_event.mouseButton.button == sf::Mouse::Button::Left || mouse_event.click == MouseBTN::LEFT_CLICK)
			{
			mouse_event.click = MouseBTN::LEFT_CLICK;
			_alive_cells.emplace_back(Cell(target_cell.x,target_cell.y,true));
			}
		if (_event.mouseButton.button ==  sf::Mouse::Button::Right || mouse_event.click == MouseBTN::RIGHT_CLICK)
		{
			mouse_event.click = MouseBTN::RIGHT_CLICK;
			_alive_cells.erase(std::remove_if(_alive_cells.begin(), _alive_cells.end(), [this,&target_cell](const Cell& _cell)
				{
					if (target_cell == _cell)
					{
						cells[target_cell.x][target_cell.y].is_alive = false;
						return true;
					}
					else 
					{
						return false;
					}
					
				}),_alive_cells.end());
		}
	}
	if (sf::Event::MouseButtonReleased == _event.type)
	{
		mouse_event.holding = false;
		mouse_event.click = MouseBTN::NONE;
	}
}
