// file History.cpp
// Member function definitions for class History
#include "History.h"

// ---------------------------------------------------------------------------
// Constructor 
// Default constructor for class History
History::History()
{
	customer = NULL; 
}

// ---------------------------------------------------------------------------
// create 
// Creates a new history object and returns it to the factory
Transaction* History::create()
{
	return new History();
}

// ---------------------------------------------------------------------------
// setData 
// sets variables to the approiate objects 
bool History::setData(Customer *cust, Item *object, char format)
{
	customer = cust;
	customer->addTran(this); 
	return true; 
}


// ---------------------------------------------------------------------------
// executeTran 
// Executes the transaction displaying approiate information of the customer
bool History::executeTran()
{
	customer->displayTranHistory();
	return true;
}

// ---------------------------------------------------------------------------
// display 
// displays approriate infomration about transaction 
void History::display() const
{
	return; 
}

// ---------------------------------------------------------------------------
// Deconstructor 
// Deconstructor for history object
History::~History()
{
}
