//---------------------------------------------------------------------------
// CUSTDATABASE.H
// Contains all the customers that Manager class owns
//---------------------------------------------------------------------------
// CustDatabase class:  
//   -- allows addition of customers 
//   -- allows retreival of customers
//
// Implementation and assumptions:
//   -- Customer object must be implemented correctly with the correct data
//---------------------------------------------------------------------------
#pragma once
#include "Customer.h"

// MAX size of the hash table
static const int MAX_CUST = 10000; 

class CustDatabase
{
public:
	// constructors
	CustDatabase();
	~CustDatabase();

	// add people to the database
	bool add(Customer *); 
	// retrive a customer
	Customer* get(const int); 

private:
	// HASH TABLE of all customers
	// Note: the key is customer's id
	Customer *database[MAX_CUST];  
	 
};

