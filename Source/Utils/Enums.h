/*
  ==============================================================================

    Enums.h
    Created: 20 Feb 2021 11:11:13am
    Author:  marcs

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

#define BOARD_LENGTH (8)

enum class Colour
{
    WHITE,
    BLACK,
};

static std::map<Colour, juce::String> colourToString = {
    {Colour::WHITE, "White"},
    {Colour::BLACK, "Black"},
};

static juce::Colour getSquareColour(Colour colour)
{
    switch (colour)
    {
    case Colour::WHITE:
        return juce::Colours::white.interpolatedWith(juce::Colours::lawngreen, 0.1f);
    case Colour::BLACK:
        return juce::Colours::black.interpolatedWith(juce::Colours::lawngreen, 0.6f);
    }
}

enum class File
{
    A,
    B,
    C,
    D,
    E,
    F,
    G,
    H,
};

static std::map<File, juce::String> fileToString = {
    {File::A, "a"},
    {File::B, "b"},
    {File::C, "c"},
    {File::D, "d"},
    {File::E, "e"},
    {File::F, "f"},
    {File::G, "g"},
    {File::H, "h"},
};

enum class Rank
{
    _1,
    _2,
    _3,
    _4,
    _5,
    _6,
    _7,
    _8,
};

static std::map<Rank, juce::String> rankToString = {
    {Rank::_1, "1"},
    {Rank::_2, "2"},
    {Rank::_3, "3"},
    {Rank::_4, "4"},
    {Rank::_5, "5"},
    {Rank::_6, "6"},
    {Rank::_7, "7"},
    {Rank::_8, "8"},
};