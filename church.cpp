#include "church.h"
#include <iostream>

Church::Church(){
	doors = 3;
	windows = 10;
	bricks = 40;
}

void Church::identifier(){
	std::cout<<"I am a church."<<std::endl;
}