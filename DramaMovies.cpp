// file DramaMovies.cpp
// Member function definitions for class DramaMovies
#include "DramaMovies.h"
#include <iomanip>

// ---------------------------------------------------------------------------
// Constructor 
// Default constructor for class ComedyMovie 
DramaMovies::DramaMovies()
{
	title = " ";
	year = 0;
	type = NULL;
}

// ---------------------------------------------------------------------------
// initialize
// Breaks down the infile and assigns the correct variables
void DramaMovies::initialize(istream &infile)
{
	Media::initialize(infile);

	infile.get();
	infile >> year;

	type = new Dvd;
} 

// ---------------------------------------------------------------------------
// initCompObj
// Breaks down the infile and assigns the correct variables to have this item
// ready to compare to another item
void DramaMovies::initCompObj(istream &infile)
{
	
	infile.get();
	string fileDirector = " ";
	getline(infile, fileDirector, ',');
	director.setName(fileDirector); 

	infile.get();
	getline(infile, title, ','); 

}

// ---------------------------------------------------------------------------
// operator== 
// Compares if this item is equal to the other item
bool DramaMovies::operator==(const Item &secItem) const
{
	const DramaMovies &secClass = static_cast<const DramaMovies&>(secItem);
	
	return (director.getName() == secClass.director.getName()
		&& title == secClass.title);

}

// ---------------------------------------------------------------------------
// operator< 
// Compares if this item is less than the other item
bool DramaMovies::operator<(const Item &secItem) const
{
	const DramaMovies &secClass = static_cast<const DramaMovies&>(secItem);
	if (director.getName() < secClass.director.getName())
	{
		return true; 
	}
	else if (title < secClass.title && 
		    director.getName() == secClass.director.getName())
	{
		return true; 
	}
	return false;
}

// ---------------------------------------------------------------------------
// create 
// creates a blank ClassicMovie object
Item* DramaMovies::create() const
{
	return new DramaMovies;
}

// ---------------------------------------------------------------------------
// displayInfo 
// Displays information about item in the correct formate 
void DramaMovies::displayInfo() const
{
	cout.setf(ios::left, ios::adjustfield);

	cout << left << setw(QUANTITY_MAX_LENGTH + 1) << type->getCurrStock();
	cout << left << setw(QUANTITY_MAX_LENGTH) 
		 << (type->getQuantity() - type->getCurrStock());

	cout << setw(TITLE_MAX_LENGTH) << title.substr(0, TITLE_MAX_LENGTH - 1);
	cout << left << setw(DIRECTOR_MAX_LENGTH) 
		 << director.getName().substr(0, DIRECTOR_MAX_LENGTH - 1);
	cout << year << "   ";
}

// ---------------------------------------------------------------------------
// displayTranInfo 
// Displays information about item in the correct formate for transaction info
void DramaMovies::displayTranInfo() const
{
	cout.setf(ios::left, ios::adjustfield);

	cout << setw(TITLE_MAX_LENGTH) << title.substr(0, TITLE_MAX_LENGTH - 1);
	cout << left << setw(DIRECTOR_MAX_LENGTH) 
		 << director.getName().substr(0, DIRECTOR_MAX_LENGTH - 1);
	cout << year << "   ";
}

// ---------------------------------------------------------------------------
// displayHeader 
// Displays the header information for this particular class
void DramaMovies::displayHeader() const
{
	cout.setf(ios::left, ios::adjustfield);

	cout << GENRA << endl;
	cout << "IN | OUT" << endl;

	cout << left << setw(QUANTITY_MAX_LENGTH + 1) << "DVD";
	cout << left << setw(QUANTITY_MAX_LENGTH) << "DVD";

	cout << setw(TITLE_MAX_LENGTH) << "TITLE";
	cout << left << setw(DIRECTOR_MAX_LENGTH) << "DIRECTOR";
	cout << "YEAR" << " ";
}

// ---------------------------------------------------------------------------
// Deconstructor 
// Deconstructor for DramaMovies
DramaMovies::~DramaMovies()
{
	delete type;
	type = NULL;
}
