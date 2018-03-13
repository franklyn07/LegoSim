#include "church_builder.h"


Building* Church_builder::build(Quarry* quarry){
	Building* building =factory->get_building("church");
	bricks_needed = building->get_bricks();
	windows_needed = building->get_windows();
	doors_needed = building->get_doors();

	if(	material_checker(doors_needed,bricks_needed,windows_needed,quarry)==true){	
		quarry->remove_bricks(bricks_needed);
		quarry->remove_doors(doors_needed);
		quarry->remove_windows(windows_needed);

		std::cout<<"Church Built!"<<std::endl;
		return building;
	}else{
		//deleting object since insufficient amount
		delete building;
		throw "Insufficient material to build church!";

	}
}