#ifndef CHURCH_BUILDER_H
#define CHURCH_BUILDER_H

#include "builder.h"

//here no need of virtual inheritance since there will be no diamond problem
class Church_builder:public Builder{
	public:
		//inheriting constructors
		using Builder::Builder;
		Building* build(Quarry* quarry);
};

#endif 