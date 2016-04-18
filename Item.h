//---------------------------------------------------------------------------
// ITEM.H
// The parent class that represents a generic item
//---------------------------------------------------------------------------
// Item Class: 
//   -- pure virtual function of comparing items together
//   -- pure virtual function of displaying information about item
//   -- pure virtual function of initializing items to contain correct info
//
// Implementation and assumptions:
//   -- This class will never be created by it self. 
//   -- This is only a parent object not a object that will be initialized. 
//---------------------------------------------------------------------------
#pragma once
#include <string>
#include <iostream>
#include "Format.h"
#include "Person.h"
#include "Dvd.h"
using namespace std;
class Item
{
	
public:
	//constructors
	Item();
	virtual ~Item();

	// gets items format type
	virtual Format* getFormat() const = 0;

	// comparing if items are equal to each other
	virtual bool operator==(const Item &) const = 0;
	// comparing if items are less to each other
	virtual bool operator<(const Item &) const = 0;
	
	// create object
	virtual Item* create() const = 0; 

	//initialize object to store inside of store
	virtual void initialize(istream &infile) = 0;
	//initialize object to compare to other objects
	virtual void initCompObj(istream &infile) = 0; 

	//display information
	virtual void displayInfo() const = 0; 
	//display header for particular item
	virtual void displayHeader() const = 0;
	//display Transaction information about item
	virtual void displayTranInfo() const = 0; 
};

