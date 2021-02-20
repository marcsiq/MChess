/*
  ==============================================================================

    PieceBase.cpp
    Created: 20 Feb 2021 1:21:10pm
    Author:  marcs

  ==============================================================================
*/

#include <JuceHeader.h>
#include "PieceBase.h"

//==============================================================================
PieceBase::PieceBase(juce::String name, Colour colour)
    :colour(colour), name(name)
{
    currentSquare = nullptr;
}

PieceBase::PieceBase(const PieceBase& other)
    :PieceBase(other.name, other.colour)
{
    currentSquare.reset(other.currentSquare.get());
}

PieceBase::~PieceBase()
{
    currentSquare.release();
}

Colour PieceBase::getPieceColour()
{
    return colour;
}

juce::String PieceBase::getName()
{
    return name;
}

Square PieceBase::getCurrentSquare()
{
    return *currentSquare;
}

void PieceBase::setCurrentSquare(Square* square)
{
    currentSquare.reset(square);
    DBG(toString());
}

void PieceBase::paint (juce::Graphics& g)
{

}

void PieceBase::resized()
{

}

juce::String PieceBase::toString()
{
    juce::String text;
    text << "Piece{";
    text << " Name=" << name;
    text << " Colour=" << colourToString[colour];
    text << " Square=" << (currentSquare == nullptr ? "null" : currentSquare->toString());
    text << " }";
    return text;
}
