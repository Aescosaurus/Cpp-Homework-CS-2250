#include "Trophy.h"
#include <iostream>

Trophy::Trophy()
	:
	name( "" ),
	level( 0 ),
	col( BRONZE )
{}

Trophy::Trophy( const string& name,int level,Color c )
	:
	name( name ),
	level( level ),
	col( c )
{}

void Trophy::setName( const string& newName )
{
	name = newName;
}

void Trophy::setLevel( int newLevel )
{
	level = newLevel;
}

void Trophy::setColor( Color newColor )
{
	col = newColor;
}

const string& Trophy::getName() const
{
	return name;
}

int Trophy::getLevel() const
{
	return level;
}

Color Trophy::getColor() const
{
	return col;
}

void Trophy::print() const
{
	cout << "[ " << name << " : " << level << " : "
		<< col2str( col ) << " ]" << endl;
}

string Trophy::col2str( Color c )
{
	if( c == GOLD ) return "GOLD";
	else if( c == SILVER ) return "SILVER";
	else return "BRONZE";
}
