// file ClassicMovie.cpp
// Member function definitions for class ClassicMovie
#include "ClassicMovie.h"
#include <iomanip>

// ---------------------------------------------------------------------------
// Constructor 
// Default constructor for class ClassicMovie 
ClassicMovie::ClassicMovie()
{
	month = 0; 
	title = " ";
	year = 0;
	type = NULL;
	actor.setName(" "); 
}

// ---------------------------------------------------------------------------
// initialize
// Breaks down the infile and assigns the correct variables
void ClassicMovie::initialize(istream &infile)
{
	Media::initialize(infile); 

	infile.get(); 
	string actorfirst;
	string actorlast; 
	infile >> actorfirst >> actorlast;

	actor.setName(actorfirst + " " + actorlast); 
	
	infile.get(); 
	infile >> month; 

	infile.get();
	infile >> year;

	type = new Dvd; 
}

// ---------------------------------------------------------------------------
// initCompObj
// Breaks down the infile and assigns the correct variables to have this item
// ready to compare to another item
void ClassicMovie::initCompObj(istream &infile)
{
	infile.get(); 
	infile >> month;

	infile.get();
	infile >> year; 

	infile.get();
	string actorfirst;
	string actorlast;
	infile >> actorfirst >> actorlast;

	actor.setName(actorfirst + " " + actorlast);
}

// ---------------------------------------------------------------------------
// operator== 
// Compares if this item is equal to the other item
bool ClassicMovie::operator==(const Item &secItem) const
{
	const ClassicMovie &secClass = static_cast<const ClassicMovie&>(secItem); 

	return (year == secClass.year && month == secClass.month 
		&& actor.getName() == secClass.actor.getName());
}

// ---------------------------------------------------------------------------
// operator< 
// Compares if this item is less than the other item
bool ClassicMovie::operator<(const Item &secItem) const
{
	const ClassicMovie &secClass = static_cast<const ClassicMovie&>(secItem);
	if (year < secClass.year)
	{
		return true; 		
	}
	else if (year == secClass.year && month < secClass.month )
	{
		return true; 
	}
	else if (actor.getName() < secClass.actor.getName() && 
		(year == secClass.year && month == secClass.month))
	{
		return true; 
	}

	return false;
}

// ---------------------------------------------------------------------------
// create 
// creates a blank ClassicMovie object
Item* ClassicMovie::create() const
{
	return new ClassicMovie; 
}

// ---------------------------------------------------------------------------
// displayInfo 
// Displays information about item in the correct formate 
void ClassicMovie::displayInfo() const
{
	cout.setf(ios::left, ios::adjustfield);

	cout << left << setw(QUANTITY_MAX_LENGTH + 1) << type->getCurrStock();
	cout << left << setw(QUANTITY_MAX_LENGTH) 
		<< (type->getQuantity() - type->getCurrStock()) ;

	cout << setw(TITLE_MAX_LENGTH) << title.substr(0, TITLE_MAX_LENGTH - 1); 
	cout << left << setw(DIRECTOR_MAX_LENGTH)
		<< director.getName().substr(0, DIRECTOR_MAX_LENGTH - 1); 
	cout << year << "   "; 
	cout << left <<  setw(MONTH_MAX_LENGTH) << month; 
	cout << actor.getName(); 
}

// ---------------------------------------------------------------------------
// displayTranInfo 
// Displays information about item in the correct formate for transaction info
void ClassicMovie::displayTranInfo() const
{
	cout.setf(ios::left, ios::adjustfield);

	cout << setw(TITLE_MAX_LENGTH) << title.substr(0, TITLE_MAX_LENGTH - 1);
	cout << left << setw(DIRECTOR_MAX_LENGTH) 
		<< director.getName().substr(0, DIRECTOR_MAX_LENGTH - 1);
	cout << year << "   ";
	cout << left << setw(MONTH_MAX_LENGTH) << month;
	cout << actor.getName();
}

// ---------------------------------------------------------------------------
// displayHeader 
// Displays the header information for this particular class
void ClassicMovie::displayHeader() const
{
	cout.setf(ios::left, ios::adjustfield);

	cout << GENRA << endl; 
	cout << "IN | OUT" << endl; 

	cout << left << setw(QUANTITY_MAX_LENGTH + 1) << "DVD";
	cout << left << setw(QUANTITY_MAX_LENGTH) << "DVD"; 

	cout << setw(TITLE_MAX_LENGTH) << "TITLE";
	cout << left << setw(DIRECTOR_MAX_LENGTH) << "DIRECTOR";
	cout << "YEAR" << "   ";
	cout << left << setw(MONTH_MAX_LENGTH) << "MO";
	cout << "ACTOR";
}

// ---------------------------------------------------------------------------
// Deconstructor 
// Deconstructor for ClassicMovie
ClassicMovie::~ClassicMovie()
{
	delete type; 
	type = NULL; 	
}
