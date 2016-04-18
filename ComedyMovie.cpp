// file ComedyMovie.cpp
// Member function definitions for class ComedyMovie
#include "ComedyMovie.h"
#include <iomanip>

// ---------------------------------------------------------------------------
// Constructor 
// Default constructor for class ComedyMovie 
ComedyMovie::ComedyMovie()
{
	title = " ";
	year = 0;
	type = NULL;
}

// ---------------------------------------------------------------------------
// initialize
// Breaks down the infile and assigns the correct variables
void ComedyMovie::initialize(istream &infile)
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
void ComedyMovie::initCompObj(istream &infile)
{
	infile.get();
	getline(infile, title, ',');

	infile.get();
	infile >> year;
}

// ---------------------------------------------------------------------------
// operator== 
// Compares if this item is equal to the other item
bool ComedyMovie::operator==(const Item &secItem) const
{
	const ComedyMovie &secClass = static_cast<const ComedyMovie&>(secItem);
 
	return (year == secClass.year && title == secClass.title);
}

// ---------------------------------------------------------------------------
// operator< 
// Compares if this item is less than the other item
bool ComedyMovie::operator<(const Item &secItem) const
{
	const ComedyMovie &secClass = static_cast<const ComedyMovie&>(secItem);
	if (title < secClass.title)
	{
		return true; 
	}
	else if (year < secClass.year && title == secClass.title)
	{
		return true; 
	}
	return false;
}

// ---------------------------------------------------------------------------
// create 
// creates a blank ClassicMovie object
Item* ComedyMovie::create() const
{
	return new ComedyMovie;
}

// ---------------------------------------------------------------------------
// displayInfo 
// Displays information about item in the correct formate 
void ComedyMovie::displayInfo() const
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
void ComedyMovie::displayTranInfo() const
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
void ComedyMovie::displayHeader() const
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
// Deconstructor for ComedyMovie
ComedyMovie::~ComedyMovie()
{
	delete type;
	type = NULL;
}
