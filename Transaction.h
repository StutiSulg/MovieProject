//---------------------------------------------------------------------------
// TRANSACTION.H
// The parent class that represents a generic transaction
//---------------------------------------------------------------------------
// Transaction Class: 
//   -- pure virtual function of executing transaction
//   -- pure virtual function of setting data for a generic transaction obj.
//   -- pure virtual function of creating an empty transaction obj
//   -- pure virtual function of displaying transaction information 
//
// Implementation and assumptions:
//   -- This class will never be created by it self. 
//   -- This is only a parent object not a object that will be initialized. 
//---------------------------------------------------------------------------
#pragma once
#include "Item.h"
#include "Customer.h"

class Transaction
{
	
public:
	// constructor
	Transaction();
	~Transaction();
	// execute transaction 
	virtual bool executeTran() = 0;  
	//set Transaction items
	virtual bool setData(Customer *, Item *, char format) = 0; 
	//creates a new object
	virtual Transaction* create() = 0; 
	// get's transaction information 
	virtual void display() const = 0; 
};

