// file Manager.cpp
// Member function definitions for class Manager

#include "Manager.h"

// -------------------------------------------------------------------------- -
// Constructor 
Manager::Manager()
{
}

// ---------------------------------------------------------------------------
// initializeStore()
// Function that takes in txt information and initializes the storeInventory
// with appropriate items
void Manager::initializeStore(istream &store)
{
	// until the txt file is empty keep reading the file
	while (!store.eof())
	{
		// read first character from file
		char movieCode; 
		store >> movieCode; 

		if (store.eof()) return; 

		// create appropriate class
		Item *newItem = factory.createItem(movieCode);
		if (newItem != NULL)
		{
			newItem->initialize(store); 
			storeInventory.addItem(newItem, movieCode); 
		}
		else
		{
			string temp; 
			getline(store, temp, '\n'); 
		}

		newItem = NULL; 
		delete newItem; 
	}
}

// ---------------------------------------------------------------------------
// initializeCustomer() 
// Function that takes in txt file that includes customers names and 
// initializes them correctly in the customer database
void Manager::initializeCustomers(istream &infile)
{
	Customer *ptrCust; 

	// until the file is empty keep reading the file
	while (!infile.eof())
	{
		
		ptrCust = new Customer(infile); 
		if (infile.eof())
		{
			delete ptrCust; 
			ptrCust = NULL; 
			return; 
		}
		customers.add(ptrCust); 
		ptrCust = NULL; 
	}

	ptrCust = NULL; 
	delete ptrCust; 
}

// ---------------------------------------------------------------------------
// runCommands() 
// Reads the commands text file and places and executes the correct 
// transactions
void Manager::runCommands(istream &infile)
{
	Transaction *ptrTran = NULL; 
	Customer *ptrCust = NULL; 
	Item *ptrItem = NULL; 
	char tranCode = ' ';
	char movieCode = ' '; 
	char format = ' '; 
	char endOfLine = '\n'; 
	char historyMovieCode = 'H'; 
	int id = 0;
	string del = " "; 
	

	// Read until there are no more commands to read
	while (!infile.eof())
	{
		// Grad transaction code and build correct transaction
		infile >> tranCode; 
		if (infile.eof()) return;
		ptrTran = factory.createTran(tranCode); 

		// If could not build transaction code either an error
		// or show all of movie items was called
		if (ptrTran == NULL)
		{
			if (tranCode == 'S')
				display();				
			else
			{
				getline(infile, del, '\n'); 
				error("Invalid Transaction Code"); 
			}				
		}
		else
		{
			// Get customer class
			infile.get();
			infile >> id;
			ptrCust = customers.get(id);
			
			// If no customer class display error
			if (ptrCust == NULL)
			{
				delete ptrTran; 
				getline(infile, del, '\n');
				error("Invalid Customer ID ");
			}
			else if (tranCode == historyMovieCode)
			{
				ptrTran->setData(ptrCust, ptrItem, format);
				ptrTran->executeTran();
			}
			else
			{	
				// Get the movie format desired
				infile.get(); 
				infile >> format; 

				// Get the movie genera code
				infile.get(); 
				infile >> movieCode; 
				ptrItem = factory.createItem(movieCode);

				if (ptrItem != NULL)
				{
					// initialize the empty movie class
					ptrItem->initCompObj(infile); 

					// see if this movie exisits in our data base
					Item *retrievedItem = 
						storeInventory.retrieveItem(ptrItem, movieCode); 					
					delete ptrItem; 
					ptrItem = retrievedItem; 
					retrievedItem = NULL; 
					
					//check if correct format of movie was found
					bool noErrors = true; 
					noErrors = ptrTran->setData(ptrCust, ptrItem, format);

					if (!noErrors)
					{
						delete ptrTran; 
						error("Invalid Item Call ");
						getline(infile, del, '\n'); 
					}
					else
					{
						// execute the transaction 
						noErrors = ptrTran->executeTran();
						if (!noErrors)
						{
							delete ptrTran;
							error("Unable to return/borrow a certian format");
						}			
						
					}
						
				}
				else
				{
					delete ptrItem; 
					delete ptrTran; 
					string del;
					getline(infile, del, '\n');
					error("Invalid Movie Code");
				}
			}
		}

		ptrTran = NULL;
		ptrCust = NULL;
		ptrItem = NULL;
		tranCode = ' ';
		movieCode = ' ';
		format = ' ';
		id = 0;
	}
}

// ---------------------------------------------------------------------------
// error() 
// Display the error function once an error occurs
void Manager::error(string errorCode) const
{
	cout << "Error : " << errorCode<< endl; 
}

void Manager::display() const
{
 	storeInventory.displayCatagories(); 
}

// ---------------------------------------------------------------------------
// Destructor 
// Destructor for class Manager
Manager::~Manager()
{
}
