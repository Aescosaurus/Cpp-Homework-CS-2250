#ifndef TROPHY_H
#define TROPHY_H

#include <iostream>
#include <string>
using namespace std;

enum Color { BRONZE, SILVER, GOLD };

class Trophy
{
public:
	Trophy();
	Trophy(string name, int level, Color color);
	~Trophy();
	string GetName() const;
	int GetLevel() const;
	Color GetColor() const;
	void SetName(string name);
	void SetLevel(int level);
	void SetColor(Color color);
	void Print() const;

	bool operator==(const Trophy& trophy) const;
	bool operator<(const Trophy& trophy) const;
	bool operator>(const Trophy& trophy) const;
	bool operator<=(const Trophy& trophy) const;
	bool operator>=(const Trophy& trophy) const;
	bool operator!=(const Trophy& trophy) const;

	friend ostream& operator<<(ostream& sout, const Trophy& trophy);

private:
	string name;
	int level;
	Color color;
};

#endif