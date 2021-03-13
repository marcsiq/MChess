/*
  ==============================================================================

    PieceBase.cpp
    Created: 20 Feb 2021 1:21:10pm
    Author:  marcs

  ==============================================================================
*/

#include <JuceHeader.h>
#include "PieceBase.h"
#include "../Board/Board.h"

//==============================================================================
PieceBase::PieceBase(juce::String name, Colour colour)
    :colour(colour), name(name)
{
    currentSquare = nullptr;
}

PieceBase::PieceBase(const PieceBase& other)
    :PieceBase(other.name, other.colour)
{
    currentSquare = other.currentSquare;
    pieceImg = other.pieceImg;
}

PieceBase::~PieceBase()
{
    currentSquare = nullptr;
}

Colour PieceBase::getPieceColour()
{
    return colour;
}

juce::String PieceBase::getName()
{
    return name;
}

Square* PieceBase::getCurrentSquare()
{
    return currentSquare;
}

void PieceBase::setCurrentSquare(Square* square)
{
    currentSquare = square;
}

juce::String PieceBase::toString()
{
    juce::String text;
    text << "Piece{";
    text << " Name=" << name;
    text << " Colour=" << colourToString[colour];
    text << " Square=" << (currentSquare == nullptr ? "null" : currentSquare->getLocation().toString());
    text << " }";
    return text;
}

void PieceBase::paint(juce::Graphics& g)
{
    g.setColour(juce::Colours::blue);
    //g.setImageResamplingQuality(juce::Graphics::highResamplingQuality);
    g.drawImage(pieceImg, getLocalBounds().toFloat(), juce::RectanglePlacement(juce::RectanglePlacement::fillDestination));
}

void PieceBase::resized()
{
    repaint();
}

juce::MouseCursor PieceBase::getMouseCursor()
{
    return juce::MouseCursor::DraggingHandCursor;
}

void PieceBase::mouseDrag(const juce::MouseEvent& event)
{
    auto board = (Board*) getParentComponent();
    if (board->getCurrentPlayer() == getPieceColour())
    {
        board->startDragging("PieceBase", this);
    }
}

void PieceBase::mouseUp(const juce::MouseEvent& event)
{
    repaint();
}

bool PieceBase::isInterestedInDragSource(const juce::DragAndDropTarget::SourceDetails& dragSourceDetails)
{
    return currentSquare->isInterestedInDragSource(dragSourceDetails);
}
void PieceBase::itemDragEnter(const juce::DragAndDropTarget::SourceDetails& dragSourceDetails)
{
    currentSquare->itemDragEnter(dragSourceDetails);
}
void PieceBase::itemDragMove(const juce::DragAndDropTarget::SourceDetails& dragSourceDetails)
{
    currentSquare->itemDragMove(dragSourceDetails);
}
void PieceBase::itemDragExit(const juce::DragAndDropTarget::SourceDetails& dragSourceDetails)
{
    currentSquare->itemDragExit(dragSourceDetails);
}
void PieceBase::itemDropped(const juce::DragAndDropTarget::SourceDetails& dragSourceDetails)
{
    currentSquare->itemDropped(dragSourceDetails);
}