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

class Square : public juce::Component
{
public:
    //==============================================================================
    Square(Colour mcolour, Location mLocation, bool occupied);
    Square(const Square& other);

    Square& operator=(const Square& other);

    //==============================================================================

    bool getOccupied(void);
    void setOccupied(bool occupied);
    Colour getColour(void);
    Location getLocation(void);

    //==============================================================================

    void reset();
    juce::String toString();

    //==============================================================================
    void paint(juce::Graphics& g) override;
    void resized() override;

private:
    Colour colour;
    Location location;
    bool isOccupied;

    JUCE_LEAK_DETECTOR(Square)
};
