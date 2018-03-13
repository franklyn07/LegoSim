#ifndef BOB_H
#define BOB_H

#include "_1storeybuilder.h"
#include "_2storeybuilder.h"


class Bob:public _1Storeybuilder, public _2Storeybuilder{
	private:
		Building* build(Quarry* quarry);

	public:
		Bob();
};

#endif 