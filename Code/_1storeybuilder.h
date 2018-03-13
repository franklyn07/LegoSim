#ifndef _1STOREY_BUILDER_H
#define _1STOREY_BUILDER_H

#include "builder.h"

class _1Storeybuilder:public virtual Builder{
	public:
		//inheriting constructors
		using Builder::Builder;
		Building* build(Quarry* quarry);
};

#endif 