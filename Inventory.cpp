// file Inventory.cpp
// Member function definitions for class Inventory

#include "Inventory.h"

// ---------------------------------------------------------------------------
// Constructor 
// Default constructor for class Inventory 
Inventory::Inventory()
{
	initStorage();
	storage[hash('C')] =new BinTree;
	storage[hash('D')] =new BinTree;
	storage[hash('F')] = new BinTree;
}

// ---------------------------------------------------------------------------
// addItem() 
// Takes the Item and addes to the hash table using the movieCode as a key to 
// hash function approiatly
bool Inventory::addItem(Item *item, char movieCode)
{
	BinTree *storageTree = storage[hash(movieCode)]; 
	storageTree->insert(item); 

	return true; 
}

// ---------------------------------------------------------------------------
// hash() 
// Hash the charachter passed to return back the approiate key
int Inventory::hash(char character) const
{
	return character - 'A';
}

// ---------------------------------------------------------------------------
// initStorage() 
// Initializes the hash table to point to all NULLs
void Inventory::initStorage()
{
	for (int i = 0; i < MAX_ITEMTYPE; i++)
	{
		storage[i] = NULL;
		//delete storage[i]; 
	}
}

// ---------------------------------------------------------------------------
// displayCatagories 
// Displays each of BinTree's data stored in the Hashtable 
void Inventory::displayCatagories() const
{
	for (int i = 0; i < MAX_ITEMTYPE; i++)
	{
		if (storage[i] != NULL)
		{
			cout << *storage[i]; 
		}
	}
}

// ---------------------------------------------------------------------------
// retrieveItem 
// Takes the Item and compares it's value in the correct BinTree found after 
// using itemCode to hash to correct key
Item* Inventory::retrieveItem(const Item *obj, char itemCode) const
{
	BinTree *storageTree = storage[hash(itemCode)];
	Item *retrieved = NULL;
	storageTree->retrieve(obj, retrieved);

	return retrieved; 
}

// ---------------------------------------------------------------------------
// Deconstructor
// Deconstructor constructor for class Inventory
Inventory::~Inventory()
{
	for (int i = 0; i < MAX_ITEMTYPE; i++)
	{
		if (storage[i] != NULL)
		{
			delete storage[i];
			storage[i] = NULL;
		}		
	}
}