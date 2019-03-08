#include "Trophy.h"
#include <iostream>
#include <iomanip>

Trophy::Trophy()
	:
	name(new string("")),
	level(new int(0)),
	col(new Color(BRONZE))
{}

Trophy::Trophy(const string& name, int level, Color c)
	:
	name(new string(name)),
	level(new int(level)),
	col(new Color(c))
{}

Trophy::Trophy(const Trophy& rhs)
	:
	name(new string(*rhs.name)),
	level(new int(*rhs.level)),
	col(new Color(*rhs.col))
{}

Trophy& Trophy::operator=(const Trophy& rhs)
{
	*name = *rhs.name;
	*level = *rhs.level;
	*col = *rhs.col;

	return *this;
}

Trophy::~Trophy()
{
	delete name;
	delete level;
	delete col;
}

void Trophy::setName(const string& newName)
{
	*name = newName;
}

void Trophy::setLevel(int newLevel)
{
	*level = newLevel;
}

void Trophy::setColor(Color newColor)
{
	*col = newColor;
}

const string& Trophy::getName() const
{
	return *name;
}

int Trophy::getLevel() const
{
	return *level;
}

Color Trophy::getColor() const
{
	return *col;
}

void Trophy::print() const
{
	cout << "[ " << *name << " : " << *level << " : "
		<< col2str(*col) << " ]" << endl;
}

string Trophy::col2str(Color c)
{
	if(c == GOLD) return "GOLD";
	else if(c == SILVER) return "SILVER";
	else return "BRONZE";
}

bool Trophy::operator==(const Trophy& rhs) const
{
	return *name == *rhs.name &&
		*level == *rhs.level &&
		*col == *rhs.col;
}

bool Trophy::operator!=(const Trophy& rhs) const
{
	return !(*this == rhs);
}

bool Trophy::operator<(const Trophy& rhs) const
{
	bool result = false;

	if(*level != *rhs.level)
	{
		result = *level < *rhs.level;
	}
	else if(*col != *rhs.col)
	{
		// Since colors are in descending order.
		result = int(*col) > int(*rhs.col);
	}
	else
	{
		result = *name < *rhs.name;
	}

	return result;
}

bool Trophy::operator<=(const Trophy& rhs) const
{
	return *this == rhs || *this < rhs;
}

bool Trophy::operator>(const Trophy& rhs) const
{
	return !(*this < rhs) && *this != rhs;
}

bool Trophy::operator>=(const Trophy& rhs) const
{
	return *this > rhs || *this == rhs;
}

ostream& operator<<(ostream& stream, const Trophy& rhs)
{
	// stream << *rhs.name << ", " << *rhs.level << ", "
	// 	<< Trophy::col2str(*rhs.col);

	stream << "[ " << setw(30) << *rhs.name << ' '
		<< setw(2) << *rhs.level << ' '
		<< setw(6) << Trophy::col2str(*rhs.col) << " ]";

	return stream;
}
