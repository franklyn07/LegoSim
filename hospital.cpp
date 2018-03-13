#include "hospital.h"
#include <iostream>

Hospital::Hospital(){
	doors = 10;
	windows = 15;
	bricks = 60;
}

void Hospital::identifier(){
	std::cout<<"I am a hospital."<<std::endl;
}