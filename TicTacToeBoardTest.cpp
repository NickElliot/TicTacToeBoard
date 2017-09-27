/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(TicTacToeBoardTest, tToggleTurn){
	TicTacToeBoard testboard;
	testboard.toggleTurn();
	ASSERT_TRUE(testboard.toggleTurn() == X);
	ASSERT_TRUE(testboard.toggleTurn() == O);
	
}

/* 
	*BUG: If you place a piece on a spot where there is already a piece it should return the piece already w/ no change to game state
	*My implementation will toggle the player turn even if the attempted placement fails due to an existing piece.
	*My test catches this bug by making sure the turn does not toggle on duplicate placement (lines 36-39)
*/

TEST(TicTacToeBoardTest, tPlacePiece){
	TicTacToeBoard testboard;
	ASSERT_TRUE(testboard.placePiece(2,3) == Invalid);
	ASSERT_TRUE(testboard.placePiece(3,2) == Invalid);
	ASSERT_TRUE(testboard.placePiece(0,0) == X);
	ASSERT_TRUE(testboard.placePiece(1,1) == O);
	ASSERT_TRUE(testboard.placePiece(0,0) == X);
	ASSERT_TRUE(testboard.placePiece(0,1) == X);
	ASSERT_TRUE(testboard.placePiece(1,2) == O);
	ASSERT_TRUE(testboard.placePiece(0,2) == X);
	ASSERT_TRUE(testboard.placePiece(1,2) == Blank);
}
Test(TicTacToeBoard, tGetPiece){
	TicTacToeBoard testboard;
	ASSERT_TRUE(testboard.getPiece(2,3) == Invalid);
	ASSERT_TRUE(testboard.getPiece(3,2) == Invalid);
	ASSERT_TRUE(testboard.getPiece(0,0) == Blank);
	testboard.placePiece(0,0);
	ASSERT_TRUE(testboard.getPiece(0,0) == X);
}
Test(TicTacToeBoardTest.tGetWinner){
	TicTacToeBoard testboardX;
	ASSERT_TRUE(testboardX.getWinner == Invalid);
	testboardX.placePiece(0,0);
	testboardX.toggleTurn();
	testboardX.placePiece(0,1);
	testboardX.toggleTurn();
	testboardX.placePiece(0,2);
	testboardX.toggleTurn();
	ASSERT_TRUE(testboardX.getWinner == X);
	TicTacToeBoard testboardO;
	ASSERT_TRUE(testboardO.getWinner == Invalid);
	testboardO.toggleTurn();
	testboardO.placePiece(0,0);
	testboardO.toggleTurn();
	testboardO.placePiece(0,1);
	testboardO.toggleTurn();
	testboardO.placePiece(0,2);
	testboardO.toggleTurn();
	ASSERT_TRUE(testboardO.getWinner == O);
	
	TicTacToeBoard testboard2X;
	ASSERT_TRUE(testboard2X.getWinner == Invalid);
	testboard2X.placePiece(0,0);
	testboard2X.toggleTurn();
	testboard2X.placePiece(1,0);
	testboard2X.toggleTurn();
	testboard2X.placePiece(2,0);
	testboard2X.toggleTurn();
	ASSERT_TRUE(testboard2X.getWinner == X);
	TicTacToeBoard testboard2O;
	ASSERT_TRUE(testboard2O.getWinner == Invalid);
	testboard2O.toggleTurn();
	testboard2O.placePiece(0,0);
	testboard2O.toggleTurn();
	testboard2O.placePiece(1,0);
	testboard2O.toggleTurn();
	testboard2O.placePiece(2,0);
	testboard2O.toggleTurn();
	ASSERT_TRUE(testboard2O.getWinner == O);
	
	
	TicTacToeBoard testboardX3;
	ASSERT_TRUE(testboardX3.getWinner == Invalid);
	testboardX3.placePiece(0,0);
	testboardX3.toggleTurn();
	testboardX3.placePiece(1,1);
	testboardX3.toggleTurn();
	testboardX3.placePiece(2,2);
	testboardX3.toggleTurn();
	ASSERT_TRUE(testboardX3.getWinner == X);
	TicTacToeBoard testboardO3;
	ASSERT_TRUE(testboardO3.getWinner == Invalid);
	testboardO3.toggleTurn();
	testboardO3.placePiece(0,0);
	testboardO3.toggleTurn();
	testboardO3.placePiece(1,1);
	testboardO3.toggleTurn();
	testboardO3.placePiece(2,2);
	testboardO3.toggleTurn();
	ASSERT_TRUE(testboardO3.getWinner == O);
	
	TicTacToeBoard testboardX4;
	ASSERT_TRUE(testboardX4.getWinner == Invalid);
	testboardX4.placePiece(0,0);
	testboardX4.toggleTurn();
	testboardX4.placePiece(1,1);
	testboardX4.toggleTurn();
	testboardX4.placePiece(2,2);
	testboardX4.toggleTurn();
	ASSERT_TRUE(testboardX4.getWinner == X);
	TicTacToeBoard testboardO4;
	ASSERT_TRUE(testboardO4.getWinner == Invalid);
	testboardO4.toggleTurn();
	testboardO4.placePiece(0,2);
	testboardO4.toggleTurn();
	testboardO4.placePiece(1,1);
	testboardO4.toggleTurn();
	testboardO4.placePiece(2,0);
	testboardO4.toggleTurn();
	ASSERT_TRUE(testboardO4.getWinner == O);
}
