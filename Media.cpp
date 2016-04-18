// file Media.cpp
// Member function definitions for class Media
#include "Media.h"

// ---------------------------------------------------------------------------
// Constructor 
// Default constructor for class Media 
Media::Media()
{
	title = " "; 
	year = 0; 
	type = NULL;
}

// ---------------------------------------------------------------------------
// getTitle() 
// grabs the title of the movie
string Media::getTitle() const
{
	return title; 
}

// ---------------------------------------------------------------------------
// getFormat ()
// Grabs the format class of the media
Format* Media::getFormat() const
{
	 
	return type; 
}

// ---------------------------------------------------------------------------
// initialize 
// breaks down the infile and assigns the correct variables
void Media::initialize(istream &infile)
{
	infile.get(); 
	string fileDirector; 
	getline(infile, fileDirector, ','); 

	director.setName(fileDirector);

	infile.get(); 
	getline(infile, title, ','); 

}

// ---------------------------------------------------------------------------
// Deconstuctor 
// Deconstuctor for class Media 
Media::~Media()
{
}
