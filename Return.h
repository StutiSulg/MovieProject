//---------------------------------------------------------------------------
// Return.H
// Child class of transaction that represents the transaction of returning
// Items borrowed by customers 
//---------------------------------------------------------------------------
// Borrow Class: 
//   -- function of executing transaction
//   -- function of setting data for a borrow transaction obj.
//   -- function of creating an empty borrow obj
//   -- function of displaying borrowing transaction information 
//
// Implementation and assumptions:
//   -- Items stored in setData will be a fully initialized item 
//---------------------------------------------------------------------------
#pragma once
#include "Transaction.h"

class Return : public Transaction
{
public:
	// Constructor
	Return();
	~Return();

	// execute transaction 
	virtual bool executeTran();
	//set Transaction items
	virtual bool setData(Customer *, Item *, char format);
	//creates a new object
	virtual Transaction* create();
	// displays transaction information
	virtual void display() const;
private:
	// pointer to customer 
	Customer *customer;
	// pointer to item that is being returned
	Item *item;
	// char of the format returned
	char neededFormat;
};

