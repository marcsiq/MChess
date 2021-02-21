/*
  ==============================================================================

    Queen.cpp
    Created: 20 Feb 2021 1:35:12pm
    Author:  marcs

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Queen.h"

//==============================================================================
Queen::Queen(Colour colour)
    :PieceBase("Queen", colour)
{

}

Queen::~Queen()
{
}

void Queen::paint (juce::Graphics& g)
{
    auto b = getLocalBounds();
    b.reduce(20, 10);
    g.setColour(getSquareColour(getPieceColour()));
    g.fillRoundedRectangle(b.toFloat(), 10.0f);
    g.setColour(juce::Colours::blue);
    g.drawRoundedRectangle(b.toFloat(), 10.0f, 3.0f);
    g.drawSingleLineText("Q", b.getCentreX() - 5, b.getCentreY());
}

void Queen::resized()
{
    repaint();
}

juce::Array<Location> Queen::getValidMoves(Board board)
{
    juce::Array<Location> moves;
    return moves;
}
