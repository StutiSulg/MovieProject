// file Format.h
// Format parent class that represents general format
#pragma once
#include <string>
using namespace std; 

//---------------------------------------------------------------------------
// Formate class: is a parent class that represent the different type of
// formats a movie can come in, it: 
//   -- allows to get the number of copies avaliable in that formate
//   -- allows you to add/remove a copy 
//   -- allows you to get the total amout of this particular format
// Assumption: 
//   -- this class will not be created by itself
//---------------------------------------------------------------------------

class Format
{
public:
	// Constructors
	Format();
	~Format();

	//adds 1 to current inventory in stock
	bool add(); 
	// removes 1 from current inventory instock
	bool remove();
	// get total amount of movies in inventory
	int getQuantity() const; 
	// get current inventory in stock 
	int getCurrStock() const; 
	// returns movie format ex. DVD
	string getType() const; 

protected: 
	//set in child class
	string type; 
	// total amount of copies
	int inStock;
	// copies we own set in child class
	int totalCopies; 

};

