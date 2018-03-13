#include "_2storey.h"
#include <iostream>

_2Storey::_2Storey(){
	doors = 1;
	windows = 3;
	bricks = 20;
}

void _2Storey::identifier(){
	std::cout<<"I am a two storey house."<<std::endl;
}