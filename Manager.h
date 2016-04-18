//---------------------------------------------------------------------------
// MANAGER.H
// The main class that handles all the customers and items of MOVIE
//---------------------------------------------------------------------------
// Manager class:  
//   -- allows input of items 
//   -- allows input of customers
//   -- allows text of commands to run on items and customer
//   -- displays what content is in the store
//
// Implementation and assumptions:
//   -- Input text files are formated correctly 
//   -- There is no space after the end of the text files
//---------------------------------------------------------------------------
#pragma once
#include "Inventory.h"
#include "Factory.h"
#include "CustDatabase.h"
#include "Customer.h"
#include <queue>
#include <istream>
#include <fstream>
#include <iostream>
using namespace std;

class Manager
{
public:
	// constructors 
	Manager();
	~Manager();

	//initializes inventory of items
	void initializeStore(istream &); 
	//intitializes amount of customers
	void initializeCustomers(istream &); 
	//runs the needed commands
	void runCommands(istream &); 

	//dispay content of business
	void display() const; 
	
private:
	//contains all the items in the store
	Inventory storeInventory;
	
	//database of customers
	CustDatabase customers; 
	
	//factory for movies and transactions
	Factory factory; 
	
	// error function
	void error(string) const; 

};

