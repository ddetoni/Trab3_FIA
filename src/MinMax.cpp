#include <cstdlib>
#include <iostream>

using namespace std;

class MinMax {

public:
	MinMax();
	BoardState teste(vector<int>board, int depth, bool playerOne);

};

MinMax::MinMax(){
	//contructor
	}
	
	
BoardState MinMax::teste(vector<int> board, int depth, bool playerOne){
	BoardState b (board, 0);
	if (depth == 9 || b.isOver()){ //todas as posicoes ocupados ou alguem ehvencedor
		if ((playerOne == true) && b.Evaluate() == 1){//se eh jogador 1 (atual) e ele eh o vencedor
			b.setValue(10-depth);
			return b;
			}else
				if ((playerOne == false) && b.Evaluate() == 2){//se eh o oponente e ele eh o vencedor
					b.setValue(depth-10);
					return b;
				}else{ //se nao ha vencedor
					b.setValue(0);
					return b;
					}
		}
	
	int bestValue;
	if(playerOne == true){
		bestValue = -10000;
		vector<BoardState> list_child;
		list_child = b.get_nexts(1);
		for (int i = 0 ; i < list_child.size() ; i++){
			b = this->teste(list_child[i].getBoard(), depth+1, false); //false faz o proximo nivel ser do adv
			if (b.getValue() > bestValue){ //se b é maior que o atual maior de todos os vizinhos
				b.setValue(bestValue); 
				}
			return b;
			}
				
		}
		else 
			{
			bestValue = 10000;
			vector<BoardState> list_child;
			list_child = b.get_nexts(2);
			for (int i = 0 ; i < list_child.size() ; i++){
				b = this->teste(list_child[i].getBoard(), depth+1, true); //false faz o proximo nivel ser do adv
				if (b.getValue() < bestValue){ //se b é maior que o atual maior de todos os vizinhos
					b.setValue(bestValue); 
					}
				return b;
				}
					
			}
			
		
	
		
	}	
	


	
	/*
BoardState MinMax::teste(vector<int> board, int depth, bool playerOne){
	BoardState b (board, 10000);
	if((depth == 9) || (b.checkWinner() == 1) || (b.checkWinner() == 2)){
			cout << "check" << b.checkWinner();
			if(b.checkWinner() == 0){ //draw
				b.setValue(0);
				//cout << "entrou no 0";
				cout << "0";
				b.printBoard();
				return b;
			}		
			if(b.checkWinner() == 1){ //player 1 won
				//cout << "1";
				//b.printBoard();
	
				
				if (playerOne == true ){
			
					 b.setValue(10-depth);
					 
					 }
				if (playerOne == false){
					 b.setValue(depth-10);
				}
				//cout << "entrou no 1";
				return b;
			
			if(b.checkWinner() == 2){ //player 1 won
			//	cout << "before set" << b.getValue();
				b.printBoard();
				cout << "2";
				if (playerOne == true )b.setValue(10-depth);
				if (playerOne == false) b.setValue(depth-10);
			//	cout << "after set" << b.getValue();
			//	cout << "entrou no 2";
				
				return b;
			}
		}
	int bestValue;
	if(playerOne == true){
		//cout << "entro if";
		bestValue = -10000;
		//pegar proximos
		vector<BoardState> list_child;
		list_child = b.get_nexts(1);
		//BoardState value(board, 0);
		
		for (int i = 0 ; i < list_child.size() ; i++){
			//list_child[i].printBoard();
			cout <<endl;
			b = this->teste(list_child[i].getBoard(), depth+1, false);
			if (b.getValue() >= bestValue){
			//	cout << "value: "<< b.getValue() << "  bestValue: " << bestValue <<endl;
			//	cout << "Board: " << endl;
			//	list_child[i].printBoard();
			//	cout << endl << "depth: " << depth <<endl << endl;
				bestValue = b.getValue();		
				b.setValue(bestValue);
				b.setVector(list_child[i].getBoard());
				}
		}
		
		//cout << "list" ;
		
		//cout <<value.getValue();
		//value.printBoard();
		cout << "true";
		return b;		
		}else{
			cout << "entrou else" <<endl; 
			bestValue = 10000;
			vector<BoardState> list_child;
			list_child = b.get_nexts(2);
			//BoardState value(board, 0);
			for (int i = 0 ; i < list_child.size() ; i++){
				
				//list_child[i].printBoard();
				cout <<endl;
				
				b = this->teste(list_child[i].getBoard(), depth+1, true);
				if (b.getValue() <= bestValue){
					bestValue = b.getValue();
					b.setValue(bestValue);
					b.setVector(list_child[i].getBoard());
					}
				}
			//cout << value.getValue();
		//	value.printBoard();
			cout << "false";
			return b;
		}
			
			
	}*/
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

