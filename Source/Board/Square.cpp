/*
  ==============================================================================

	Square.cpp
	Created: 20 Feb 2021 11:10:12am
	Author:  marcs

  ==============================================================================
*/

#include "Square.h"
#include "../Pieces/PieceBase.h"
#include "../Game.h"

Square::Square(Colour mcolour, Location mLocation)
	: colour(mcolour), location(mLocation), currentPiece(nullptr), isTarget(false), isDragging(false)
{
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
	currentPiece = nullptr;
	repaint();
}

bool Square::isOccupied(void) const
{
	return currentPiece != nullptr;
}

Colour Square::getColour(void) const
{
	return colour;
}

Location Square::getLocation(void) const
{
	return location;
}

void Square::setCurrentPiece(PieceBase* piece)
{
	if (isOccupied())
	{
		currentPiece->capture();
		currentPiece = nullptr;
	}
	currentPiece = piece;
	currentPiece->setVisible(true);
	currentPiece->toFront(false);
	resized();
}

PieceBase* Square::getCurrentPiece(void) const
{
	return currentPiece;
}

juce::String Square::toString() const
{
	juce::String text;
	text << "Square{";
	text << " Colour=" << colourToString.at(colour);
	text << " Location=" << location.toString();
	text << " Piece=" << (isOccupied() ? currentPiece->toString() : "NONE");
	text << " }";
	return text;
}

void Square::paint(juce::Graphics& g)
{
	auto b = getLocalBounds().toFloat();

	g.fillAll(colourToColour.at(colour));
	g.setColour(juce::Colours::white.darker());
	g.drawSingleLineText(location.toString(), b.toNearestInt().getX(), b.toNearestInt().getY() + 10, juce::Justification::left);

	if (isTarget)
	{
		if (isDragging)
		{
			g.drawRect(b, 6.0f);
		}

		if (isOccupied())
		{
			g.drawEllipse(b.reduced(10), 10.0f);
		}
		else
		{
			g.fillEllipse(b.reduced(30));
		}
	}
}

void Square::resized()
{
	if (isOccupied())
	{
		currentPiece->setBounds(getBounds());
	}
}

bool Square::isInterestedInDragSource(const juce::DragAndDropTarget::SourceDetails&)
{
	return true;
}

void Square::itemDragEnter(const juce::DragAndDropTarget::SourceDetails&)
{
	if (isTarget)
	{
		isDragging = true;
		repaint();
	}
}

void Square::itemDragMove(const juce::DragAndDropTarget::SourceDetails&)
{
}

void Square::itemDragExit(const juce::DragAndDropTarget::SourceDetails&)
{
	if (isTarget)
	{
		isDragging = false;
		repaint();
	}
}

void Square::itemDropped(const juce::DragAndDropTarget::SourceDetails& dragSourceDetails)
{
	if (isTarget)
	{
		auto piece = ((PieceBase*)dragSourceDetails.sourceComponent.get());
		getGame()->makeMove(piece, this);
		isTarget = false;
		isDragging = false;
	}
	auto board = (Board*)getParentComponent();
	board->noPieceMoving();
}

void Square::setTarget(bool target)
{
	if (isTarget != target)
	{
		isTarget = target;
		repaint();
	}
}