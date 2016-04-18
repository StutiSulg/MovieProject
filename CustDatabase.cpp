// file CustDatabase.cpp
// Member function definitions for class CustDatabase
#include "CustDatabase.h"

// ---------------------------------------------------------------------------
// Constructor 
// Default constructor for class CustDatabase
CustDatabase::CustDatabase()
{
	for (int i = 0; i < MAX_CUST; i++)
	{
		database[i] = NULL; 
	}
}

// ---------------------------------------------------------------------------
// add() 
// Adds the new customer to the Hash Table using the Customer's id key
bool CustDatabase::add(Customer *newCustomer)
{
	int idHash = newCustomer->getId(); 
	if (database[idHash] == NULL)
	{
		database[idHash] = newCustomer; 
		return true; 
	}

	return false; 
}

// ---------------------------------------------------------------------------
// get() 
// Returns a pointer to the customer that is stored inside of the Hash table
Customer* CustDatabase::get(const int id)
{
	return database[id]; 
}

// ---------------------------------------------------------------------------
// Deconstructor 
// Default constructor for class CustDatabase
CustDatabase::~CustDatabase()
{
	for (int i = 0; i < MAX_CUST; i++)
	{
		if (database[i] != NULL)
		{
			delete database[i];
			database[i] = NULL;
		}	 
	}
}
