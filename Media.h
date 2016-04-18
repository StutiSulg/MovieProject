//---------------------------------------------------------------------------
// MEDIA.H
// The Parent class of all the different movie generas
//---------------------------------------------------------------------------
// Media Class: 
//   -- pure virtual function of comparing items together
//   -- pure virtual function of displaying information about item
//   -- pure virtual function of initializing items to contain correct info
//
// Implementation and assumptions:
//   -- This class will never be created by it self. 
//   -- This is only a parent object not a object that will be initialized. 
//---------------------------------------------------------------------------
#pragma once
#include "Item.h"
#include <istream>


class Media : public Item
{
	//output overloaded function
	friend ostream & operator<<(ostream &, const Item &);
public:
	//constructor
	Media();
	virtual ~Media();

	// returns title of movie
	string getTitle() const; 

	// returns Formate which contains quantity
	Format* getFormat() const; 
	
	//initializes infomration about media 
	virtual void initialize(istream &infile); 
	
	// creates an empty object
	virtual Item* create() const = 0;
	//initializes item to compare to other items
	virtual void initCompObj(istream &infile) = 0;
	
	// comparing if items are equal to each other
	virtual bool operator==(const Item &) const = 0;
	// comparing if items are less to each other
	virtual bool operator<(const Item &) const = 0;
		
	//display information
	virtual void displayInfo() const = 0;
	//display header for particular item
	virtual void displayHeader() const = 0;
	//display Transaction information about item
	virtual void displayTranInfo() const = 0; 

protected:
	//title of movie
	string title; 
	//quantity of a certian formate
	Format *type; 
	Person director; 
	//year of creation
	int year; 
	
	// const for formatting output
	static const int TITLE_MAX_LENGTH = 22; 
	static const int DIRECTOR_MAX_LENGTH = 17; 
	static const int QUANTITY_MAX_LENGTH = 4;
	static const int MONTH_MAX_LENGTH =3;

};

