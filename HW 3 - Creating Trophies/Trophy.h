#ifndef TROPHY_H
#define TROPHY_H

#include <string>

using namespace std;

enum Color
{
	GOLD,
	SILVER,
	BRONZE
};

class Trophy
{
public:
	Trophy();
	Trophy( const string& name,int level,Color c );

	void setName( const string& newName );
	void setLevel( int newLevel );
	void setColor( Color newColor );

	const string& getName() const;
	int getLevel() const;
	Color getColor() const;
	void print() const;
	static string col2str( Color c );
private:
	string name;
	int level;
	Color col;
};

#endif