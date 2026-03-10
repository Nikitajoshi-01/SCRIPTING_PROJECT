#include <iostream>
#include <vector>
using namespace std;

char board[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

void printBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << "\n";
        if (i < 2) cout << "-----------\n";
    }
    cout << "\n";
}

bool movesLeft() {
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(board[i][j]==' ')
                return true;
    return false;
}

int evaluate() {

    for(int i=0;i<3;i++){
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2]){
            if(board[i][0]=='X') return 1;
            if(board[i][0]=='O') return -1;
        }
    }

    for(int j=0;j<3;j++){
        if(board[0][j]==board[1][j] && board[1][j]==board[2][j]){
            if(board[0][j]=='X') return 1;
            if(board[0][j]=='O') return -1;
        }
    }

    if(board[0][0]==board[1][1] && board[1][1]==board[2][2]){
        if(board[0][0]=='X') return 1;
        if(board[0][0]=='O') return -1;
    }

    if(board[0][2]==board[1][1] && board[1][1]==board[2][0]){
        if(board[0][2]=='X') return 1;
        if(board[0][2]=='O') return -1;
    }

    return 0;
}

int minimax(bool isMax) {

    int score = evaluate();

    if(score == 1) return score;
    if(score == -1) return score;

    if(!movesLeft()) return 0;

    if(isMax) {
        int best = -1000;

        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]==' '){
                    board[i][j] = 'X';

                    best = max(best, minimax(false));

                    board[i][j] = ' ';
                }
            }
        }

        return best;
    }
    else {
        int best = 1000;

        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]==' '){
                    board[i][j] = 'O';

                    best = min(best, minimax(true));

                    board[i][j] = ' ';
                }
            }
        }

        return best;
    }
}

pair<int,int> findBestMove() {

    int bestVal = -1000;
    pair<int,int> bestMove = {-1,-1};

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){

            if(board[i][j]==' '){

                board[i][j] = 'X';

                int moveVal = minimax(false);

                board[i][j] = ' ';

                if(moveVal > bestVal){
                    bestMove = {i,j};
                    bestVal = moveVal;
                }
            }
        }
    }

    return bestMove;
}

int main() {

    cout<<"Tic Tac Toe (comp= X, me = O)\n";

    while(true){

        printBoard();

        int r,c;
        cout<<"Enter your move (row col): ";
        cin>>r>>c;

        if(board[r][c]!=' '){
            cout<<"Invalid move!\n";
            continue;
        }

        board[r][c] = 'O';

        if(evaluate()==-1){
            printBoard();
            cout<<"i won!\n";
            break;
        }

        if(!movesLeft()){
            printBoard();
            cout<<"Draw!\n";
            break;
        }

        pair<int,int> bestMove = findBestMove();
        board[bestMove.first][bestMove.second] = 'X';

        cout<<"comp plays: "<<bestMove.first<<" "<<bestMove.second<<"\n";

        if(evaluate()==1){
            printBoard();
            cout<<"comp wins!\n";
            break;
        }

        if(!movesLeft()){
            printBoard();
            cout<<"Draw!\n";
            break;
        }
    }

    return 0;
}