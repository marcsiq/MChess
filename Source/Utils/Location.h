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

    File getFile()
    {
        return file;
    }

    Rank getRank()
    {
        return rank;
    }

    juce::String toString()
    {
        return fileToString[file] + rankToString[rank];
    }

    friend bool operator==(const Location& l, const Location& r) {
        return (l.file == r.file) && (l.rank == r.rank);
    }

    friend bool operator!=(const Location& lhs, const Location& rhs) {
        return !(lhs == rhs);
    }

    Location withOffset(int fileOffset, int rankOffset)
    {
        int newFile = std::max(0, std::min(BOARD_LENGTH-1, fileOffset + (int)file));
        int newRank = std::max(0, std::min(BOARD_LENGTH-1, rankOffset + (int)rank));
        Location l((File)newFile, (Rank)newRank);
        return l;
    }

private:
    File file;
    Rank rank;
};