#ifndef BUILDING_H
#define BUILDING_H

class Building{
	//protected such that derived buildings inherit the variables
	protected:
		int doors;
		int windows;
		int bricks;
	//all methods here are abstract since building cannot exist 
	public:
		virtual void identifier()=0;
		//since I want to use the compiler generated version of the destructor w/o adding
		//anything to the body, I use the keyword default.
		virtual ~Building()=default;
		int get_doors();
		int get_windows();
		int get_bricks();
};

#endif 