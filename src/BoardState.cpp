#include <cstdlib>
#include <iostream>


#include <vector>

using namespace std;

class BoardState {
private:
    vector<int> board;
    int depth;
    int value;

public:
    BoardState(vector<int> b, int v);
    vector<BoardState> get_nexts(int id);
    int printBoard();
	int checkWinner(); //0 = no winner ; 1 = player 1 won ; 2 = player 2 won
	vector<int> getBoard();
	void setValue(int value);
	void setVector(vector<int> b);
	int getValue();
	int getElement(int index);
	bool isOver();
	int Evaluate();
};

BoardState::BoardState(vector<int> b, int v) {
    this->board = b;
    this->value = v;
}

int BoardState::getElement(int index){
	return this->board[index];
	}
	
int BoardState::getValue(){
	return this->value;
	}

void BoardState::setVector(vector<int> b){
		this->board = b;
	}

void BoardState::setValue(int value){
	this->value = value;
	}
	
vector<int> BoardState::getBoard(){
	//vector<int> aux = this.board;
//return aux;
	return board;
	}

//argument should be a player id
vector<BoardState> BoardState::get_nexts(int id) {
    //Retorna os próximos estados.
    //Percorrer board, se vazio então copiar board e alterar a posição em questao.
    vector<BoardState> list_board; //list of next states
    vector<int> aux_board;
    
    for (int i = 0 ; i < 9 ; i++){
		aux_board = this->board;
		if (this->board[i] == 0){
			aux_board[i] = id;
			BoardState aux = BoardState(aux_board,0);
			list_board.push_back(aux);
		}
	
	}
	return list_board;
    
}

int BoardState::printBoard(){
	for ( int i = 0 ; i < 9 ; i++){
		if(i % 3 == 0){
			cout << endl;
		}
		if(board[i] == 0){
			cout << " - ";
		}
		if(board[i] == 1){
			cout << " X ";
		}
		if(board[i] == 2){
			cout << " O ";
		}
	}
	
	return 0;
	}
	
int BoardState::checkWinner(){
	//int winner= 0;
	if((this->board[0] == this->board[1]) && (this->board[1] == this->board[2])){
		if(this->board[0] == 1)return 1;
		if(this->board[0] == 2)return 2;
		}
			
	if((this->board[3] == this->board[4]) && (this->board[4] == this->board[5])){
		if(this->board[3] == 1)return 1;
		if(this->board[3] == 2)return 2;
	}
	
	if((this->board[6] == this->board[7]) && (this->board[7] == this->board[8])){
		if(this->board[6] == 1)return 1;
		if(this->board[6] == 2)return 2;	
	}
	
	if((this->board[0] == this->board[3]) && (this->board[3] == this->board[6])){
		if(this->board[0] == 1)return 1;
		if(this->board[0] == 2)return 2;	
	}
	
	if((this->board[1] == this->board[4]) && (this->board[4] == this->board[7])){
		if(this->board[1] == 1)return 1;
		if(this->board[1] == 2)return 2;
	}
			
	if((this->board[2] == this->board[5]) && (this->board[5] == this->board[8])){
		if(this->board[2] == 1)return 1;
		if(this->board[2] == 2)return 2;
	}
			
	if((this->board[0] == this->board[4]) && (this->board[4] == this->board[8])){
		if(this->board[0] == 1)return 1;
		if(this->board[0] == 2)return 2;
	}
				
	if((this->board[2] == this->board[4]) && (this->board[4] == this->board[6])){
		if(this->board[2] == 1)return 1;
		if(this->board[2] == 2)return 2;
	}
	return 0;
	
}

bool BoardState::isOver(){

	if((this->checkWinner()==1) || (this->checkWinner()==2)){
		return true;
	}
	for (int i = 0 ; i < 9 ; i++){
		if(this->board[i] == 0){
			return false; //ha posicao vazia
		}
	}
	return true;
	
	
}

int BoardState::Evaluate(){ //retorna o vencedor, ou 0 para empate
	if (this->checkWinner() == 1){
		return 1;
		}else
			if (this->checkWinner() == 2){
				return 2;
				}else{
					return 0;
					}
		
	}
