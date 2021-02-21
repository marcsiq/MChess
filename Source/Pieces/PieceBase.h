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

//==============================================================================
/*
*/
class PieceBase  : public juce::Component
{
public:
    PieceBase(juce::String name, Colour colour);
    PieceBase(const PieceBase& other);
    ~PieceBase() override;

    Colour getPieceColour();
    juce::String getName();
    Square getCurrentSquare();
    void setCurrentSquare(Square* square);
    juce::String PieceBase::toString();

    void paint(juce::Graphics& g) override;

protected:
    Colour colour;
    std::unique_ptr<Square> currentSquare;
    juce::String name;

    JUCE_LEAK_DETECTOR(PieceBase)
};
