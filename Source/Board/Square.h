/*
  ==============================================================================

    Square.h
    Created: 20 Feb 2021 11:10:12am
    Author:  marcs

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "../Utils/Enums.h"
#include "../Utils/Location.h"

class PieceBase;

class Square : public juce::Component
{
public:
    //==============================================================================
    Square(Colour mcolour, Location mLocation);
    Square(const Square& other);
    ~Square();

    Square& operator=(const Square& other);

    //==============================================================================

    bool isOccupied(void);
    Colour getColour(void);
    Location getLocation(void);
    void setCurrentPiece(PieceBase* piece);

    //==============================================================================

    void reset();
    juce::String toString();

    //==============================================================================
    void paint(juce::Graphics& g) override;
    void resized() override;

private:
    Colour colour;
    Location location;
    PieceBase* currentPiece;

    JUCE_LEAK_DETECTOR(Square)
};
