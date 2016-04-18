//---------------------------------------------------------------------------
// DRAMAMOVIES.H
// The child class of Media that represents a drama movie
//---------------------------------------------------------------------------
// DramaMovies Class: 
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

class DramaMovies : public Media
{
public:
	//constructors
	DramaMovies();
	~DramaMovies();

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
	//type of movie genera
	const string GENRA = "DRAMA";
};

