#pragma once

struct Cell
{
	int x;
	int y;
	bool is_alive= false;


	bool operator==(const Cell& _other_cell)
	{
		if (x == _other_cell.x && y == _other_cell.y)
		{
			return true;
		}
		return false;
	}

};

enum class cell_state {
	DEAD,
	ALIVE,
};

enum class pattern_types {
	STILL,
	OSCILLATOR,
	SPACESHIP
};
