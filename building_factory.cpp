#include "building_factory.h"

Building* Building_Factory::get_building(std::string building){	
    if(building == "1storeyhouse"){
    	//return pointer to new object two storey house
       return new _1Storey();
    } else if(building == "2storeyhouse"){
    	//return pointer to new object one storey house
       return new _2Storey();
    } else if(building == "church"){
    	//return pointer to new object church
        return new Church();
    } else if(building == "hospital"){
    	//return pointer to new object hospital
    	return new Hospital();
    } else if(building == "university"){
    	//return pointer to new object university
    	return new University();
    }
    //invalid input, return nullptr
    return nullptr;
}