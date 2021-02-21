/*
  ==============================================================================

    Pawn.cpp
    Created: 20 Feb 2021 1:35:12pm
    Author:  marcs

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Pawn.h"

//==============================================================================
Pawn::Pawn(Colour colour)
    :PieceBase("Pawn", colour)
{
    isFirstMove = true;
}

Pawn::~Pawn()
{
}

void Pawn::paint (juce::Graphics& g)
{

}

void Pawn::resized()
{

}

juce::Array<Location> Pawn::getValidMoves(Board board)
{
    auto current = getCurrentSquare().getLocation();
    juce::Array<Location> moves;
    return moves;
}
