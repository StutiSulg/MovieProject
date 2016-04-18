//---------------------------------------------------------------------------
// FACTORY.H
// Produces the correct objects for the Manger Class using two hash tables
//---------------------------------------------------------------------------
// Factory class has the ability   
//   -- to create specific item objects (ClassicMovie, ComedyMovie ...)
//   -- to create specific transaction objects (Borrow, History, Return)
//
// Implementation and assumptions:
//   -- Only sing char charcters are passed
//---------------------------------------------------------------------------
#pragma once
#include "Item.h"
#include "Media.h"
#include "ClassicMovie.h"
#include "ComedyMovie.h"
#include "DramaMovies.h"
#include "Transaction.h"
#include "Borrow.h"
#include "Return.h"
#include "History.h"

// Max amount of items and transactions objects
static const int MAX_ITEMS = 26; 

class Factory
{
public:
	// constructor 
	Factory();
	~Factory();

	// creates the appropriate item 
	Item* createItem(char character); 
	// create the appropriate transaction item
	Transaction* createTran(char character); 
	
private:
	// factory of items
	Item *itemFactory[MAX_ITEMS]; 
	// transaction factory
	Transaction *tranFactory[MAX_ITEMS]; 
	// hashs to correct item 
	int hash(char character);
	// initalizes the factories
	void initializeFact(); 
	
};

