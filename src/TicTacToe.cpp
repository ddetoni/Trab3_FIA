#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <math.h>

#include "MinMax.cpp"
using namespace std;

class TicTacToe {
private:
    BoardState board;

public:
    TicTacToe(vector<int> array);
    void start();
    void next_move_player();
    void next_move_computer();
    int is_over();

};

TicTacToe::TicTacToe(vector<int> array) {
	this->board (array, 0);
};

void TicTacToe::next_move_player() {

    int move;

    cout << "Set your move: ";
    cin >> move;

    this->board.setMove(move, 1);

}

void TicTacToe::next_move_computer() {
    MinMax minmax;

    move = minmax.teste(this->board.getBoard(), 0, false);
    this->board.setBoard(move.getBoard());
}


void TicTacToe::start(){
	cout << "starting tic tac toe..." <<endl;

    int who_plays = 1;
    for(int i=1; i < 10; i++)
    {
        if (who_plays == 1) {
            this->next_move_player();
            this->board.printBoard();
            who_plays = 2;
        } else {
            this->next_move_computer();
            this->board.printBoard();
            who_plays = 1;
        }
    }

}
