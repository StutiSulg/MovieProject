//---------------------------------------------------------------------------
// INVENTORY.H
// A class that contains a hash table that contains the Binary Trees with 
// Items. The stores inventory class. 
//---------------------------------------------------------------------------
// Inventory Class: 
//   -- allows addition of items to it's hash table
//   -- allows retrievial of items from hash table
//   -- allows display of all items in stored in the hash table
//
// Implementation and assumptions:
//   -- Items stored are fully labled
//   -- Item code that represents the genera of the item is valid
//---------------------------------------------------------------------------
#pragma once
#include "Item.h"
#include "BinTree.h"
#include <iostream>
using namespace std; 

//THIS IS A HASH
//The max amout of types of item catagories (generas) you can have
static const int MAX_ITEMTYPE = 26; 
class Inventory
{
public:
	
	//constructors
	Inventory();
	~Inventory();
	
	// adds item to the appropriate tree
	bool addItem(Item *item, char itemCode); 
	// retrieves correct movie item
	Item* retrieveItem(const Item *, char itemCode) const; 
	// display's movie content by catagory
	void displayCatagories() const; 

private:
	// THIS IS A HASH
	BinTree *storage[MAX_ITEMTYPE]; 
	// hashs the appropriate key to the value requested
	int hash(char movieCode) const; 
	// initializes the hash table 
	void initStorage(); 
	 
	
};

