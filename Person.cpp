// file Person.cpp
// Member function definitions for class Person
#include "Person.h"

// ---------------------------------------------------------------------------
// Constructor 
// Default constructor for class Person 
Person::Person()
{
	name = " "; 
}

// ---------------------------------------------------------------------------
// Person(const string id) 
// Constructor that takes in a string that represents name of person
Person::Person(const string id)
{
	name = id;
}

// ---------------------------------------------------------------------------
// getName 
// gets persons name
string Person::getName() const
{
	return name; 
}

// ---------------------------------------------------------------------------
// setName 
// sets persons name
void Person::setName(string names)
{
	name = names; 
}

// ---------------------------------------------------------------------------
// Deconstructor 
// Deconstructor for Person Class
Person::~Person()
{
}