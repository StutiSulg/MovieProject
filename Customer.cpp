// file Customer.cpp
// Member function definitions for class Customer
#include "Customer.h"
#include "Transaction.h"

// ---------------------------------------------------------------------------
// Constructor 
// Default constructor for class Customer 
Customer::Customer()
{
}

// ---------------------------------------------------------------------------
// Customer(istream &infile) 
// infile can just be passed to customer to create a customer object
Customer::Customer(istream &infile)
{
	infile >> id; 
	infile.get(); 
	getline(infile, name, '\n');  
}

// ---------------------------------------------------------------------------
// displayTranHistory 
// Displays the transaction history of the customer
void Customer::displayTranHistory() const
{
	cout << "  *** "; 
	cout << "Customer ID = " << id; 
	cout << "  " << name << endl; 
	int size = tranHistory.size(); 
	for (int i = 0; i < size; i++)
	{
		tranHistory[i]->display(); 
	}

	cout << endl; 
}

// ---------------------------------------------------------------------------
// getIde 
// gets customer's id
int Customer::getId() const
{
	return id; 
}

// ---------------------------------------------------------------------------
// addTran 
// adds transactions called to tranhistory
bool Customer::addTran(Transaction *tran)
{
	tranHistory.push_back(tran); 
	return true; 
}

// ---------------------------------------------------------------------------
// borrowItem 
// adds item to customers collection of items
void Customer::borrowItem(Item *object)
{
	myInventory.insert(object); 
}

// ---------------------------------------------------------------------------
// returnItem 
// returns item to from customers collection of items
bool Customer::returnItem(Item *object)
{
	return myInventory.remove(object); 
	
}

// ---------------------------------------------------------------------------
// Deconstructor 
// Deconstructor for customer class
Customer::~Customer()
{
	int size = tranHistory.size();
	for (int i = 0; i < size; i++)
	{
		delete tranHistory[i];
		tranHistory[i] = NULL; 
	}
}
