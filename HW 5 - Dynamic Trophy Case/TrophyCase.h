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
	bool copyTrophy(const string& copyee);
	bool deleteTrophy(const string& toDelete);
	bool renameTrophy(const string& name,
		const string& fixedName);
	bool relevelTrophy(const string& name,
		int fixedLevel);
	bool recolorTrophy(const string& name,
		Color fixedCol);

	int getNbrOfTrophies() const;
	int getAllocatedSize() const;
private:
	Trophy* findTrophy(const string& name);
private:
	static constexpr int startSize = 10;
	Trophy** list = nullptr;
	int capacity = startSize;
	int curPos = 0;
};

#endif