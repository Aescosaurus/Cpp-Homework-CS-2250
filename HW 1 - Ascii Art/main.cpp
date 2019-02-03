#include <iostream>

using namespace std;

// Prints a message welcoming the user to the program.
void PrintWelcomeMessage();
// Gives the user options of shapes to print, then prints.
bool HandleMainLoop();
// Prints the selectable menu options.
void PrintMenu();
// Reads user choices into command and size.
void CheckUserInput( int& command,int& size );
// Ask user what size shape to draw.
void PromptForSize( int& size );

int main()
{
	// Welcome the user, it's polite!
	PrintWelcomeMessage();

	// Draw shapes until the user asks to quit.
	while( HandleMainLoop() );

	return( 0 );
}

// Welcomes the user and gives some information about how
//  this application works and what it does.
void PrintWelcomeMessage()
{
	// Say welcome to the user.
	cout << "Welcome!  This program will draw different "
		<< "shapes for you!" << endl;
	cout << "Select an option to get started:" << endl;
}

// Shows the menu and reads in user input then prints
//  the chosen shape or quits(whatever the user chooses).
//  Returns true if we should keep looping and false if
//  the user wants to quit.
bool HandleMainLoop()
{
	int command = -1;  // Option the user picked.
	int size = -1;     // Size of shape (if applicable).
	bool stop = false; // Whether or not to exit app.

	// Show user their options and ask them to pick one.
	PrintMenu();
	CheckUserInput( command,size );

	// Draw shape based on command, or exit if picked.
	switch( command )
	{
	case 1: DrawSquare( size ); break;
	case 2: DrawRightTri( size ); break;
	case 3: DrawIscTri( size ); break;
	case 4: DrawHourglass( size ); break;
	case 5: DrawDiamond( size ); break;
	case 6: stop = true; break;
	}

	// Return true (!stop) to keep going, and vice versa.
	return( !stop );
}

// Prints out all valid menu options(square, right and
//  isosceles triangles, hourglass, diamond, quit).
void PrintMenu()
{
	// Print a nifty menu with all the options.
	cout << "-----Menu-----" << endl;
	cout << "1. Square" << endl;
	cout << "2. Right Triangle" << endl;
	cout << "3. Isosceles Triangle" << endl;
	cout << "4. Hourglass" << endl;
	cout << "5. Diamond" << endl;
	cout << "6. Quit(exit the application)" << endl;
}

// Ask the user to pick an option, then read in their
//  feedback into command.  If they pick a shape(not quit),
//  read their input into size.
// command: Which option the user picks.
// size: Size of shape to draw.
void CheckUserInput( int& command,int& size )
{
	// Prompt the user for their command and read it.
	cout << "Please pick a command(1-6): ";
	cin >> command;
	cout << endl;

	// If it's a shape ask for size, if the command is
	//  invalid keep asking until a valid one is given.
	switch( command )
	{
	case 1: case 2: case 3: case 4: case 5:
		PromptForSize( size );
		break;
	case 6:
		break;
	default:
		cout << "Invalid command, please try again!"
			<< endl;
		CheckUserInput( command,size );
		break;
	}
}

void PromptForSize( int& size )
{
	cout << "Please pick a size(1-20): ";
	cin >> size;
	cout << endl;

	if( size < 1 || size > 20 )
	{
		cout << "Invalid size, please retry!" << endl;
		PromptForSize( size );
	}
}
