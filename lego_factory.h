#ifndef LEGO_FACTORY
#define LEGO_FACTORY

#include <string>
#include "window.h"
#include "door.h"
#include "brick.h"

class Lego_Factory{
    public:
    	//since Lego_piece is an abstract class, it cannot return directly, thus you return a pointer to it.
    	//which in the factroy method will be used to point to either a brick, door or window, which all are
    	//inherited from lego_piece
        Lego_piece* get_piece(std::string lego_type);
        ~Lego_Factory()=default;
};

#endif