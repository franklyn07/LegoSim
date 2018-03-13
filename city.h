#ifndef CITY_H
#define CITY_H

#include "linked_list.h"
#include "building.h"
#include "_1storey.h"
#include "_2storey.h"
#include "church.h"
#include "university.h"
#include "hospital.h"
#include <string>

class City{
	private:
		Linked_list<Building> building_list;
	public:
		void addBuilding(Building* b);
		int getSize();
		void generateReport(int reqUni, int reqChr, int req1Sh, int req2Sh, int reqHosp);
		~City();
};

#endif 