// file Return.cpp
// Member function definitions for class Return
#include "Return.h"

// ---------------------------------------------------------------------------
// Constructor 
// Default constructor for class Return
Return::Return()
{
	customer = NULL; 
	item = NULL;
	neededFormat = ' '; 
}

// ---------------------------------------------------------------------------
// create 
// Creates a new return object and returns it to the factory
Transaction* Return::create()
{
	return new Return();
}

// ---------------------------------------------------------------------------
// setData 
// sets variables to the approiate objects such as customers,
// item returned, and format of the item returend
bool Return::setData(Customer *cust, Item *object, char format)
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
bool Return::executeTran()
{
	Format *recievedFormat = item->getFormat();

	if (recievedFormat->getType()[0] == neededFormat)
	{
		if (recievedFormat->getCurrStock() != recievedFormat->getQuantity())
		{
			bool returnable = true; 
			returnable = customer->returnItem(item); 
			if (returnable)
			{
				recievedFormat->add();
				customer->addTran(this);
				recievedFormat = NULL;
				return true;
			}
			
		}
		
	}

	recievedFormat = NULL;
	return false;
}

// ---------------------------------------------------------------------------
// display 
// displays approriate information about transaction 
void Return::display() const
{
	cout.setf(ios::left, ios::adjustfield); 

	cout << item->getFormat()->getType() << " " << "Return  ";
	item->displayTranInfo();
	cout << endl;
}

// ---------------------------------------------------------------------------
// Deconstructor 
// Deconstructor for return object
Return::~Return()
{ 
}
