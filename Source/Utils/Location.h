/*
  ==============================================================================

	Location.h
	Created: 20 Feb 2021 11:14:39am
	Author:  marcs

  ==============================================================================
*/

#pragma once
#include "Enums.h"

class Location
{
public:
	Location(File mFile, Rank mRank)
		: file(mFile), rank(mRank)
	{
	}

	File getFile() const
	{
		return file;
	}

	Rank getRank() const
	{
		return rank;
	}

	juce::String toString() const
	{
		return fileToString[file] + rankToString[rank];
	}

	bool isValid() const
	{
		return valid;
	}

	friend bool operator==(const Location& l, const Location& r) {
		return (l.file == r.file) && (l.rank == r.rank);
	}

	friend bool operator!=(const Location& lhs, const Location& rhs) {
		return !(lhs == rhs);
	}

	Location withOffset(int fileOffset, int rankOffset) const
	{
		int newFile = fileOffset + (int)file;
		int newRank = rankOffset + (int)rank;

		Location l((File)newFile, (Rank)newRank);

		if (newFile < 0 || newFile >= 8 || newRank < 0 || newRank >= 8)
		{
			l.valid = false;
		}

		return l;
	}

private:
	File file;
	Rank rank;
	bool valid = true;
};