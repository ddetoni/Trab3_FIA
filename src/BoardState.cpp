#include <vector>

using namespace std;

class BoardState {
private:
    vector<int> board;
    int depth;

public:
    BoardState();
    vector<BoardState> get_nexts();

};

BoardState::BoardState() {
    //Instanciar board
}

vector<BoardState> BoardState::get_nexts() {
    //Retorna os próximos estados.
    //Percorrer board, se vazio então copiar board e alterar a posição em questao.
}
