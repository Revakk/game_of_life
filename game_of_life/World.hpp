#pragma once
#include <map>

struct mouse_world_event
{
	sf::Vector2f last_pos;
	bool left_click;
	bool right_click;
};

void update_mouse_event(mouse_world_event& _last_event,sf::Event& _current_mouse_event)
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
	WorldSize world_size{ 50,50,10 };
	std::map<size_t,std::map<size_t,Cell>> cells;

	auto get_bounds();
	std::vector<Cell> initialize_cells();
	void modify_world(std::vector<Cell>& _world,sf::Event& _event);
};

template<typename Cell>
auto World<Cell>::get_bounds() {
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
	
	if (sf::Event::MouseButtonPressed == _event.type)
	{
		auto mouse_pos = sf::Vector2f(_event.mouseButton.x, _event.mouseButton.y);
		auto target_cell = find_corresponding_cell(mouse_pos, cell_size_in_px);

		switch (_event.mouseButton.button)
		{
		case sf::Mouse::Button::Left:
			{
			_alive_cells.emplace_back(Cell(target_cell.x,target_cell.y,true));
			break;
			}
		case sf::Mouse::Button::Right:
		{
			/*_alive_cells.erase(std::remove(_alive_cells.begin(), _alive_cells.end(), [&target_cell](Cell _cell)
				{
					if (_cell.x == target_cell.x && _cell.y == target_cell.y)
					{
						return true;
					};
				}));*/
			break;
		}
		default:
			return;

		}
	}
	
}
