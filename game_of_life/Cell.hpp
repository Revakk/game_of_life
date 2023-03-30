#pragma once

struct Cell
{
	int x;
	int y;
	bool is_alive= false;
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
