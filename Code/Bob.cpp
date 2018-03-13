#include "Bob.h"

Bob::Bob(){
	name = "Bob";
}

//overriding method which will never be used.
//created such that the diamond inheritance will still work, even though base class builder is virtual
//"You simply are not allowed to have a situation in which a virtual function has more than one final overrider in any derived class that exists in your program."
//Note that you can also access other derived classes' build functions through _1Storeybuilder::build(Quarry* quarry)

Building* Bob::build(Quarry* quarry){
	return nullptr;
}