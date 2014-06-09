#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <math.h>

#include "MinMax.cpp"
using namespace std;

class TicTacToe {
private:
    vector<int> board;

public:
    TicTacToe();
    void start();
    void next_move_player();
    void next_move_computer();
    int is_over();

};

TicTacToe::TicTacToe() {
    this->board = {0,0,0,0,0,0,0,0,0};
}

void TicTacToe::next_move_player() {

    int move;

    cout << "Set your move: ";
    cin >> move;

    BoardState aux (this->board, 0);
    aux.setMove(move, 1);
    this->board = aux.getBoard();

}

void TicTacToe::next_move_computer() {
    MinMax minmax;

    BoardState move = minmax.teste(this->board, 0, false);
    this->board = move.getBoard();
}


void TicTacToe::start(){
	cout << "starting tic tac toe..." <<endl;

    int who_plays = 1;
    for(int i=1; i < 10; i++)
    {
        if (who_plays == 1) {
            this->next_move_player();
            BoardState aux (this->board, 0);
            aux.printBoard();
            cout << endl;
            who_plays = 2;
        } else {
            this->next_move_computer();
            BoardState aux (this->board, 0);
            aux.printBoard();
            cout << endl;
            who_plays = 1;
        }
    }

}
