#include "_1storey.h"
#include <iostream>

_1Storey::_1Storey(){
	doors = 1;
	windows = 1;
	bricks = 10;
}

void _1Storey::identifier(){
	std::cout<<"I am a one storey house."<<std::endl;
}