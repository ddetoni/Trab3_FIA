#include <cstdlib>
#include <iostream>

using namespace std;

class MinMax {

public:
	MinMax();
	BoardState run(vector<int>board,int depth, bool playerOne);
};

MinMax::MinMax(){
	//contructor
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
