// file Dvd.h
// Dvd is the child class of Format that represents a Dvd
#pragma once
#include "Format.h"

//---------------------------------------------------------------------------
// Dvd class: is a child class of format that represent the a Dvd
//   -- allows to get the number of copies avaliable in that formate
//   -- allows you to add/remove a copy 
//   -- allows you to get the total amout of this particular format
//   -- has a max of 10 copies of this formate
// Assumption & Implementation: 
//   -- you can change the number of max copies you want here
//---------------------------------------------------------------------------

class Dvd : public Format
{
	//Max number of copies a store can own
	const int MAX_COPIES = 10; 
public:
	//constructors
	Dvd();
	~Dvd();
};

