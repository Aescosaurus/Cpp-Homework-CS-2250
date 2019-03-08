#include "TrophyCase.h"
#include <algorithm>

TrophyCase::TrophyCase()
	:
	list(new Trophy*[startSize])
{}

TrophyCase::TrophyCase(const TrophyCase& rhs)
	:
	list(new Trophy*[rhs.capacity]),
	capacity(rhs.capacity),
	curPos(rhs.curPos)
{
	for(int i = 0; i < curPos; ++i)
	{
		list[i] = new Trophy(*rhs.list[i]);
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

	// TODO: Sort here maybe?
}

bool TrophyCase::copyTrophy(const string& copyee)
{
	const Trophy* foundTrophy = findTrophy(copyee);
	bool success = false;

	if(foundTrophy != nullptr)
	{
		addTrophy(foundTrophy->getName(),
			foundTrophy->getLevel(),
			foundTrophy->getColor());

		success = true;
	}
	else
	{
		success = false;
	}

	return success;
}

bool TrophyCase::deleteTrophy(const string& toDelete)
{
	Trophy* found = findTrophy(toDelete);
	bool success = false;

	if(found != nullptr)
	{
		// Swap found trophy with the last one.
		std::swap(*found, *list[curPos]);

		// Pop the found trophy from the list.
		delete list[curPos];
		--curPos;

		success = true;

		// TODO: Sort maybe?
	}
	else
	{
		success = false;
	}

	return success;
}

bool TrophyCase::renameTrophy(const string& name,
	const string& fixedName)
{
	Trophy* found = findTrophy(name);
	bool success = false;

	if(found != nullptr)
	{
		found->setName(fixedName);

		success = true;
	}
	else
	{
		success = false;
	}

	return success;
}

bool TrophyCase::relevelTrophy(const string& name,
	int fixedLevel)
{
	Trophy* found = findTrophy(name);
	bool success = false;

	if(found != nullptr)
	{
		found->setLevel(fixedLevel);

		success = true;
	}
	else
	{
		success = false;
	}

	return success;
}

bool TrophyCase::recolorTrophy(const string& name,
	Color fixedCol)
{
	Trophy* match = findTrophy(name);
	bool success = false;

	if(match != nullptr)
	{
		match->setColor(fixedCol);

		success = true;
	}
	else
	{
		success = false;
	}

	return success;
}

int TrophyCase::getNbrOfTrophies() const
{
	return curPos;
}

int TrophyCase::getAllocatedSize() const
{
	return capacity;
}

Trophy* TrophyCase::findTrophy(const string& name)
{
	Trophy* result = nullptr;

	for(int i = 0; i < curPos; ++i)
	{
		Trophy* curTrophy = list[i];

		if(curTrophy->getName() == name)
		{
			result = curTrophy;
		}
	}

	return result;
}
