#include "TrophyCase.h"
#include <algorithm>

TrophyCase::TrophyCase()
	:
	m_trophies(new Trophy*[startSize])
{}

TrophyCase::TrophyCase(const TrophyCase& rhs)
	:
	m_trophies(new Trophy*[rhs.m_capacity]),
	m_capacity(rhs.m_capacity),
	m_nbrOfTrophies(rhs.m_nbrOfTrophies)
{
	for(int i = 0; i < m_nbrOfTrophies; ++i)
	{
		m_trophies[i] = new Trophy(*rhs.m_trophies[i]);
	}
}

TrophyCase& TrophyCase::operator=(const TrophyCase& rhs)
{
	// Free my memory.
	for(int i = 0; i < m_nbrOfTrophies; ++i)
	{
		delete m_trophies[i];
	}

	delete m_trophies;

	// Create a new list and copy entries over.
	m_trophies = new Trophy*[rhs.m_capacity];
	for(int i = 0; i < m_nbrOfTrophies; ++i)
	{
		m_trophies[i] = new Trophy(*rhs.m_trophies[i]);
	}

	return *this;
}

TrophyCase::~TrophyCase()
{
	for(int i = 0; i < m_nbrOfTrophies; ++i)
	{
		delete m_trophies[i];
	}

	delete m_trophies;
}

void TrophyCase::addTrophy(const string& name, int level,
	Color c)
{
	m_trophies[m_nbrOfTrophies++] = new Trophy(name, level, c);

	// We must reallocate!
	if(m_nbrOfTrophies >= m_capacity/*-1*/)
	{
		Trophy** trophies = nullptr;

		// Add 10% extra capacity.
		m_capacity = int(float(m_capacity) * 1.1f);
		trophies = new Trophy*[m_capacity];

		// Move each list item then get rid of it.
		for(int i = 0; i < m_nbrOfTrophies; ++i)
		{
			trophies[i] = m_trophies[i];
			delete m_trophies[i];
		}
		delete m_trophies;

		// Assign list to trophies.
		m_trophies = trophies;
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
		std::swap(*found, *m_trophies[m_nbrOfTrophies]);

		// Pop the found trophy from the list.
		delete m_trophies[m_nbrOfTrophies];
		--m_nbrOfTrophies;

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
	return m_nbrOfTrophies;
}

int TrophyCase::getAllocatedSize() const
{
	return m_capacity;
}

Trophy* TrophyCase::findTrophy(const string& name)
{
	Trophy* result = nullptr;

	for(int i = 0; i < m_nbrOfTrophies; ++i)
	{
		Trophy* curTrophy = m_trophies[i];

		if(curTrophy->getName() == name)
		{
			result = curTrophy;
		}
	}

	return result;
}

void TrophyCase::insertionSort()
{
	Trophy* value;
	int j;

	for(int i = 1; i < m_nbrOfTrophies; ++i)
	{
		value = m_trophies[i];
		j = i - 1;

		while(j >= 0 && *m_trophies[j] > *value)
		{
			m_trophies[j + 1] = m_trophies[j];
			--j;
		}

		m_trophies[j + 1] = value;
	}
}

ostream& operator<<(ostream& lhs,
	const TrophyCase& rhs)
{
	for(int i = 0; i < rhs.m_nbrOfTrophies; ++i)
	{
		lhs << *rhs.m_trophies[i] << endl;
	}

	return lhs;
}
