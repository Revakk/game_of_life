#pragma once

struct Cell
{
	int x;
	int y;
	bool is_alive= false;
};

//auto check_alive_neighbours(const Cell& _cell){
//	
//}

enum class cell_state {
	DEAD,
	ALIVE,
};

enum class pattern_types {
	STILL,
	OSCILLATOR,
	SPACESHIP
};
