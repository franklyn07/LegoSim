#ifndef UNIVERSITY_BUILDER_H
#define UNIVERSITY_BUILDER_H

#include "builder.h"

class University_builder:public virtual Builder{
	public:
		//inheriting constructors
		using Builder::Builder;
		Building* build(Quarry* quarry);
};

#endif 