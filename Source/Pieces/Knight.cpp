/*
  ==============================================================================

    Knight.cpp
    Created: 20 Feb 2021 1:35:12pm
    Author:  marcs

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Knight.h"

//==============================================================================
Knight::Knight(Colour colour)
    :PieceBase("Knight", colour)
{

}

Knight::~Knight()
{
}

void Knight::paint (juce::Graphics& g)
{
    auto b = getLocalBounds();
    b.reduce(20, 10);
    g.setColour(getSquareColour(getPieceColour()));
    g.fillRoundedRectangle(b.toFloat(), 10.0f);
    g.setColour(juce::Colours::blue);
    g.drawRoundedRectangle(b.toFloat(), 10.0f, 3.0f);
    g.drawSingleLineText("KN", b.getCentreX() - 5, b.getCentreY());
}

void Knight::resized()
{
    repaint();
}

juce::Array<Location> Knight::getValidMoves(Board board)
{
    juce::Array<Location> moves;
    return moves;
}
