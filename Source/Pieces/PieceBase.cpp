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
#include "../Game.h"

//==============================================================================
PieceBase::PieceBase(juce::String name, Colour colour, int value)
	:colour(colour), name(name), value(value)
{
	currentSquare = nullptr;
	isDragging = false;
	movedBefore = false;
	beenCaptured = false;
}

PieceBase::PieceBase(const PieceBase& other)
	:PieceBase(other.name, other.colour, other.value)
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

void PieceBase::setStartingSquare(Square* square)
{
	setVisible(true);
	currentSquare = square;
	movedBefore = false;
	beenCaptured = false;
}

void PieceBase::moveToSquare(Square* square)
{
	currentSquare = square;
	currentSquare->setCurrentPiece(this);
	movedBefore = true;
}

bool PieceBase::hasMovedBefore()
{
	return movedBefore;
}

bool PieceBase::hasBeenCaptured()
{
	return beenCaptured;
}

void PieceBase::capture()
{
	beenCaptured = true;
	setVisible(false);
}

int PieceBase::getPieceValue()
{
	return value;
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
	if (!isDragging)
	{
		g.setImageResamplingQuality(juce::Graphics::highResamplingQuality);
		g.drawImage(pieceImg, getLocalBounds().toFloat(), juce::RectanglePlacement(juce::RectanglePlacement::fillDestination));
	}
}

void PieceBase::resized()
{
	repaint();
}

juce::MouseCursor PieceBase::getMouseCursor()
{
	return juce::MouseCursor::DraggingHandCursor;
}

void PieceBase::mouseDrag(const juce::MouseEvent&)
{
	if (getGame()->getCurrentPlayer() == getPieceColour())
	{
		getGame()->getBoard()->pieceMoving(this);
	}
	isDragging = true;
}

void PieceBase::mouseUp(const juce::MouseEvent&)
{
	isDragging = false;
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