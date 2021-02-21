/*
  ==============================================================================

    Square.cpp
    Created: 20 Feb 2021 11:10:12am
    Author:  marcs

  ==============================================================================
*/

#include "Square.h"
#include "../Pieces/PieceBase.h"

Square::Square(Colour mcolour, Location mLocation)
    : colour(mcolour), location(mLocation)
{
    //setRepaintsOnMouseActivity(true);
    currentPiece = nullptr;
}

Square::Square(const Square& other)
    : Square(other.colour, other.location)
{
 
}

Square::~Square()
{
    currentPiece = nullptr;
}

Square& Square::operator=(const Square& other)
{
    // Guard self assignment
    if (this == &other)
        return *this;

    this->location = other.location;
    this->colour = other.colour;
    this->currentPiece = other.currentPiece;

    return *this;
}

void Square::reset()
{
    //currentPiece = nullptr;
}

bool Square::isOccupied(void)
{
    return currentPiece != nullptr;
}

Colour Square::getColour(void)
{
    return colour;
}

Location Square::getLocation(void)
{
    return location;
}

void Square::setCurrentPiece(PieceBase* piece)
{
    currentPiece = piece;
    currentPiece->setCurrentSquare(this);
    resized();
}

juce::String Square::toString()
{
    juce::String text;
    text << "Square{";
    text << " Colour=" << colourToString[colour];
    text << " Location=" << location.toString();
    text << " Piece=" << (isOccupied() ? currentPiece->toString() : "NONE");
    text << " }";
    return text;
}

void Square::paint(juce::Graphics& g)
{
    g.fillAll(getSquareColour(colour));
    g.setColour(getSquareColour((colour == Colour::WHITE ? Colour::BLACK : Colour::WHITE)));
    g.drawSingleLineText(location.toString(), getLocalBounds().getX(), getLocalBounds().getY() + 10, juce::Justification::left);

}

void Square::resized()
{
    if (isOccupied())
    {
        currentPiece->setBounds(getBounds());
    }
}