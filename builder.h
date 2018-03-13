#ifndef BUILDER_H
#define BUILDER_H

#include"building_factory.h"
#include"quarry.h"
#include <string>

class Builder{
	//protected so that inheriting classes also have access to them
	protected:
		std::string name;
		int bricks_needed;
		int doors_needed;
		int windows_needed;

		Building_Factory* factory;

	public:
		Builder();
		Builder(std::string name);
		virtual ~Builder();
		void get_name();
		virtual Building* build(Quarry* quarry)=0;
		bool material_checker(int doors, int bricks, int windows, Quarry* quarry);
};

#endif 