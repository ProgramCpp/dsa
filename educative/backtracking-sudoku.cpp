#include <iostream>

bool isValid(vector<vector<char>>& board, int row, int col, char c){
     for (int i = 0; i < 9; i++)
          if(board[row][i] == c){
                cout << "cannot place " << c << " in " << row << "," << col <<".already in " << row << "," << i << endl
                return false;
          }
               
     
     for (int i = 0; i < 9; i++)
          if(board[i][col] == c)
               return false;

     int baseRow = row/3;
     int baseCol = col/3;

     for (int i = baseRow * 3; i < baseRow * 3 + 3; i++)
          for (int j = baseCol * 3; j < baseCol * 3 + 3; j++)
               if(board[i][j] == c)
                    return false;
     
     return true;
}

pair<int, int> nextCell(int r, int c){
     c++;
     if (c == 9){
          r++;
          c = 0;
     }

     return pair<int, int>{r, c};
}

bool solve(vector<vector<char>> &board, int row, int col){
     if (row == 9)
          return true;

     // cell already filled. try next one
     if (board[row][col] != '.'){
          return solve(board, nextCell(row, col).first, nextCell(row, col).second);
     }

     char c = board[row][col];

     for(char k = '1'; k <= '9'; k++){
          if(isValid(board, row, col, k)){
               board[row][col] = k;
               cout << "placing " << k << " in " << row << "," << col << endl;
               bool solved = solve(board, nextCell(row, col).first, nextCell(row, col).second);
               if (solved) {
                    return solved;
               }
          }
     }

     board[row][col] = c;
     cout << "unplacing " << c << " in " << row << "," << col << endl;

     return false;
}

vector<vector<char>> solveSudoku(vector<vector<char>>& board){
     solve(board, 0, 0);
     return board;
}