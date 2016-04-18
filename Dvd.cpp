// file Dvd.cpp
// Member function definitions for class Dvd
#include "Dvd.h"

// ---------------------------------------------------------------------------
// Constructor 
// Default constructor for class Dvd 
Dvd::Dvd()
{
	type = "Dvd"; 
	inStock = MAX_COPIES; 
	totalCopies = MAX_COPIES; 
}

// ---------------------------------------------------------------------------
// Deconstructor 
// Deconstructor for Dvd
Dvd::~Dvd()
{
}
