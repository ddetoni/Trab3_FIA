#include <cstdlib>
#include <iostream>
#include <vector>
#include <stdlib.h>

#include "BoardState.cpp"
#include "TicTacToe.cpp"

using namespace std;

int main(int argc, char** argv) {



	vector<int>board = {1,0,1,2,1,0,2,1,2};
	//vector<int>board = {1,0,0,0,0,0,0,0,0};
	BoardState b (board, 0);
	//cout << b.isOver();
	//b.Evaluate();


	TicTacToe game(board);
	game.start();





    return 0;
}
