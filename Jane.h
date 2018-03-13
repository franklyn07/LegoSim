#ifndef JANE_H
#define JANE_H

#include "university_builder.h"
#include "hospital_builder.h"


class Jane:public Hospital_builder, public University_builder{
	private:
		Building* build(Quarry* quarry);
	public:
		Jane();
};

#endif 