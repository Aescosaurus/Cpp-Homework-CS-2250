#include <iostream>
#include <string>
#include <vector>
#include "TrophyCase.h"
using namespace std;

// Numerical Contants
const int MINIMUM_LEVEL = 1;
const int MAXIMUM_LEVEL = 50;
const int MAXIMUM_NAME_LENGTH = 30;

// Reusable strings
const string PROMPT_FOR_NAME = "Please enter the name of the Trophy:";
const string PROMPT_FOR_EXISTING_NAME = "Please enter the name of the existing Trophy:";
const string PROMPT_FOR_NEW_NAME = "Please enter the new name of the Trophy:";
const string PROMPT_FOR_LEVEL = "Please enter the level of your Trophy:";
const string PROMPT_FOR_COLOR = "Please enter the color of your Trophy: (GOLD, SILVER, or BRONZE)";
const string PROMPT_FOR_CASE_NUMBER = "Please enter the number of the case:";
const string PROMPT_FOR_CASE_NUMBER_COPY = "Please enter the number of the case to copy:";
const string PROMPT_FOR_CASE_NUMBER_OVERWRITE = "Please enter the number of the case to overwrite:";

const string MESSAGE_QUIT = "You have chosen to exit the application, good-bye!";

const string CONFIRM_CREATE_CASE = "You have chosen to create a new Trophy Case.";
const string CONFIRM_COPY_CASE = "You have chosen to copy an existing Trophy Case.";
const string CONFIRM_OVERWRITE_CASE = "You have chosen to overwrite a Trophy Case with another one.";
const string CONFIRM_DELETE_CASE = "You have chose to delete a Trophy Case.";
const string CONFIRM_ADD_TROPHY = "You have chosen to add a trophy.";
const string CONFIRM_DELETE_TROPHY = "You have chosen to delete an existing trophy.";
const string CONFIRM_COPY_TROPHY = "You have chosen to copy an existing trophy.";
const string CONFIRM_RENAME_TROPHY = "You have chosen to change the name of an existing trophy.";
const string CONFIRM_RELEVEL_TROPHY = "You have chosen to change the level of an existing trophy.";
const string CONFIRM_RECOLOR_TROPHY = "You have chosen to change the color of an existing trophy.";
const string CONFIRM_PRINT_TROPHIES = "You have chosen to print all of the trophies.";

const string ERROR_MENU_SELECTION = "That is not a recognized menu selection, choose again.";
const string ERROR_NAME = "That is not a valid name.  Try again.";
const string ERROR_INTEGER = "That value is outside the acceptable range.  Try again.";
const string ERROR_COLOR = "That is not an acceptable color.  Try again.";
const string ERROR_NO_CASES_EXIST = "There are no Trophy Cases.  Create one first.";
const string ERROR_TROPHY_CANNOT_BE_FOUND = "That trophy could not be found.";

char printMenu();

// Menu choice handlers
void createNewCase(vector<TrophyCase>& trophyCases);
void copyCase(vector<TrophyCase>& trophyCases);
void overwriteCase(vector<TrophyCase>& trophyCases);
void deleteCase(vector<TrophyCase>& trophyCases);
void addTrophy(vector<TrophyCase>& trophyCases);
void copyTrophy(vector<TrophyCase>& trophyCases);
void deleteTrophy(vector<TrophyCase>& trophyCases);
void renameTrophy(vector<TrophyCase>& trophyCases);
void relevelTrophy(vector<TrophyCase>& trophyCases);
void recolorTrophy(vector<TrophyCase>& trophyCases);
void printTrophies(vector<TrophyCase>& trophyCases);

// Input handlers
string promptForString(const string& message, int maxLength = 0);
int promptForInt(const string& message, int minimum, int maximum);
Color promptForColor(const string& message);

// Useful helper methods
int convertStringToInt(const string& input);
string stringToUpper(string value);

// This application allows for the management of a trophy collection
int main()
{
	vector<TrophyCase> trophyCases;

	cout << "**************************************************" << endl
		<< "Welcome to the Trophy Case editor!" << endl
		<< "With this application, you can manage your trophy" << endl
		<< "collection - add, modify, or remove trophies or" << endl
		<< "trophy cases by using this simple menu!" << endl
		<< "**************************************************" << endl;

	// Loop the menu, allowing the user to select an action each time
	int input;
	do
	{
		input = printMenu();
		switch(input)
		{
		case 1:		// Create a new Trophy Case
			createNewCase(trophyCases);
			break;
		case 2:		// Copy an existing Case into a new Case
			copyCase(trophyCases);
			break;
		case 3:		// Overwrite an existing Case with another
			overwriteCase(trophyCases);
			break;
		case 4:
			deleteCase(trophyCases);
			break;
		case 5:		// print all Trophies
			printTrophies(trophyCases);
			break;
		case 6:		// Add a new Trophy
			addTrophy(trophyCases);
			break;
		case 7:		// Copy an existing Trophy
			copyTrophy(trophyCases);
			break;
		case 8:		// Delete an existing Trophy
			deleteTrophy(trophyCases);
			break;
		case 9:		// Rename a Trophy
			renameTrophy(trophyCases);
			break;
		case 10:		// Change the level of a Trophy
			relevelTrophy(trophyCases);
			break;
		case 11:		// Change the color of a Trophy
			recolorTrophy(trophyCases);
			break;
		case 12:		// Exit
			cout << MESSAGE_QUIT << endl;
			break;
		default:
			cout << ERROR_MENU_SELECTION << endl;
			break;
		}

	} while(input != 12);

	return 0;
}

// print the menu to the user and accept their menu choice
char printMenu()
{
	int value;
	string input;
	cout << "----------------------------------------------------------------" << endl
		<< "Please select an option :" << endl
		<< "1  - Create a new TrophyCase" << endl
		<< "2  - Copy an existing TrophyCase" << endl
		<< "3  - Overwrite an existing TrophyCase with another TrophyCase" << endl
		<< "4  - Delete a TrophyCase" << endl
		<< "5  - Print all the Trophies" << endl
		<< "6  - Add a new Trophy" << endl
		<< "7  - Copy a Trophy" << endl
		<< "8  - Delete a Trophy" << endl
		<< "9  - Change the name of a Trophy" << endl
		<< "10 - Change the level of a Trophy" << endl
		<< "11 - Change the color of a Trophy" << endl
		<< "12 - Exit the program" << endl
		<< "----------------------------------------------------------------" << endl;
	getline(cin, input);
	value = convertStringToInt(input);
	return value;
}

// Create a new TrophyCase
void createNewCase(vector<TrophyCase>& trophyCases)
{
	cout << CONFIRM_CREATE_CASE << endl;
	trophyCases.push_back(TrophyCase());
}

// Copy an existing TrophyCase into a new TrophyCase
void copyCase(vector<TrophyCase>& trophyCases)
{
	cout << CONFIRM_COPY_CASE << endl;
	int caseIndex = promptForInt(PROMPT_FOR_CASE_NUMBER_COPY, 1, trophyCases.size()) - 1;

	trophyCases.push_back(TrophyCase(trophyCases[caseIndex]));
}

// Copy an existing TrophyCase into an existing TrophyCase
void overwriteCase(vector<TrophyCase>& trophyCases)
{
	cout << CONFIRM_OVERWRITE_CASE << endl;
	int copyIndex = promptForInt(PROMPT_FOR_CASE_NUMBER_COPY, 1, trophyCases.size()) - 1;
	int overwriteIndex = promptForInt(PROMPT_FOR_CASE_NUMBER_OVERWRITE, 1, trophyCases.size()) - 1;

	trophyCases[overwriteIndex] = trophyCases[copyIndex];
}

// Delete an existing TrophyCase
void deleteCase(vector<TrophyCase>& trophyCases)
{
	cout << CONFIRM_DELETE_CASE << endl;
	int index = promptForInt(PROMPT_FOR_CASE_NUMBER, 1, trophyCases.size()) - 1;
	trophyCases.erase(trophyCases.begin() + index);
}

// Add a new Trophy to the collection
void addTrophy(vector<TrophyCase>& trophyCases)
{
	cout << CONFIRM_ADD_TROPHY << endl;

	if(trophyCases.empty())
	{
		cout << ERROR_NO_CASES_EXIST << endl;
		return;
	}

	// Ask the user for the case and trophy info
	int index = promptForInt(PROMPT_FOR_CASE_NUMBER, 1, trophyCases.size()) - 1;
	string name = promptForString(PROMPT_FOR_NAME, MAXIMUM_NAME_LENGTH);
	int level = promptForInt(PROMPT_FOR_LEVEL, MINIMUM_LEVEL, MAXIMUM_LEVEL);
	Color color = promptForColor(PROMPT_FOR_COLOR);

	trophyCases[index].addTrophy(name, level, color);
}

// Delete an existing Trophy from the collection
void deleteTrophy(vector<TrophyCase>& trophyCases)
{
	cout << CONFIRM_DELETE_TROPHY << endl;

	if(trophyCases.empty())
	{
		cout << ERROR_NO_CASES_EXIST << endl;
		return;
	}

	// Ask the user for the case and trophy info
	int index = promptForInt(PROMPT_FOR_CASE_NUMBER, 1, trophyCases.size()) - 1;
	string name = promptForString(PROMPT_FOR_EXISTING_NAME);

	// Delete the trophy from the case
	if(!trophyCases[index].deleteTrophy(name))
	{
		cout << ERROR_TROPHY_CANNOT_BE_FOUND << endl;
	}
}

// Copy an existing Trophy in the collection
void copyTrophy(vector<TrophyCase>& trophyCases)
{
	cout << CONFIRM_COPY_TROPHY << endl;

	if(trophyCases.empty())
	{
		cout << ERROR_NO_CASES_EXIST << endl;
		return;
	}

	// Ask the user for the case and trophy info
	int index = promptForInt(PROMPT_FOR_CASE_NUMBER, 1, trophyCases.size()) - 1;
	string name = promptForString(PROMPT_FOR_EXISTING_NAME);

	// Delete the trophy from the case
	if(!trophyCases[index].copyTrophy(name))
	{
		cout << ERROR_TROPHY_CANNOT_BE_FOUND << endl;
	}
}

// Rename an existing Trophy (change the name)
void renameTrophy(vector<TrophyCase>& trophyCases)
{
	cout << CONFIRM_RENAME_TROPHY << endl;

	if(trophyCases.empty())
	{
		cout << ERROR_NO_CASES_EXIST << endl;
		return;
	}

	// Ask the user for the case and trophy info
	int index = promptForInt(PROMPT_FOR_CASE_NUMBER, 1, trophyCases.size()) - 1;
	string name = promptForString(PROMPT_FOR_EXISTING_NAME);
	string newName = promptForString(PROMPT_FOR_NEW_NAME, MAXIMUM_NAME_LENGTH);

	// Delete the trophy from the case
	if(!trophyCases[index].renameTrophy(name, newName))
	{
		cout << ERROR_TROPHY_CANNOT_BE_FOUND << endl;
	}
}

// Relevel an existing Trophy (change the level)
void relevelTrophy(vector<TrophyCase>& trophyCases)
{
	cout << CONFIRM_RELEVEL_TROPHY << endl;

	if(trophyCases.empty())
	{
		cout << ERROR_NO_CASES_EXIST << endl;
		return;
	}

	// Ask the user for the case and trophy info
	int index = promptForInt(PROMPT_FOR_CASE_NUMBER, 1, trophyCases.size()) - 1;
	string name = promptForString(PROMPT_FOR_EXISTING_NAME);
	int level = promptForInt(PROMPT_FOR_LEVEL, MINIMUM_LEVEL, MAXIMUM_LEVEL);

	// Delete the trophy from the case
	if(!trophyCases[index].relevelTrophy(name, level))
	{
		cout << ERROR_TROPHY_CANNOT_BE_FOUND << endl;
	}
}

// Recolor an existing Trophy (change the color)
void recolorTrophy(vector<TrophyCase>& trophyCases)
{
	cout << CONFIRM_RECOLOR_TROPHY << endl;

	if(trophyCases.empty())
	{
		cout << ERROR_NO_CASES_EXIST << endl;
		return;
	}

	// Ask the user for the case and trophy info
	int index = promptForInt(PROMPT_FOR_CASE_NUMBER, 1, trophyCases.size()) - 1;
	string name = promptForString(PROMPT_FOR_EXISTING_NAME);
	Color color = promptForColor(PROMPT_FOR_COLOR);

	// Delete the trophy from the case
	if(!trophyCases[index].recolorTrophy(name, color))
	{
		cout << ERROR_TROPHY_CANNOT_BE_FOUND << endl;
	}
}

// print all of the Trophies in the collection
void printTrophies(vector<TrophyCase>& trophyCases)
{
	cout << CONFIRM_PRINT_TROPHIES << endl;
	for(unsigned int i = 0; i < trophyCases.size(); ++i)
	{
		cout << "#############################################" << endl;
		cout << "TrophyCase " << i + 1 << ":" << endl;
		cout << trophyCases[i];
		cout << "#############################################" << endl;
	}
}

// Ask the user for a string, validate their response
// Return the string
string promptForString(const string& message, int maxLength)
{
	string value;
	if(maxLength == 0)
	{
		cout << message << endl;
	}
	else
	{
		cout << message << "(less than " << maxLength << " characters)" << endl;
	}

	getline(cin, value);
	while(value.empty())
	{
		cout << ERROR_NAME << endl;
		getline(cin, value);
	}
	return value;
}

// Ask the user for an int, validate their response by
// checking that it is between minimum and maximum values
// Return the int
int promptForInt(const string& message, int minimum, int maximum)
{
	string input;
	cout << message << " (between " << minimum << " and " << maximum << ")" << endl;
	getline(cin, input);
	int value = convertStringToInt(input);
	while(value < minimum || value > maximum)
	{
		cout << ERROR_INTEGER << endl;
		getline(cin, input);
		value = convertStringToInt(input);
	}
	return value;
}

// Convert a string to an int
int convertStringToInt(const string& input)
{
	int value;
	try
	{
		value = stoi(input);
	}
	catch(exception&)
	{
		value = -1;
	}
	return value;
}

// Convert a string to all uppercase (so that we can compare the
// user's entered color to the official color)
string stringToUpper(string value)
{
	for(char& i : value)
	{
		i = toupper(i);
	}
	return value;
}

// Ask the user for a color, validate the response
// Return the color
Color promptForColor(const string& message)
{
	Color color = BRONZE;
	string value;
	cout << message << endl;

	do
	{
		getline(cin, value);
		string upperValue = stringToUpper(value);

		if(upperValue == "GOLD")
		{
			color = GOLD;
		}
		else if(upperValue == "SILVER")
		{
			color = SILVER;
		}
		else if(upperValue == "BRONZE")
		{
			color = BRONZE;
		}
		else
		{
			cout << ERROR_COLOR << endl;
		}
	} while(color != GOLD && color != SILVER && color != BRONZE);

	return color;
}
