#include "BoardState.cpp"

using namespace std;

class TicTacToe {
private:
    BoardState board;

public:
    TicTacToe();
    BoardState next_move_player(int move_position);
    BoardState next_move_computer(int move_position);
    int is_over();

};

TicTacToe::TicTacToe() {

};

BoardState TicTacToe::next_move_player(int move_position) {

    return BoardState();
};

BoardState TicTacToe::next_move_computer(int move_position) {

    return BoardState();
};

int TicTacToe::is_over() {

    return 0;
}
