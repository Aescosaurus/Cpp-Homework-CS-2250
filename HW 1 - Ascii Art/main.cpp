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
// Draws a square to the screen with specified size.
void DrawSquare( int size );
// Draws a right triangle to the screen with size.
void DrawRightTri( int size );
// Draws an isosceles triangle to the screen.
void DrawIscTri( int size );
// Draws an hourglass shape on the screen.
void DrawHourglass( int size );
// Draws a diamond on the screen.
void DrawDiamond( int size );

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
		PromptForSize( size ); // Get size of shape.
		break;
	case 6: // User wants to quit, do nothing.
		break;
	default: // Keep retrying until result is valid.
		cout << "Invalid command, please try again!"
			<< endl;
		CheckUserInput( command,size );
		break;
	}
}

// Asks user how big to draw some shape and ensures the
//  value inputted is between 1 and 20.
// size: How big to draw shape.
void PromptForSize( int& size )
{
	// Prompt user to input a size.
	cout << "Please pick a size(1-20): ";
	cin >> size;
	cout << endl;

	// Keep asking until the user gives something valid.
	if( size < 1 || size > 20 )
	{
		cout << "Invalid size, please retry!" << endl;
		PromptForSize( size );
	}
}

// Draws a square with width/height of size on the screen.
// size: How big to draw the square.
void DrawSquare( int size )
{
	// Loop over y first because lines go down.
	for( int y = 0; y < size; ++y )
	{
		// Loop over x of every line and put a *.
		for( int x = 0; x < size; ++x )
		{
			cout << '*';
		}

		// Print out newline to make it a real square.
		cout << endl;
	}
}

// Draws a right triangle onto the screen.
// size: Size of base and height of the triangle.
void DrawRightTri( int size )
{
	// Loop over y first because console lines go down.
	for( int y = 0; y < size; ++y )
	{
		// x loops as much as how far y went.
		for( int x = 0; x <= y; ++x )
		{
			cout << '*';
		}

		// Make sure it's not all on the same line.
		cout << endl;
	}
}

// Draws an isosceles triangle onto the screen.  Base is
//  size * 2 - 1, height is size by itself.
// size: How big the triangle is.
void DrawIscTri( int size )
{
	const int BASE = ( size * 2 ) - 1; // Width of base.
	const int STAR_ADD_PER_LEVEL = 2;  // How many stars to
	                                   //  add per y level.
	int curStars = 1;                  // Stars for current
	                                   //  level.

	for( int y = 0; y < size; ++y )
	{
		for( int x = 0; x < BASE; ++x )
		{
			// How much space is on each side of the stars.
			const int STAR_SUB = ( BASE - curStars ) / 2;

			// Make sure we have empty buffers on the sides
			//  so it doesn't draw a square.
			if( x >= STAR_SUB &&
				x < BASE - STAR_SUB )
			{
				cout << '*';
			}
			else
			{
				cout << ' ';
			}
		}

		// Draw 2 more stars each level, print newline.
		curStars += STAR_ADD_PER_LEVEL;
		cout << endl;
	}
}

// Draws an hourglass with height and base of 2 * size - 1.
// size: Size of the hourglass' base and height.
void DrawHourglass( int size )
{
	const int BASE = 2 * size - 1;   // Base width.
	const int HEIGHT = 2 * size - 1; // Height.
	const int HALFWAY = HEIGHT / 2;  // Distance to center.
	const int STAR_DELTA = 2;        // How many stars to
	                                 //  add or decrease
	                                 //  each y level.
	int curStars = BASE;             // Stars to draw.

	for( int y = 0; y < HEIGHT; ++y )
	{
		for( int x = 0; x < BASE; ++x )
		{
			// Buffer space on edges of stars.
			const int STAR_SUB = ( BASE - curStars ) / 2;

			// Only draw stars in the middle, not sides.
			if( x >= STAR_SUB &&
				x < BASE - STAR_SUB )
			{
				cout << '*';
			}
			else
			{
				cout << ' ';
			}
		}

		// Remove stars if we're above the middle, add
		//  stars if we're after it.
		if( y < HALFWAY )
		{
			curStars -= STAR_DELTA;
		}
		else
		{
			curStars += STAR_DELTA;
		}
		cout << endl;
	}
}

// Draws a diamond to the screen.  Width as well as height
//  are 2 * size - 1.
// size: How big the diamond should be.
void DrawDiamond( int size )
{
	const int WIDTH = 2 * size - 1;  // Width of diamond.
	const int HEIGHT = 2 * size - 1; // Height of diamond.
	const int HALFWAY = HEIGHT / 2;  // Middle of diamond.
	const int STAR_DELTA = 2;        // How many stars to
	                                 //  add or remove
	                                 //  every y level.
	int curStars = 1;                // Stars to draw on
	                                 //  the current y.

	for( int y = 0; y < HEIGHT; ++y )
	{
		for( int x = 0; x < WIDTH; ++x )
		{
			// Buffer space on edges of stars.
			const int STAR_SUB = ( WIDTH - curStars ) / 2;

			// Only draw stars in the middle, not sides.
			if( x >= STAR_SUB &&
				x < WIDTH - STAR_SUB )
			{
				cout << '*';
			}
			else
			{
				cout << ' ';
			}
		}
		// Add or remove stars based on y.  Kind of like
		//  an inside out hourglass.
		if( y < HALFWAY )
		{
			curStars += STAR_DELTA;
		}
		else
		{
			curStars -= STAR_DELTA;
		}
		cout << endl;
	}
}
