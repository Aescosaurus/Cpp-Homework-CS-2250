#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Prints a message welcoming the user to the program.
void PrintWelcomeMessage();
// Gives the user options of shapes to print, then prints.
bool HandleMainLoop();
// Prints the selectable menu options.
void PrintMenu();
// Reads user choices into command and size.
void CheckUserInput( int& command,string& message,int& shift );
// Prompts for generic message and returns user input.
string PromptForMessage( const string& msg );
// Asks user for some value and returns what they input.
int PromptForValue( const string& msg );
// Encrypts msg with caesar cipher shifting by shiftVal.
string Encrypt( const string& msg,int shiftVal );
// Shifts a character by a certain amount.
char ShiftSingleChar( char unencrypted,int shift );
// Encrypt msg by shift and print it.
void PrintEncryptedMessage( const string& msg,int shift );
// Decrypts msg by shift and prints it.
void PrintDecryptedMessage( const string& msg,int shift );
// Tries all possible decryption shifts and prints them out.
void PrintForceDecrypted( const string& msg );
// Subtracts upper or lowercase letter to turn ascii to 1-26.
char SubUpperOrLower( char ascii,int character );
// Adds upper or lowercase letter to turn ascii from 1-26 to actual ascii.
char AddUpperOrLower( char ascii,int character );
int MoveCharByShift( int asciiCode,int shift );

int main()
{
	// Welcome the user, it's polite!
	PrintWelcomeMessage();

	// Draw shapes until the user asks to quit.
	while( HandleMainLoop() );

	cout << "Thank you Caesar!  See ya!";

	return( 0 );
}

// Welcomes the user and gives some information about how
//  this application works and what it does.
void PrintWelcomeMessage()
{
	// Say welcome to the user.
	cout << "Welcome to the Tali-banned Encrypter!" << endl;
	cout << "Make a selection from the menu and then "
		<< "follow the prompts." << endl;
	cout << "*************************************" << endl;
}

// Shows the menu and reads in user input then prints
//  the chosen shape or quits(whatever the user chooses).
//  Returns true if we should keep looping and false if
//  the user wants to quit.
bool HandleMainLoop()
{
	int command = -1;  // Option the user picked.
	string userMessage = ""; // User inputted message.
	int shift = -1; // How much to shift for encryption.
	bool stop = false; // Whether or not to exit app.

	// Show user their options and ask them to pick one.
	PrintMenu();
	CheckUserInput( command,userMessage,shift );

	// Draw shape based on command, or exit if picked.
	switch( command )
	{
	case 1: PrintEncryptedMessage( userMessage,shift ); break;
	case 2: PrintDecryptedMessage( userMessage,shift ); break;
	case 3: PrintForceDecrypted( userMessage ); break;
	case 4: stop = true; break;
	}

	// Return true (!stop) to keep going, and vice versa.
	return( !stop );
}

// Prints out all valid menu options(square, right and
//  isosceles triangles, hourglass, diamond, quit).
void PrintMenu()
{
	// Print a nifty menu with all the options.
	cout << "* 1 - Encrypt a message" << endl;
	cout << "* 2 - Decrypt a message" << endl;
	cout << "* 3 - Brute - force decrypt a message" << endl;
	cout << "* 4 - Quit" << endl;
	cout << "*************************************" << endl;
}

// Ask the user to pick an option, then read in their
//  feedback into command.  If they pick a shape(not quit),
//  read their input into size.
// command: Which option the user picks.
// size: Size of shape to draw.
void CheckUserInput( int& command,string& message,int& shift )
{
	// Prompt the user for their command and read it.
	cout << "Please make a menu selection (1-4):" << endl;
	cin >> command;
	cin.ignore();

	// If it's a shape ask for size, if the command is
	//  invalid keep asking until a valid one is given.
	switch( command )
	{
	case 1:
		message = PromptForMessage( "Please enter the message to encrypt:" );
		shift = PromptForValue( "Please enter the shift value (1-25):" );
		break;
	case 2:
		message = PromptForMessage( "Please enter the message to decrypt:" );
		shift = PromptForValue( "Please enter the shift value (1-25):" );
		break;
	case 3:
		message = PromptForMessage( "Please enter the message to decrypt:" );
		break;
	case 4: // User wants to quit, do nothing.
		break;
	default: // Keep retrying until result is valid.
		cout << "Invalid choice, ";
		CheckUserInput( command,message,shift );
		break;
	}
}

// Asks user to enter message and returns the input.
// msg: What to ask the user.
string PromptForMessage( const string& msg )
{
	string input; // User's message response.

	// Ask user for and get input.
	cout << msg << endl;
	getline( cin,input );

	return( input );
}

// Print message then ask user for value, and return that.
int PromptForValue( const string& msg )
{
	int input = 0; // User inputted value.

	// Ask user for and get value.
	cout << msg << endl;
	cin >> input;
	cin.ignore();

	if( input < 1 || input > 25 )
	{
		cout << "Invalid choice, ";
		input = PromptForValue( msg );
	}

	return( input );
}

// Encrypts a message with a caesar cipher.
// msg: Message needing encryption.
// shiftVal: How far to shift each character.
string Encrypt( const string& msg,int shiftVal )
{
	string encrypted = ""; // The encrypted message.

	// Encrypt each char of msg then add to encrypted.
	for( int i = 0; i < int( msg.length() ); ++i )
	{
		encrypted += ShiftSingleChar( msg[i],shiftVal );
	}

	return( encrypted );
}

// Encrypt a single character with caesar cypher.  Shift
//  unencrypted by shift.
// unencrypted: Character needing encryption.
// shift: How much to shift character by.
char ShiftSingleChar( char unencrypted,int shift )
{
	int ascii = int( unencrypted ); // Ascii code to modify.

	// Only shift if in the alphabet.
	if( isalpha( unencrypted ) )
	{
		ascii = SubUpperOrLower( ascii,unencrypted );

		ascii = MoveCharByShift( ascii,shift );

		ascii = AddUpperOrLower( ascii,unencrypted );
	}
	else
	{
		ascii = int( unencrypted );
	}

	return( char( ascii ) );
}

void PrintEncryptedMessage( const string& msg,int shift )
{
	cout << "Encrypted as:" << endl << Encrypt( msg,shift ) << endl;
}

void PrintDecryptedMessage( const string& msg,int shift )
{
	cout << "Decrypted as:" << endl << Encrypt( msg,-shift ) << endl;
}

void PrintForceDecrypted( const string & msg )
{
	cout << "Decrypted as:" << endl;
	for( int i = 25; i > 0; --i )
	{
		cout << Encrypt( msg,i ) << endl;
	}
}

char SubUpperOrLower( char ascii,int character )
{
	if( isupper( character ) )
	{
		ascii -= int( 'A' );
	}
	else // Lower case.
	{
		ascii -= int( 'a' );
	}

	return( ascii );
}

char AddUpperOrLower( char ascii,int character )
{
	if( isupper( character ) )
	{
		ascii += int( 'A' );
	}
	else // Lower case.
	{
		ascii += int( 'a' );
	}

	return( ascii );
}

int MoveCharByShift( int asciiCode,int shift )
{
	while( shift > 0 )
	{
		--shift;
		++asciiCode;
		if( asciiCode > 25 ) asciiCode = 0;
	}
	while( shift < 0 )
	{
		++shift;
		--asciiCode;
		if( asciiCode < 0 ) asciiCode = 25;
	}

	return( asciiCode );
}
