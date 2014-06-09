#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <math.h>

//#include "BoardState.cpp"
#include "MinMax.cpp"
using namespace std;

class TicTacToe {
private:
    BoardState board(vector<int> b);

public:
    TicTacToe(vector<int> array);
    void start();
  //  BoardState next_move_player(int move_position);
  //  BoardState next_move_computer(int move_position);
    int is_over();

};

TicTacToe::TicTacToe(vector<int> array) {
	BoardState board(array,0);
};

/*BoardState TicTacToe::next_move_player(int move_position) {

    return BoardState(0);
};

BoardState TicTacToe::next_move_computer(int move_position) {

    return BoardState(0);
};
*/
int TicTacToe::is_over() {

    return 0;
}



void TicTacToe::start(){
	cout << "starting tic tac toe..." <<endl;
	MinMax minmax;
	vector<BoardState> next;
	//vector<int>board = {1,2,2,2,1,1,0,0,0};
	vector<int>board = {2,1,2,1,1,2,0,0,0};
	vector<int>aux = {0,0,0,0,0,0,0,0,0};
	BoardState b (board, 0);
	

	
	
	BoardState move(aux,0);
	cout << "INITIAL STATE" <<endl <<endl;
	
	//b.printBoard();
	move = minmax.teste(b.getBoard(), 1, true);
	
//	next = b.get_nexts(1);
	
	for (int i = 0 ; i < next.size() ; i++){
	//	next[i].printBoard();
		}
	
	//next[1].printBoard();
	//cout << endl << next[1].isOver();
	
	cout << endl << endl <<endl<<"move: ";
	cout <<move.getValue();
	move.printBoard();
	
	

	
	
	
}


