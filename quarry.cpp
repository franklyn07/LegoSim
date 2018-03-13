#include "quarry.h"

Quarry* Quarry::quarry = nullptr;

Quarry::Quarry(){
	//initialise lego piece factory.
	lego_factory = new Lego_Factory();
}

//initialisation in singleton pattern
Quarry* Quarry::instance(){
	//check that static reference is empty
	if(quarry == nullptr){
		//if it is empty it means that no instances are present
		//we can initialiase a new object and return a reference to it.
		quarry = new Quarry();
		std::cout<<"Quarry initialised!"<<std::endl;
	}
	//note that since its a static reference, and initialisation is done
	//privately on a single static reference, there can only be one object
	//of the type quarry per execution of program.
	return quarry;
}

void Quarry::reset_instance(){
	if(nullptr!=quarry){
		delete quarry;
		quarry = nullptr;
	}
}

//Note on following 3 methods:
//we use static cast to typecast to derived class at compile time, in order to be able to store it in linked list
//since linked list only accepts one type (bricks)(cant have a pointer of type legopieces)

void Quarry::add_bricks(int amnt){
	for(int i = 0; i<amnt;i++){
		brick_list.Add_entry(static_cast<Brick*>(lego_factory->get_piece("brick")));
	}
}

void Quarry::add_windows(int amnt){
	for(int i = 0; i<amnt;i++){
		window_list.Add_entry(static_cast<Window*>(lego_factory->get_piece("window")));
	}
}

		
void Quarry::add_doors(int amnt){
	for(int i = 0; i<amnt;i++){
		door_list.Add_entry(static_cast<Door*>(lego_factory->get_piece("door")));
	}	
}
		
void Quarry::remove_bricks(int amnt){
	if(check_amount(amnt,amnt_bricks())==true){
		for(int i = 0; i<amnt;i++){
			brick_list.Delete_last_entry();
		}
	}else{
		std::cout<<"Insufficient amount of bricks!"<<std::endl;
	}
}
		
void Quarry::remove_windows(int amnt){
	if(check_amount(amnt,amnt_windows())==true){
		for(int i = 0; i<amnt;i++){
			window_list.Delete_last_entry();
		}
	}else{
		std::cout<<"Insufficient amount of windows!"<<std::endl;
	}
}
		
void Quarry::remove_doors(int amnt){
	if(check_amount(amnt,amnt_doors())==true){
		for(int i = 0; i<amnt;i++){
			door_list.Delete_last_entry();
		}
	}else{
		std::cout<<"Insufficient amount of doors!"<<std::endl;
	}
}

int Quarry::amnt_doors(){
	return door_list.Show_contents();
}
		
int Quarry::amnt_windows(){
	return window_list.Show_contents();
}
		
int Quarry::amnt_bricks(){
	return brick_list.Show_contents();
}

bool Quarry::check_amount(int to_remove, int present){
	if (to_remove>present){
		return false;
	}else{
		return true;
	}
}

Quarry::~Quarry(){
	delete lego_factory;
	brick_list.Delete();
	door_list.Delete();
	window_list.Delete();
}