#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize (800, 800);
    addAndMakeVisible(board);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{

}

void MainComponent::resized()
{
    board.setBounds(getBounds());
}
