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
	Trophy(const string& name, int level, Color c);
	Trophy(const Trophy& rhs);
	Trophy& operator=(const Trophy& rhs);
	~Trophy();

	void setName(const string& newName);
	void setLevel(int newLevel);
	void setColor(Color newColor);

	const string& getName() const;
	int getLevel() const;
	Color getColor() const;
	void print() const;
	static string col2str(Color c);
	bool operator==(const Trophy& rhs) const;
	bool operator!=(const Trophy& rhs) const;
	// Do I need these?
	// bool operator<( const Trophy& rhs ) const;
	// bool operator<=( const Trophy& rhs ) const;
	// bool operator>( const Trophy& rhs ) const;
	// bool operator>=( const Trophy& rhs ) const;
	friend ostream& operator<<(ostream& stream,
		const Trophy& rhs);
private:
	string* name;
	int* level;
	Color* col;
};

#endif