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

private:
    File file;
    Rank rank;
};