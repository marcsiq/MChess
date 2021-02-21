/*
  ==============================================================================

    King.cpp
    Created: 20 Feb 2021 1:35:12pm
    Author:  marcs

  ==============================================================================
*/

#include <JuceHeader.h>
#include "King.h"

//==============================================================================
King::King(Colour colour)
    :PieceBase("King", colour)
{

}

King::~King()
{
}

void King::paint (juce::Graphics& g)
{
    auto b = getLocalBounds();
    b.reduce(20, 10);
    g.setColour(getSquareColour(getPieceColour()));
    g.fillRoundedRectangle(b.toFloat(), 10.0f);
    g.setColour(juce::Colours::blue);
    g.drawRoundedRectangle(b.toFloat(), 10.0f, 3.0f);
    g.drawSingleLineText("K", b.getCentreX() - 5, b.getCentreY());
}

void King::resized()
{
    repaint();
}

juce::Array<Location> King::getValidMoves(Board board)
{
    juce::Array<Location> moves;
    auto current = currentSquare->getLocation();
    moves.add(currentSquare->getLocation());
    return moves;
}
