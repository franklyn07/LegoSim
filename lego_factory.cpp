#include "lego_factory.h"

Lego_piece* Lego_Factory::get_piece(std::string lego_type){	
    if(lego_type == "brick"){
    	//return pointer to new object brick
       return new Brick();
    } else if(lego_type == "window"){
    	//return pointer to new object window
       return new Window();
    } else if(lego_type == "door"){
    	//return pointer to new object door
        return new Door();
    }
    //invalid input, return nullptr
    return nullptr;
}

