//---------------------------------------------------------------------------
// Person.H
// The Parent class of all different type of people
//---------------------------------------------------------------------------
// Person Class: 
//   -- get person's full name
//   -- set person's name
//---------------------------------------------------------------------------
#pragma once
#include <string>
using namespace std;
class Person
{
public:
	// constructors
	Person();
	Person(const string); 
	~Person();

	// returns person's first name
	string getName() const; 
	// returns person's last name
	void setName(string name); 

protected:
	// full (first last name)
	string name; 
};

