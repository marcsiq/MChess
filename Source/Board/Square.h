/*
  ==============================================================================

	Square.h
	Created: 20 Feb 2021 11:10:12am
	Author:  marcs

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "../Utils/Enums.h"
#include "../Utils/Location.h"

class PieceBase;

class Square : public juce::Component,
	public juce::DragAndDropTarget
{
public:
	//==============================================================================
	Square(Colour mcolour, Location mLocation);
	Square(const Square& other);
	~Square();

	Square& operator=(const Square& other);

	//==============================================================================

	bool isOccupied(void) const;
	Colour getColour(void) const;
	Location getLocation(void) const;
	void setCurrentPiece(PieceBase* piece);
	PieceBase* getCurrentPiece(void) const;

	//==============================================================================

	void reset();
	juce::String toString() const;
	void setTarget(bool isTarget);

	//==============================================================================
	void paint(juce::Graphics& g) override;
	void resized() override;
	//==============================================================================
	bool isInterestedInDragSource(const juce::DragAndDropTarget::SourceDetails& dragSourceDetails) override;
	void itemDragEnter(const juce::DragAndDropTarget::SourceDetails& dragSourceDetails) override;
	void itemDragMove(const juce::DragAndDropTarget::SourceDetails& dragSourceDetails) override;
	void itemDragExit(const juce::DragAndDropTarget::SourceDetails& dragSourceDetails) override;
	void itemDropped(const juce::DragAndDropTarget::SourceDetails& dragSourceDetails) override;

private:
	Colour colour;
	Location location;
	PieceBase* currentPiece;
	bool isTarget;
	bool isDragging;

	JUCE_LEAK_DETECTOR(Square)
};
