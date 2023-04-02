#pragma once

struct Cell
{
	int x;
	int y;
	bool is_alive= false;


	bool operator==(const Cell& _other_cell) const
	{
		if (x == _other_cell.x && y == _other_cell.y)
		{
			return true;
		}
		return false;
	}
};


namespace std {
	template<> struct hash<Cell> {
		std::size_t operator()(const Cell& _cell) const noexcept
		{
			size_t hash = _cell.x + 1000 * _cell.y;
			return hash;
		}
	};
}

enum class cell_state {
	DEAD,
	ALIVE,
};

enum class pattern_types {
	STILL,
	OSCILLATOR,
	SPACESHIP
};
