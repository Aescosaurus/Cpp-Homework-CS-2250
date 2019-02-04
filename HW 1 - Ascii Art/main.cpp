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
void PromptForSize( int& size,int command );
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
// Draws '*' or ' ' based on x position.
void DrawCharBasedOnX( int x,int starSub,int width );
// Add or remove stars 
void UpdateStarCount( int& curStars,bool addOrRemove,
	int starDelta );
// Tells the user what they selected and asks for a size.
void OutputCommandQuestion( int command );

int main()
{
	// Welcome the user, it's polite!
	PrintWelcomeMessage();

	// Draw shapes until the user asks to quit.
	while( HandleMainLoop() );

	cout << "Thank you for using our application!  "
		<< "Good-bye!";

	return( 0 );
}

// Welcomes the user and gives some information about how
//  this application works and what it does.
void PrintWelcomeMessage()
{
	// Say welcome to the user.
	cout << "Welcome to the shape renderer!" << endl;
	cout << "You can draw a few different shapes at a "
		<< "variety of sizes!" << endl;
	cout << "*********************************************"
		<< "***********************************" << endl;
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
	cout << "* Please select a menu option(1 - 6) :"
		<< endl;
	cout << "* 1 - Square" << endl;
	cout << "* 2 - Right Triangle" << endl;
	cout << "* 3 - Isosceles Triangle" << endl;
	cout << "* 4 - Hourglass" << endl;
	cout << "* 5 - Diamond" << endl;
	cout << "* 6 - Quit(exit the application)" << endl;
	cout << "*********************************************"
		<< "***********************************" << endl;
}

// Ask the user to pick an option, then read in their
//  feedback into command.  If they pick a shape(not quit),
//  read their input into size.
// command: Which option the user picks.
// size: Size of shape to draw.
void CheckUserInput( int& command,int& size )
{
	// Prompt the user for their command and read it.
	cout << "Please select a menu option(1-6)" << endl;
	cin >> command;

	// If it's a shape ask for size, if the command is
	//  invalid keep asking until a valid one is given.
	switch( command )
	{
	case 1: case 2: case 3: case 4: case 5:
		PromptForSize( size,command ); // Get size of shape.
		break;
	case 6: // User wants to quit, do nothing.
		break;
	default: // Keep retrying until result is valid.
		cout << "You have not selected a valid menu "
			<< "option, please try again." << endl;
		CheckUserInput( command,size );
		break;
	}
}

// Asks user how big to draw some shape and ensures the
//  value inputted is between 1 and 20.
// size: How big to draw shape.
void PromptForSize( int& size,int command )
{
	// Prompt user to input a size.
	OutputCommandQuestion( command );
	cin >> size;
	cout << endl;

	// Keep asking until the user gives something valid.
	if( size < 1 || size > 20 )
	{
		cout << "You have not selected an appropriate "
			<< "size, please try again." << endl;
		PromptForSize( size,command );
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
			DrawCharBasedOnX( x,STAR_SUB,BASE );
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
			DrawCharBasedOnX( x,STAR_SUB,BASE );
		}

		// Remove stars if we're above the middle, add
		//  stars if we're after it.
		UpdateStarCount( curStars,y >= HALFWAY,STAR_DELTA );
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
			DrawCharBasedOnX( x,STAR_SUB,WIDTH );
		}
		// Add or remove stars based on y.  Kind of like
		//  an inside out hourglass.
		UpdateStarCount( curStars,y < HALFWAY,STAR_DELTA );
		cout << endl;
	}
}

// Draw a '*' or a ' ' based on x position and buffer
//  characters required on the edges.
// x: Current x position on screen.
// starSub: Buffer space needed on the edges.
// width: Width/base/size of object being drawn.
void DrawCharBasedOnX( int x,int starSub,int width )
{
	// Draw stars in the center and spaces on the outside.
	if( x >= starSub &&
		x < width - starSub )
	{
		cout << '*';
	}
	else
	{
		cout << ' ';
	}
}

// Update current number of stars by delta based on whether
//  we should add or remove.
// curStars: Reference to current star count.
// addOrRemove: Whether to add or remove starDelta.
// starDelta: Number of stars to add/remove.
void UpdateStarCount( int& curStars,bool addOrRemove,
	int starDelta )
{
	// If add, add stars if remove, remove them.
	if( addOrRemove )
	{
		curStars += starDelta;
	}
	else
	{
		curStars -= starDelta;
	}
}

// Asks the user which size to make the shape.
// command: Shape chosen (it matters).
void OutputCommandQuestion( int command )
{
	// Print the right question based on  the command.
	switch( command )
	{
	case 1:
		cout << "You have selected a square!  "
			<< "What size should your square be (1-20)?";
		break;
	case 2:
		cout << "You have selected a right triangle!  "
			<< "What size should your right triangle be "
			<< "(1-20)?";
		break;
	case 3:
		cout << "You have selected a isosceles triangle!  "
			<< "What size should your isosceles triangle "
			<< "be (1-20)?";
		break;
	case 4:
		cout << "You have selected an hourglass!  What "
			<< "size should your hourglass be (1-20)?";
		break;
	case 5:
		cout << "You have selected an diamond!  What size "
			<< "should your diamond be (1-20)?" << endl;
		break;
	}
}
