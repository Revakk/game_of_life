#pragma once
#include <vector>
#include "Cell.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <unordered_set>

bool state_in_bounds(const std::pair<int, int>& _state, size_t _max_width, size_t _max_height)
{
	if (_state.first < _max_width
		&&
		_state.first > 0
		&&
		_state.second < _max_height
		&&
		_state.second > 0) {
		//std::cout << "State is in bounds" << '\n';
		return true;
	}
	else {
		//std::cout << "State is not in bounds" << '\n';
		return false;
	}
}

cell_state state_from_neighbours_count(int _num_alive_neighbours,bool _is_alive)
{
	if (_is_alive)
	{
		if (_num_alive_neighbours < 2 || _num_alive_neighbours > 3)
		{
			//std::cout << "CELL DIED" << '\n';
			return cell_state::DEAD;
		}
		else {
			return cell_state::ALIVE;

		}
	}
	else {
		if (_num_alive_neighbours == 3)
		{
			return cell_state::ALIVE;
		}
		else {
			return cell_state::DEAD;
		}
	}
	
}

template<typename T, typename Cell>
int check_neighbours(Cell _cell, T& _world, std::unordered_set<Cell>& _neighbouring_cells, bool _push_to_vector) {
	std::vector<std::pair<int, int>> states = {
		{-1,-1},
		{-1,0},
		{-1,1},
		{0,-1},
		{0,1},
		{1,-1},
		{1,0},
		{1,1}
	};

	auto [w, h, ps] = _world.get_bounds();

	int living_neighbours_count = 0;
	//std::cout << "Checking states for cell: " << _cell.x << ',' << _cell.y << '\n';
	for (const auto& state : states) {
		std::pair<int, int> current_state{ _cell.x + state.first, _cell.y + state.second };//std::make_pair<int,int>(_cell.x + state.first, _cell.y + state.second);

		//std::cout << current_state.first << ',' << current_state.second << '\n';

		if (state_in_bounds(current_state, w, h)) {
			if (_world.cells.at(current_state.first).at(current_state.second).is_alive)
			{
				living_neighbours_count++;
				//std::cout << "This neigbour is alive" << '\n';
			}
			else
			{
				//std::cout << "This neigbour is NOT alive" << '\n';
				_neighbouring_cells.insert(Cell(current_state.first, current_state.second, false));	
			}
		}
	}

	//std::cout << living_neighbours_count << '\n';
	return living_neighbours_count;
}



template<typename T,typename Cell>
void update(T& _world,std::vector<Cell>& _vec,bool _simmulating) {
	std::unordered_set<Cell> next_iter_check{};
	std::vector<Cell> cells_to_change{};
	std::unordered_set<Cell> neighbouring_cells{};

	//neighbouring_cells.reserve(_vec.size() * 8);
	next_iter_check.reserve(_vec.size());
	cells_to_change.reserve(_vec.size());
	
	if (_simmulating)
	{
		for (const auto& cell : _vec) {
			int alive_neighbours_count = check_neighbours(cell, _world,neighbouring_cells,true);
			if (state_from_neighbours_count(alive_neighbours_count,cell.is_alive) == cell_state::ALIVE)
			{
				next_iter_check.insert(cell);
				Cell cell_to_change = _world.cells[cell.x][cell.y];
				cell_to_change.is_alive = true;
				cells_to_change.emplace_back(cell_to_change);
				//_world.cells[cell.x][cell.y].is_alive = true;
			}
			else
			{
				Cell cell_to_change = _world.cells[cell.x][cell.y];
				cell_to_change.is_alive = false;
				cells_to_change.emplace_back(cell_to_change);
				//_world.cells[cell.x][cell.y].is_alive = false;
			}
		}

		for (const auto& cell : neighbouring_cells) {
			int alive_neighbours_count = check_neighbours(cell, _world, neighbouring_cells,false);
			if (state_from_neighbours_count(alive_neighbours_count, cell.is_alive) == cell_state::ALIVE)
			{
				next_iter_check.insert(cell);
				Cell cell_to_change = _world.cells[cell.x][cell.y];
				cell_to_change.is_alive = true;
				cells_to_change.emplace_back(cell_to_change);
			}
		}
		//_vec = next_iter_check;
		_vec = std::vector<Cell>(next_iter_check.begin(), next_iter_check.end());
	}
	else
	{
		cells_to_change = _vec;
		
	}

	for (auto& cell : cells_to_change)
	{
		_world.cells[cell.x][cell.y].is_alive = cell.is_alive;
	}

}