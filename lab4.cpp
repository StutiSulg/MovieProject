#include <iostream>
#include <string>
#include <fstream>
#include "Manager.h"
using namespace std;

int main() {
	
	ifstream infile1("data4movies.txt"); 
	ifstream infile2("data4customers.txt"); 
	ifstream infile3("data4commands.txt");
	if (!infile1 || !infile2 || !infile3)
	{
		cerr << "File could not be opened." << endl; 
		return 1; 
	}
	
	Manager movie;
	movie.initializeStore(infile1); 
	movie.initializeCustomers(infile2); 
	movie.runCommands(infile3); 
	return 0;
}

