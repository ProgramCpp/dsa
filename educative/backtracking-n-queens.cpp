#include <iostream>
#include <string>

bool isSafe(vector<vector<bool>> &board, int x, int i, int n){
    for(int j = 0; j < x; j++)
        if(board[j][i]){
            cout << "queen at col " << j << ","<< i << ".cannot place queen in this col"<<endl;
            return false;
        }
    // checked only above current row        
    // the rest of the board is not yet filled 

    // for(int j = x+1; j < n; j++)
    //     if(board[j][i])
    //         return false;
    for(int k = x -1, l = i -1; k >= 0 && l >= 0; k--, l--)
        if(board[k][l]){
            cout << "queen at diagonal "<< k << ","<< l << ".cannot place queen in this col"<<endl;
            return false;
        }
    
    for(int k = x -1, l = i +1; k >= 0 && l < n; k--, l++)
        if(board[k][l]){
            cout << "queen at diagonal "<< k << ","<< l << ".cannot place queen in this col"<<endl;
            return false;
        }
        
    // the rest of the board is not yet filled 
    // for(int k = x +1, l = i +1; k < n && l < n; k++, l++)
    //     if(board[k][l])
    //         return false;
    cout << ".queen can be placed in this col "<< i << endl;
    return true;
}

int placeQueens(vector<vector<bool>> &board, int x, int n) {
    if (x == n) 
        return 1;

    int ways = 0;
    for(int i = 0; i < n; i++){
        if (isSafe(board, x, i, n)){
            board[x][i] = true;
            cout << "placed queen"<<x <<" at " << x << "," << i << endl;
            ways += placeQueens(board, x+1, n);  
            board[x][i] = false;
            cout << "ways " << ways << endl;
            cout << "removed queen"<<x <<" at " << x << "," << i << endl;
        }
    } 
    return ways;
}

int SolveNQueens(int n) {
    vector<vector<bool>> board(n, vector<bool>(n, false));
    return placeQueens(board, 0, n);
} 