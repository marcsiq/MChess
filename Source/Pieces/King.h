/*
  ==============================================================================

    King.h
    Created: 20 Feb 2021 1:35:12pm
    Author:  marcs

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PieceBase.h"

//==============================================================================
/*
*/
class King  : public PieceBase
{
public:
    King(Colour colour);
    ~King() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (King)
};
