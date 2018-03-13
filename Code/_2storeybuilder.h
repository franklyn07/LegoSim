#ifndef _2STOREY_BUILDER_H
#define _2STOREY_BUILDER_H

#include "builder.h"

class _2Storeybuilder:public virtual Builder{
	public:
		//inheriting constructors
		using Builder::Builder;
		Building* build(Quarry* quarry);

};

#endif 