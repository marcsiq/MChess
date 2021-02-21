#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize (800, 800);
    addAndMakeVisible(board);
    board.initBoard();
    board.getSquare(File::A, Rank::_1)->setCurrentPiece(&rw1);
    board.getSquare(File::H, Rank::_1)->setCurrentPiece(&rw2);
    board.getSquare(File::A, Rank::_8)->setCurrentPiece(&rb1);
    board.getSquare(File::H, Rank::_8)->setCurrentPiece(&rb2);

    board.getSquare(File::C, Rank::_1)->setCurrentPiece(&bw1);
    board.getSquare(File::F, Rank::_1)->setCurrentPiece(&bw2);
    board.getSquare(File::C, Rank::_8)->setCurrentPiece(&bb1);
    board.getSquare(File::F, Rank::_8)->setCurrentPiece(&bb2);

    board.getSquare(File::B, Rank::_1)->setCurrentPiece(&knw1);
    board.getSquare(File::G, Rank::_1)->setCurrentPiece(&knw2);
    board.getSquare(File::B, Rank::_8)->setCurrentPiece(&knb1);
    board.getSquare(File::G, Rank::_8)->setCurrentPiece(&knb2);

    board.getSquare(File::D, Rank::_1)->setCurrentPiece(&qw);
    board.getSquare(File::D, Rank::_8)->setCurrentPiece(&qb);

    board.getSquare(File::E, Rank::_1)->setCurrentPiece(&kw);
    board.getSquare(File::E, Rank::_8)->setCurrentPiece(&kb);

    board.printBoard();
    addAndMakeVisible(rw1);
    addAndMakeVisible(rw2);
    addAndMakeVisible(rb1);
    addAndMakeVisible(rb2);
    addAndMakeVisible(bw1);
    addAndMakeVisible(bw2);
    addAndMakeVisible(bb1);
    addAndMakeVisible(bb2);
    addAndMakeVisible(knw1);
    addAndMakeVisible(knw2);
    addAndMakeVisible(knb1);
    addAndMakeVisible(knb2);
    addAndMakeVisible(kb);
    addAndMakeVisible(kw);
    addAndMakeVisible(qb);
    addAndMakeVisible(qw);
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
