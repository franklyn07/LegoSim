#include "builder.h"

Builder::Builder(){
	name = "Default name";
	factory = new Building_Factory();
}

Builder::Builder(std::string name){
	this->name=name;
	factory = new Building_Factory();
}

void Builder::get_name(){
	std::cout<<"My name is: "<<name<<std::endl;
}

bool Builder::material_checker(int doors, int bricks, int windows, Quarry* quarry){
	if(quarry->check_amount(doors_needed,quarry->amnt_doors())==true &&
		quarry->check_amount(bricks_needed,quarry->amnt_bricks()) == true &&
		quarry->check_amount(windows_needed,quarry->amnt_windows())== true){
		return true;
	}else{
		return false;
	}
}

Builder::~Builder(){
	delete factory;
}