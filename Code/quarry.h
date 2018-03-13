#ifndef QUARRY_H
#define QUARRY_H

#include "linked_list.h"
#include "lego_factory.h"
#include "door.h"
#include "window.h"
#include "brick.h"

class Quarry{
	private:
		Linked_list<Brick> brick_list;
		Linked_list<Door> door_list;
		Linked_list<Window> window_list;

		//pointer to the supplying lego_factory
		Lego_Factory *lego_factory;

		//private constructor and destructor
		Quarry();
		~Quarry();

		//static pointer to quarry 
		static Quarry* quarry;

	public:
		//method which ensures sinlge quarry is constructed(singleton pattern)
		static Quarry* instance();

		//similar method which destorys single quarry
		static void reset_instance();

		//insert amount of supply in quarry
		void add_bricks(int amnt);
		void add_windows(int amnt);
		void add_doors(int amnt);
		
		//remove an amount of supply from quarry
		void remove_bricks(int amnt);
		void remove_windows(int amnt);
		void remove_doors(int amnt);
		
		//return amount of supply remaining
		int amnt_doors();
		int amnt_windows();
		int amnt_bricks();

		//check whether sufficient material is present
		bool check_amount(int to_remove, int present);
};


#endif