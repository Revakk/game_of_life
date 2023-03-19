#pragma once
#include <map>

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
