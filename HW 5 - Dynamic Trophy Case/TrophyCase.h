#ifndef TROPHY_CASE_H
#define TROPHY_CASE_H

#include "Trophy.h"

class TrophyCase
{
public:
	TrophyCase();
	TrophyCase(const TrophyCase& rhs);
	TrophyCase& operator=(const TrophyCase& rhs);
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
	friend ostream& operator<<(ostream& lhs,
		const TrophyCase& rhs);
private:
	Trophy* findTrophy(const string& name);
	// This type of sort is scary under the hood but
	//  supposedly works well if we're mostly sorted and
	//  only add a new item on the end.
	void insertionSort();
private:
	static constexpr int startSize = 10;
	Trophy** m_trophies = nullptr;
	int m_capacity = startSize;
	int m_nbrOfTrophies = 0;
};

#endif