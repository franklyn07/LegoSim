#ifndef BUILDING_FACTORY
#define BUILDING_FACTORY

#include <string>
#include "_1storey.h"
#include "_2storey.h"
#include "church.h"
#include "hospital.h"
#include "university.h"

class Building_Factory{
    public:
    	//since Lego_piece is an abstract class, it cannot return directly, thus you return a pointer to it.
    	//which in the factroy method will be used to point to either a brick, door or window, which all are
    	//inherited from lego_piece
        Building* get_building(std::string building_type);
        //default destructor
        ~Building_Factory()=default;
};

#endif