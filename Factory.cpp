// file Factory.cpp
// Member function definitions for class Factory
#include "Factory.h"

// ---------------------------------------------------------------------------
// Constructor 
// Default constructor for class Factory that initailizes both hash tables
// with correct items/transactions.
Factory::Factory()
{
	initializeFact(); 
	itemFactory[hash('C')] = new ClassicMovie; 
	itemFactory[hash('D')] = new DramaMovies;
	itemFactory[hash('F')] = new ComedyMovie;
	
	tranFactory[hash('H')] = new History;  
	tranFactory[hash('B')] = new Borrow; 
	tranFactory[hash('R')] = new Return; 

}

// ---------------------------------------------------------------------------
// Deconstructor 
// Deconstructor for Factory
Factory::~Factory()
{
	for (int i = 0; i < MAX_ITEMS; i++)
	{
		if (itemFactory[i] != NULL)
		{
			delete itemFactory[i]; 
		}
		if (tranFactory[i] != NULL)
		{
			delete tranFactory[i]; 
		}
		itemFactory[i] = NULL;
		tranFactory[i] = NULL; 
	}
}

// ---------------------------------------------------------------------------
// createItem 
// Taking in the character the correct Item object is created and returned
Item* Factory::createItem(char character)
{
	int subscript = hash(character); 
	if (itemFactory[subscript] == NULL)
	{
		return NULL;
	}
	return itemFactory[subscript]->create(); 
}

// ---------------------------------------------------------------------------
// createTran 
// Taking in the character the correct Transaction object is created 
// and returned
Transaction* Factory::createTran(char character)
{
	int subscript = hash(character);
	if (tranFactory[subscript] == NULL)
	{
		return NULL; 
	}
	return tranFactory[subscript]->create();
}

// ---------------------------------------------------------------------------
// hash 
// The character passed is hashed into the correct key 
int Factory::hash(char character)
{
	return character - 'A'; 
}

// ---------------------------------------------------------------------------
// initializeFact 
// Initialize both hash tables to NULL
void Factory::initializeFact()
{
	for (int i = 0; i < MAX_ITEMS; i++)
	{
		itemFactory[i] = NULL; 
		tranFactory[i] = NULL; 
	}
}
