/*
  ==============================================================================

    PieceBase.h
    Created: 20 Feb 2021 1:21:10pm
    Author:  marcs

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "../Utils/Enums.h"
#include "../Board/Square.h"

class Board; // Forward declaration

//==============================================================================
/*
*/
class PieceBase  : public juce::Component,
                   public juce::DragAndDropTarget
{
public:
    PieceBase(juce::String name, Colour colour);
    PieceBase(const PieceBase& other);
    ~PieceBase() override;

    Colour getPieceColour();
    juce::String getName();
    Square* getCurrentSquare();
    void setCurrentSquare(Square* square);

    juce::String PieceBase::toString();

    void paint(juce::Graphics& g) override;
    void resized() override;

    juce::MouseCursor getMouseCursor() override;

    void mouseDrag(const juce::MouseEvent& event) override;
    void mouseUp(const juce::MouseEvent& event) override;

    bool isInterestedInDragSource(const juce::DragAndDropTarget::SourceDetails& dragSourceDetails) override;
    void itemDragEnter(const juce::DragAndDropTarget::SourceDetails& dragSourceDetails) override;
    void itemDragMove(const juce::DragAndDropTarget::SourceDetails& dragSourceDetails) override;
    void itemDragExit(const juce::DragAndDropTarget::SourceDetails& dragSourceDetails) override;
    void itemDropped(const juce::DragAndDropTarget::SourceDetails& dragSourceDetails) override;

    virtual juce::Array<Location> getValidMoves(Board* board);

protected:
    Colour colour;
    juce::Image pieceImg;
    Square* currentSquare;
    juce::String name;

    JUCE_LEAK_DETECTOR(PieceBase)
};
