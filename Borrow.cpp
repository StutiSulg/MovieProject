// file Borrow.cpp
// Member function definitions for class Borrow
#include "Borrow.h"

// ---------------------------------------------------------------------------
// Constructor 
// Default constructor for class Borrow
Borrow::Borrow()
{
	customer = NULL; 
	item = NULL; 
	neededFormat = ' '; 
}

// ---------------------------------------------------------------------------
// create 
// Creates a new borrow object and returns it to the factory
Transaction* Borrow::create()
{
	return new Borrow(); 
}

// ---------------------------------------------------------------------------
// setData 
// sets variables to the approiate objects such as customers,
// item borrowed, and format of the item borrowed
bool Borrow:: setData(Customer *cust, Item *object, char format)
{
	if (object == NULL)
	{
		return false; 
	}
	neededFormat = format; 
	item = object; 

	customer = cust; 

	return true; 
}

// ---------------------------------------------------------------------------
// executeTran 
// Executes the transaction changing approiate information of the customer
bool Borrow::executeTran()
{
	Format *recievedFormat = item->getFormat();
	
	if (recievedFormat->getType()[0] == neededFormat)
	{
		if (recievedFormat->getCurrStock() > 0)
		{
			customer->borrowItem(item); 
			recievedFormat->remove();
			customer->addTran(this);
			recievedFormat = NULL;
			return true;
			
		}
	}
	
	recievedFormat = NULL; 
	return false; 
}

// ---------------------------------------------------------------------------
// display 
// displays approriate information about transaction 
void Borrow::display() const
{
	cout << item->getFormat()->getType() << " " << "Borrow  "; 
	item->displayTranInfo(); 
	cout << endl; 
}

// ---------------------------------------------------------------------------
// Deconstructor 
// Deconstructor for borrow object
Borrow::~Borrow()
{
}
