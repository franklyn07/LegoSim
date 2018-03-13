#ifndef HOSPITAL_BUILDER_H
#define HOSPITAL_BUILDER_H

#include "builder.h"

class Hospital_builder:public virtual Builder{
	public:
		//inheriting constructors
		using Builder::Builder;
		Building* build(Quarry* quarry);
};

#endif 