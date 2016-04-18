//---------------------------------------------------------------------------
// CUSTOMER.H
// A class that represents a customer who is a person with an idea and
// transaction history and owned items
//---------------------------------------------------------------------------
// Inventory Class: 
//   -- allows addition of items customers own
//   -- allows delete items customers own
//   -- allows display transaction history of customer
//   -- add transaction done by customers
//   -- display customers id
//
// Implementation and assumptions:
//   -- Items stored are fully labled
//   -- Trasaction objects are fully initialized
//---------------------------------------------------------------------------
#pragma once
#include "Person.h"
#include <vector>
#include "LinkedList.h"

class Transaction; 
class Customer : public Person 
{
public:
	// constructors
	Customer();
	Customer(istream &); 
	~Customer();

	// display transaction history
	void displayTranHistory() const; 
	// add transaction to history
	bool addTran(Transaction *); 

	// add certain item to customer
	void borrowItem(Item *); 

	// return item to customer; 
	bool returnItem(Item *); 

	// get customer's id
	int getId() const; 

private: 
	int id; 
	//history of transaction
	vector<Transaction *> tranHistory; 
	//each personal inventory of items the customer has
	LinkedList myInventory; 
};

