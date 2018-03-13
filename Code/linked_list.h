//since its a template, both definition of class as well as implementation will go in same header file
#ifndef LINKED_LIST
#define LINKED_LIST

#include "lego_piece.h"
//#include "node.h"
#include <iostream>

template<typename T>
class node{
public:
	T* piece;
	node<T>* next;
	~node()=default;
};

template<class T>
class Linked_list{
	private:
			node<T>* root;
			node<T>* last_elem;

	public:
		Linked_list();
		void Add_entry(T* new_piece);
		void Delete_last_entry();
		void Delete();
		int Show_contents();
};

template<class T>
Linked_list<T>::Linked_list(){
	root = nullptr;
	last_elem = nullptr;
}

template<class T>
//add new piece
void Linked_list<T>::Add_entry(T* new_piece){
	//create new node<T> and store adress in new_val
	node<T>* new_val = new node<T>;
	//assign piece to new node<T>, and make it last node<T>; thus pointing to nothing
	new_val -> piece = new_piece;
	new_val -> next = nullptr;


	//check whether linked list is empty
	if(root == nullptr){
		//if empty, store the address of new node<T> in the root
		root = new_val;
		//this will also be the last element
		last_elem = new_val;
	}else{
		//if not empty make the last node<T>'s next pointer, point to the new node<T>'s address
		last_elem->next = new_val;
		//store the address of the new node<T> as the last node<T>
		last_elem = new_val;
	}

	//delete previous new node<T> pointer after taking a copy of it to avoid duplication and memory
	new_val = nullptr;

}

template<class T>
//delete last item
void Linked_list<T>::Delete_last_entry(){
	//pointer to current node<T> (initialise pointing to address of root)
	node<T>* current = root;

	//pointer to second to last node<T> (this is needed since it will become last node<T> after deletion)
	node<T>* b4last;

	//traverse list from root up untill we find last node<T>(not included)
	while(current->next != nullptr){
		b4last = current;
		current = current->next;
	}
	//last_elem will be holding now the address of b4last
	last_elem = b4last;
	//making it last element
	b4last->next = nullptr;

	//removing pointer and its contents to avoid memory leaks
	delete current->piece;
	delete current;
}

template<class T>
//shows amount of items
int Linked_list<T>::Show_contents(){
	//create temporary pointer and initialise it pointing to root
	node<T>* current = root;
	int count = 0;

	//traverse list up untill we find the final node<T>
	if(root!=nullptr){
		while(current!=nullptr){
			count++;
			current = current-> next;
		}
	}
	return count;
	//removing pointer to avoid memory leaks
	delete current;
}

template <class T>
void Linked_list<T>::Delete(){
	node<T>* current = root;

	while(current != nullptr){
		node<T>* next_node = current->next;
		delete current->piece;
		delete current;
		current = next_node;
	}
}
#endif