// file Format.cpp
// Memebr function definition for class Format
#include "Format.h"

// ---------------------------------------------------------------------------
// Constructor 
// Default constructor for class Fomate
Format::Format() 
{
	type = " "; 
	inStock = 0; 
	totalCopies = 0; 
}

// ---------------------------------------------------------------------------
// Add 
// Adds more copies of a certain format to the stor collection
bool Format::add()
{
	inStock++; 
	return true; 
}

// ---------------------------------------------------------------------------
// Remove 
// Removes one copy of a certain format from the store collection
bool Format::remove()
{
	if (inStock != 0)
	{
		inStock--;
		return true; 
	}
	return false; 
}

// ---------------------------------------------------------------------------
// getCurrStock 
// Returns the current amount of a particular format is left in stock 
int Format::getCurrStock() const
{
	return inStock; 
}

// ---------------------------------------------------------------------------
// getQuantity 
// Retuns the total amount of copies of a particular fomat the store owns
int Format::getQuantity() const
{
	return totalCopies; 
}

// ---------------------------------------------------------------------------
// getType() 
// Retuns the type of format a particular movie is
string Format::getType() const
{
	return type; 
}

// ---------------------------------------------------------------------------
// Deconstructor 
// Deconstructs everything
Format::~Format()
{
}
