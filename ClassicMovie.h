//---------------------------------------------------------------------------
// CLASSICMOVIE.H
// The child class of Media that represents a classical movie
//---------------------------------------------------------------------------
// ClassicMovie Class: 
//   -- allows comparing of items together
//   -- allows displaying of information about item
//   -- allows initializing of items to contain correct info
//
// Implementation and assumptions:
//   -- Correct format of information is passed to the class
//   -- This is only a parent object not a object that will be initialized. 
//---------------------------------------------------------------------------
#pragma once
#include "Media.h" 
#include "Person.h"

class ClassicMovie : public Media
{
public:
	//constructors
	ClassicMovie();
	~ClassicMovie();

	// compares to see if items are equal
	virtual bool operator==(const Item &) const;
	// compares to see if item is less then other item
	virtual bool operator<(const Item &) const;

	//initializes infomration about media 
	virtual void initialize(istream &infile);
	//initializes information so items can be compared
	virtual void initCompObj(istream &infile);

	// creates an empty object
	virtual Item* create() const;

	//display information
	virtual void displayInfo() const;
	//display header for particular item
	virtual void displayHeader() const; 
	//display Transaction information about item
	virtual void displayTranInfo() const; 
private:
	//actor assoicated with this movie
	Person actor; 
	// month to the movie release
	int month; 
	// genera of the movie
	const string GENRA = "CLASSIC"; 
	 
};

