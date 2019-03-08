#include "TrophyCase.h"

TrophyCase::TrophyCase()
	:
	list(new Trophy*[startSize])
{}

TrophyCase::TrophyCase(const TrophyCase& rhs)
	:
	list(new Trophy*[rhs.capacity]),
	capacity( rhs.capacity ),
	curPos( rhs.curPos )
{
	for(int i = 0; i < curPos; ++i)
	{
		list[i] = new Trophy( *rhs.list[i] );
	}
}

TrophyCase::~TrophyCase()
{
	for(int i = 0; i < curPos; ++i)
	{
		delete list[i];
	}

	delete list;
}

void TrophyCase::addTrophy(const string& name, int level,
	Color c)
{
	list[curPos++] = new Trophy(name, level, c);

	// We must reallocate!
	if(curPos >= capacity/*-1*/)
	{
		Trophy** trophies = nullptr;

		// Add 10% extra capacity.
		capacity = int(float(capacity) * 1.1f);
		trophies = new Trophy*[capacity];

		// Move each list item then get rid of it.
		for(int i = 0; i < curPos; ++i)
		{
			trophies[i] = list[i];
			delete list[i];
		}
		delete list;

		// Assign list to trophies.
		list = trophies;
	}
}

int TrophyCase::getNbrOfTrophies() const
{
	return curPos;
}

int TrophyCase::getAllocatedSize() const
{
	return capacity;
}
