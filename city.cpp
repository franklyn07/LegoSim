#include "city.h"

void City::addBuilding(Building* b){
    	building_list.Add_entry(b);
}
		
int City::getSize(){
	return building_list.Show_contents();
}
		
void City::generateReport(int reqUni, int reqChr, int req1Sh, int req2Sh, int reqHosp){
	int buildings_req = reqUni + reqChr + req1Sh + req2Sh + reqHosp;
	int buildings_prod = getSize();
	//casting one of the values to double since if we divide with 2 integers, we will achieve an integer value, and will not 
	//be stored correctly in double
	double perc_comp = (buildings_prod/(double)buildings_req)*100;
	std::cout<<"__________________________"<<std::endl;
	std::cout<<"Building requested: "<<buildings_req<<std::endl;
	std::cout<<"Buildings produced: "<<buildings_prod<<std::endl;
	std::cout<<"Percentage completed: "<<perc_comp<<"%"<<std::endl;
	std::cout<<"__________________________"<<std::endl;
}

City::~City(){
	building_list.Delete();
}