#include "university.h"
#include <iostream>

University::University(){
	doors = 10;
	windows = 20;
	bricks = 80;
}

void University::identifier(){
	std::cout<<"I am a university."<<std::endl;
}