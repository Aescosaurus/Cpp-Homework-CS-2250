#include "Trophy.h"

Trophy::Trophy()
{
	name = "";
	level = 1;
	color = BRONZE;
}

Trophy::Trophy(string name, int level, Color color)
{
	this->name = name;
	this->level = level;
	this->color = color;
}

Trophy::~Trophy()
{
}

string Trophy::GetName() const
{
	return name;
}

int Trophy::GetLevel() const
{
	return level;
}

Color Trophy::GetColor() const
{
	return color;
}

void Trophy::SetName(string name)
{
	this->name = name;
}

void Trophy::SetLevel(int level)
{
	this->level = level;
}

void Trophy::SetColor(Color color)
{
	this->color = color;
}

void Trophy::Print() const
{
	string colorString = "";
	switch (color)
	{
	case GOLD:
		colorString = "GOLD";
		break;
	case SILVER:
		colorString = "SILVER";
		break;
	case BRONZE:
		colorString = "BRONZE";
		break;
	}

	cout << "[ " << name << " : " << level << " : " << colorString << " ]" << endl;
}

bool Trophy::operator==(const Trophy& trophy) const
{
	return (name == trophy.name && color == trophy.color && level == trophy.level);
}

bool Trophy::operator<(const Trophy& trophy) const
{
	if (level < trophy.level)
	{
		return true;
	}
	else if (level > trophy.level)
	{
		return false;
	}
	else // if (level == trophy.level)
	{
		if (color < trophy.color)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool Trophy::operator>(const Trophy& trophy) const
{
	if (level > trophy.level)
	{
		return true;
	}
	else if (level < trophy.level)
	{
		return false;
	}
	else // if (level == trophy.level)
	{
		if (color > trophy.color)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool Trophy::operator<=(const Trophy& trophy) const
{
	return (*this == trophy || *this < trophy);
}

bool Trophy::operator>=(const Trophy& trophy) const
{
	return (*this == trophy || *this > trophy);
}

bool Trophy::operator!=(const Trophy& trophy) const
{
	return !(*this == trophy);
}

ostream& operator<<(ostream& sout, const Trophy& trophy)
{
	sout << "[ " << trophy.name << " : " << trophy.level << " : ";
	
	switch (trophy.color)
	{
	case GOLD:
		sout << "GOLD";
		break;
	case BRONZE:
		sout << "BRONZE";
		break;
	case SILVER:
		sout << "SILVER";
		break;
	}
	
	sout << " ]";
	return sout;
}