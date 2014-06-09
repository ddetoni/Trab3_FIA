#include <cstdlib>
#include <iostream>

using namespace std;

class MinMax {

public:
	MinMax();
	BoardState run(vector<int>board,int depth, bool playerOne);
	BoardState run_depth(vector<int>board,int depth, int max_depth, bool playerOne);
	BoardState run_alpha_beta(vector<int> board, int max_depth, int alpha, int beta, bool playerOne);
};

MinMax::MinMax(){
	//contructor
}


BoardState MinMax::run_alpha_beta(vector<int> board, int depth, int alpha, int beta, bool playerOne){

	BoardState b (board, 0);

    if (b.isOver()){
		if (b.Evaluate()==1){
			b.setValue(10+depth);
			return b;
		}else if (b.Evaluate()==2) {
			b.setValue(depth-10);
			return b;
	    }
        b.setValue(0);
        return b;
    }

	BoardState best (board, 0);
	if(playerOne == true){
		best.setValue(-10000);
		vector<BoardState> list_child;
		list_child = b.get_nexts(1);
		for (int i = 0 ; i < list_child.size() ; i++){
			b = this->run_alpha_beta(list_child[i].getBoard(), depth+1, best.getValue(), beta, false);
			if (b.getValue() > best.getValue()){
                best = list_child[i];
                best.setValue(b.getValue());
			}
			if (beta <= best.getValue()){
				//cout << "entrou no alpha";
				break;
			}
			
		}
        return best;
	} else {
		best.setValue(10000);
		vector<BoardState> list_child;
		list_child = b.get_nexts(2);
		for (int i = 0 ; i < list_child.size() ; i++){
			b = this->run_alpha_beta(list_child[i].getBoard(), depth+1, alpha, best.getValue(), true);
			if (b.getValue() < best.getValue()){
                best = list_child[i];
                best.setValue(b.getValue());
			}
			if (best.getValue() <= alpha){
				//cout << "entrou no beta";
				break;
			}
		}
        return best;
	}
}



BoardState MinMax::run(vector<int> board, int depth, bool playerOne){

	BoardState b (board, 0);

    if (b.isOver()){
		if (b.Evaluate()==1){
			b.setValue(10+depth);
			return b;
		}else if (b.Evaluate()==2) {
			b.setValue(depth-10);
			return b;
	    }
        b.setValue(0);
        return b;
    }

	BoardState best (board, 0);
	if(playerOne == true){
		best.setValue(-10000);
		vector<BoardState> list_child;
		list_child = b.get_nexts(1);
		for (int i = 0 ; i < list_child.size() ; i++){
			b = this->run(list_child[i].getBoard(), depth+1, false);
			if (b.getValue() > best.getValue()){
                best = list_child[i];
                best.setValue(b.getValue());
			}
		}
        return best;
	} else {
		best.setValue(10000);
		vector<BoardState> list_child;
		list_child = b.get_nexts(2);
		for (int i = 0 ; i < list_child.size() ; i++){
			b = this->run(list_child[i].getBoard(), depth+1, true);
			if (b.getValue() < best.getValue()){
                best = list_child[i];
                best.setValue(b.getValue());
			}
		}
        return best;
	}
}

BoardState MinMax::run_depth(vector<int> board, int depth, int max_depth, bool playerOne){
	BoardState b (board, 0);

	if (depth == max_depth || b.isOver()){
		if (b.Evaluate()==1){
			b.setValue(10+depth);
			return b;
		}else if (b.Evaluate()==2) {
			b.setValue(depth-10);
			return b;
		}
		b.setValue(0);
		return b;
	}

	BoardState best (board, 0);
	if(playerOne == true){
		best.setValue(-10000);
		vector<BoardState> list_child;
		list_child = b.get_nexts(1);
		for (int i = 0 ; i < list_child.size() ; i++){
			b = this->run_depth(list_child[i].getBoard(), depth+1, max_depth, false);
			if (b.getValue() > best.getValue()){
				best = list_child[i];
				best.setValue(b.getValue());
			}
		}
		return best;
	} else {
		best.setValue(10000);
		vector<BoardState> list_child;
		list_child = b.get_nexts(2);
		for (int i = 0 ; i < list_child.size() ; i++){
			b = this->run_depth(list_child[i].getBoard(), depth+1, max_depth, true);
			if (b.getValue() < best.getValue()){
				best = list_child[i];
				best.setValue(b.getValue());
			}
		}
		return best;
	}
}
