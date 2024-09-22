#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<char>>& board) {
    int rows=board.size();
    int cols=board[0].size();
    int min_obstacles=INT_MAX; 

    for(int col=0;col<cols;col++){
        int figure_row = -1;
        for(int row=0;row<rows;row++){
            if(board[row][col]=='*'){
                figure_row=row;
                break;
            }
        }
        
        if (figure_row!=-1) {
            int obstacles=0;
            for(int row=figure_row+1;row<rows;row++) {
                if(board[row][col]=='#'){
                    obstacles++;
                }
            }
            min_obstacles=min(min_obstacles, obstacles);
        }
    }
    return min_obstacles;
}

int main() {
    // vector<vector<char>> board = {
    //     {'*', '-', '*', '-', '*'},
    //     {'*', '-', '-', '-', '*'},
    //     {'*', '-', '*', '-', '*'},
    //     {'-', '#', '-', '-', '-'},
    //     {'-', '-', '#', '-', '-'}
    // };
    vector<vector<char>> board={
        {'*','*','*'},
        {'#','-','*'},
        {'*','*','-'},
        {'-','-','-'},
        {'-','#','#'}
    };

    // Call the solution function and print the result
    cout<<solution(board)<<endl;
    return 0;
}
