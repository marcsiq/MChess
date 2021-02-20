/*
  ==============================================================================

    Square.cpp
    Created: 20 Feb 2021 11:10:12am
    Author:  marcs

  ==============================================================================
*/

#include "Square.h"

Square::Square(Colour mcolour, Location mLocation, bool occupied)
    : colour(mcolour), location(mLocation), isOccupied(occupied)
{
    setRepaintsOnMouseActivity(true);
}

Square::Square(const Square& other)
    : Square(other.colour, other.location, other.isOccupied)
{
 
}

void Square::reset()
{
    isOccupied = false;
}

bool Square::getOccupied(void)
{
    return isOccupied;
}

void Square::setOccupied(bool occupied)
{
    isOccupied = occupied;
}

Colour Square::getColour(void)
{
    return colour;
}

Location Square::getLocation(void)
{
    return location;
}

juce::String Square::toString()
{
    juce::String text;
    text << "Square{";
    text << " Colour=" << colourToString[colour];
    text << " Location=" << location.toString();
    text << " isOccupied=" << juce::String((int)isOccupied);
    text << " }";
    return text;
}

void Square::paint(juce::Graphics& g)
{
    g.fillAll(getSquareColour(colour).interpolatedWith(juce::Colours::red, isMouseOver() ? 0.5f: 0.0f));
    g.setColour(getSquareColour((colour == Colour::WHITE ? Colour::BLACK : Colour::WHITE)));
    int offset = 10;
    g.drawSingleLineText(location.toString(), getLocalBounds().getX(), getLocalBounds().getY() + offset, juce::Justification::left);
}

void Square::resized()
{

}