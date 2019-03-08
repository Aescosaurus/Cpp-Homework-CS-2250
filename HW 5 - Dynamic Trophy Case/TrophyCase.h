#ifndef TROPHY_CASE_H
#define TROPHY_CASE_H

#include "Trophy.h"

class TrophyCase
{
public:
	TrophyCase();
	TrophyCase(const TrophyCase& rhs);
	~TrophyCase();

	void addTrophy(const string& name, int level,
		Color c);

	int getNbrOfTrophies() const;
	int getAllocatedSize() const;
private:
	static constexpr int startSize = 10;
	Trophy** list = nullptr;
	int capacity = startSize;
	int curPos = 0;
};

#endif