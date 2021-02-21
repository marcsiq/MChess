#pragma once

#include <JuceHeader.h>
#include "Board/Board.h"
#include "Pieces/Pieces.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::Component
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    //==============================================================================
    // Your private member variables go here...
    Board board;
    Rook rw1{ Colour::WHITE };
    Rook rw2{ Colour::WHITE };
    Rook rb1{ Colour::BLACK };
    Rook rb2{ Colour::BLACK };
    Bishop bw1{ Colour::WHITE };
    Bishop bw2{ Colour::WHITE };
    Bishop bb1{ Colour::BLACK };
    Bishop bb2{ Colour::BLACK };
    Knight knw1{ Colour::WHITE };
    Knight knw2{ Colour::WHITE };
    Knight knb1{ Colour::BLACK };
    Knight knb2{ Colour::BLACK };
    King kb{ Colour::BLACK };
    King kw{ Colour::WHITE };
    Queen qb{ Colour::BLACK };
    Queen qw{ Colour::WHITE };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
