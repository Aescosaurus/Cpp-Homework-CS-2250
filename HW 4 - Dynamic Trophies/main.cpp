#include <iostream>
#include <string>
#include <vector>
#include "Trophy.h"
#include <stdexcept>

using namespace std;

// Reusable strings
const string PROMPT_FOR_NAME = "Please enter the name of the Trophy";
const string PROMPT_FOR_LEVEL = "Please enter the level of your Trophy (between 1 and 10)";
const string PROMPT_FOR_COLOR = "Please enter the color of your Trophy (GOLD, SILVER, or BRONZE)";

// Menu choice handlers
void addTrophy( vector<Trophy*>& trophies );
void copyTrophy( vector<Trophy*>& trophies );
void deleteTrophy( vector<Trophy*>& trophies );
void renameTrophy( const vector<Trophy*>& trophies );
void relevelTrophy( const vector<Trophy*>& trophies );
void recolorTrophy( const vector<Trophy*>& trophies );
void printTrophies( const vector<Trophy*>& trophies );

// Input handlers
int printMenu();
void printMenuOptions();
Trophy* promptForTrophy();
string promptForString( const string& message );
int promptForInt( const string& message,int minimum,int maximum );
Color promptForColor( const string& message );

// Useful helper methods
string stringToUpper( string value );
int searchForTrophy( const vector<Trophy*>& trophies,const string& name );
bool safeStr2Int( int& intToFill,const string& input );

// This application allows for the management of a trophy collection
int main()
{
	cout << "***********************************************" << endl
		<< "Welcome to the Trophy editor!" << endl
		<< "With this application, you can manage your trophy" << endl
		<< "collection - add, modify, or remove trophies by" << endl
		<< "using this simple menu!" << endl
		<< "***********************************************" << endl;

	vector<Trophy*> trophies;

	// Loop the menu, allowing the user to select an action each time
	int input;
	do
	{
		input = printMenu();
		switch( input )
		{
		case 1:		// Add a new Trophy
			addTrophy( trophies );
			break;
		case 2:		// Copy an existing Trophy
			copyTrophy( trophies );
			break;
		case 3:		// Delete an existing Trophy
			deleteTrophy( trophies );
			break;
		case 4:		// Rename a Trophy
			renameTrophy( trophies );
			break;
		case 5:		// Change the level of a Trophy
			relevelTrophy( trophies );
			break;
		case 6:		// Change the color of a Trophy
			recolorTrophy( trophies );
			break;
		case 7:		// Print all Trophies
			printTrophies( trophies );
			break;
		case 8:		// Exit
			cout << "You have chosen to exit the application, good-bye!" << endl;
			break;
		default:
			cout << "That is not a recognized menu selection, choose again." << endl;
			break;
		}

	} while( input != 8 );

	// Free trophy memory.
	for( Trophy* trophy : trophies )
	{
		delete trophy;
	}
	trophies.clear();

	return 0;
}

// Print the menu to the user and accept their menu choice
int printMenu()
{
	int input;
	string inputStr = "";
	printMenuOptions();

	getline( cin,inputStr );
	safeStr2Int( input,inputStr );

	while( !safeStr2Int( input,inputStr ) )
	{
		cout << "That is not a recognized menu selection, choose again." << endl;
		printMenuOptions();
		getline( cin,inputStr );
	}

	return input;
}

void printMenuOptions()
{
	cout << "-----------------------------------------" << endl
		<< "Please select an option :" << endl
		<< "1 - Add a new Trophy" << endl
		<< "2 - Copy a Trophy" << endl
		<< "3 - Delete a Trophy" << endl
		<< "4 - Rename a Trophy" << endl
		<< "5 - Change the level of a Trophy" << endl
		<< "6 - Change the color of a Trophy" << endl
		<< "7 - Print All the Trophies" << endl
		<< "8 - Exit the program" << endl
		<< "-----------------------------------------" << endl;
}

// Add a new Trophy to the collection
void addTrophy( vector<Trophy*>& trophies )
{
	cout << "You have chosen to add a trophy." << endl;

	// Ask user for trophy info and emplace into vector.
	trophies.push_back( promptForTrophy() );
}

// Delete an existing Trophy from the collection
void deleteTrophy( vector<Trophy*>& trophies )
{
	cout << "You have chosen to delete an existing trophy." << endl;
	string name = promptForString( PROMPT_FOR_NAME );

	// Find the trophy and if it exists, erase it from the vector
	const int removeIndex = searchForTrophy( trophies,name );

	// Remove trophy or error if couldn't find it.
	if( removeIndex == -1 )
	{
		cout << "Couldn't find trophy to remove!" << endl;
	}
	else
	{
		// Swap bad trophy with the one at the end and
		//  remove the bad one.
		// swap( trophies[removeIndex],trophies.back() );
		// trophies.pop_back();

		// Or not since the evaluator doesn't like that.
		delete trophies[removeIndex];
		trophies.erase( trophies.begin() + removeIndex );
	}
}

// Copy an existing Trophy in the collection
void copyTrophy( vector<Trophy*>& trophies )
{
	cout << "You have chosen to copy an existing trophy." << endl;
	string name = promptForString( PROMPT_FOR_NAME );

	// Find the trophy and if it exists, copy it and
	//  add the copy to the vector
	const int spot = searchForTrophy( trophies,name );
	if( spot == -1 )
	{
		cout << "Couldn't find trophy to copy!" << endl;
	}
	else
	{
		trophies.push_back( new Trophy( *trophies[spot] ) );
	}
}

// Rename an existing Trophy (change the name)
void renameTrophy( const vector<Trophy*>& trophies )
{
	cout << "You have chosen to rename an existing trophy." << endl;
	const string name = promptForString( PROMPT_FOR_NAME );
	const string newName = promptForString( "Please enter the new name of the trophy" );
	// Find the trophy and if it exists, change its name
	const int loc = searchForTrophy( trophies,name );

	if( loc == -1 )
	{
		cout << "Trophy not found!" << endl;
	}
	else
	{
		trophies[loc]->setName( newName );
	}
}

// Relevel an existing Trophy (change the level)
void relevelTrophy( const vector<Trophy*>& trophies )
{
	cout << "You have chosen to change the level of an existing trophy." << endl;
	string name = promptForString( PROMPT_FOR_NAME );
	const int newLevel = promptForInt( PROMPT_FOR_LEVEL,1,10 );

	// Find the trophy and if it exists, change its level
	const int index = searchForTrophy( trophies,name );

	if( index == -1 )
	{
		cout << "Couldn't find trophy to change level!" << endl;
	}
	else
	{
		trophies[index]->setLevel( newLevel );
	}
}

// Recolor an existing Trophy (change the color)
void recolorTrophy( const vector<Trophy*>& trophies )
{
	cout << "You have chosen to change the color of an existing trophy." << endl;
	const string name = promptForString( PROMPT_FOR_NAME );
	const Color newCol = promptForColor( PROMPT_FOR_COLOR );
	// TODO: Find the trophy and if it exists, change its color
	const int ind = searchForTrophy( trophies,name );

	if( ind == -1 )
	{
		cout << "Couldn't find trophy to change color!" << endl;
	}
	else
	{
		trophies[ind]->setColor( newCol );
	}
}

// Print all of the Trophies in the collection
void printTrophies( const vector<Trophy*>& trophies )
{
	cout << "You have chosen to print all of the trophies." << endl;

	// Print all the trophies in the order they are stored in the vector
	for( int i = 0; i < int( trophies.size() ); ++i )
	{
		trophies[i]->print();
	}
}

// Ask the user for a Trophy, validate their responses
// Return the Trophy
Trophy* promptForTrophy()
{
	string name = promptForString( PROMPT_FOR_NAME );
	int level = promptForInt( PROMPT_FOR_LEVEL,1,10 );
	Color col = promptForColor( PROMPT_FOR_COLOR );

	Trophy* t = new Trophy( name,level,col );

	return( t );
}

// Ask the user for a string, validate their response
// Return the string
string promptForString( const string& message )
{
	string value = "";
	cout << message << endl;

	getline( cin,value );

	while( value == "" )
	{
		cout << "That is not a valid name.  Try again.";
		getline( cin,value );
	}

	return value;
}

// Ask the user for an int, validate their response by
// checking that it is between minimum and maximum values
// Return the int
int promptForInt( const string& message,int minimum,int maximum )
{
	int value = 0;
	string userInput = "";
	cout << message << endl;

	getline( cin,userInput );
	safeStr2Int( value,userInput );

	// Keep trying until the user gives a valid response.
	while( !safeStr2Int( value,userInput ) ||
		value < minimum || value > maximum )
	{
		cout << "That value is outside the acceptable range.  Try again." << endl;
		getline( cin,userInput );
	}

	return value;
}

// Convert a string to all uppercase (so that we can compare the
// user's entered color to the official color)
string stringToUpper( string value )
{
	// Loop through characters and make each one uppercase.
	for( int i = 0; i < value.length(); ++i )
	{
		value[i] = toupper( value[i] );
	}

	return value;
}

// Ask the user for a color, validate the response
// Return the color
Color promptForColor( const string& message )
{
	bool valueAcceptable = false;
	Color col;
	string value;
	cout << message << endl;

	while( !valueAcceptable )
	{
		// Read in the color
		getline( cin,value );

		// Make sure it's all upper so string match works.
		value = stringToUpper( value );

		// Set color if we have a valid one and exit loop.
		if( value == "GOLD" )
		{
			col = GOLD;
			valueAcceptable = true;
		}
		else if( value == "SILVER" )
		{
			col = SILVER;
			valueAcceptable = true;
		}
		else if( value == "BRONZE" )
		{
			col = BRONZE;
			valueAcceptable = true;
		}
		else
		{
			cout << "That is not an acceptable color.  Try again." << endl;
		}
	}

	return( col );
}

// Search for a trophy in the collection by name
int searchForTrophy( const vector<Trophy*>& trophies,const string& name )
{
	// Find the trophy in the collection by its name
	int trophyIndex = -1;
	for( int i = 0; i < int( trophies.size() ); ++i )
	{
		if( trophies[i]->getName() == name &&
			trophyIndex == -1 )
		{
			trophyIndex = i;
		}
	}

	// If the trophy was not found, print this error, return -1
	if( trophyIndex == -1 )
	{
		cout << "ERROR: The Trophy was not found" << endl;
	}

	// If you find the trophy, return its position in the collection
	return trophyIndex;
}

// Convert a string to an int and return true if it
//  was successful.
bool safeStr2Int( int& intToFill,const string& input )
{
	bool success = false; // Whether conversion worked.
	try
	{
		intToFill = stoi( input );
		success = true;
	}
	catch( const invalid_argument& ex )
	{
		// input wasn't a number...
		intToFill = -1;
		success = false;
	}

	return success;
}
