#include <iostream>
#include <string>
#include <vector>
#include <cctype>

// TODO: dont check the previous cell. handle direction
// make case insensitive
bool isFound(vector<vector<char>> grid, string word, int i, int j, int w){
  if (w == word.size())
    return true;

  if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
    return false;

  if (grid[i][j] == word[w]){
    if (isFound(grid, word, i + 1, j, w+1))
      return true;
    if (isFound(grid, word, i - 1, j, w+1))
      return true;
    if (isFound(grid, word, i, j + 1, w+1))
      return true;
    if (isFound(grid, word, i, j - 1, w+1))
      return true;
  }
  return false;
}

// Apply backtracking on every element to search the required word
bool WordSearch(vector<vector<char>> grid, string word){
  for(int i = 0; i < grid.size(); i++) {
    for(int j = 0; j < grid[0].size(); j++){
      if (isFound(grid, word, i, j, 0))
        return true;
    }
  }
  return false;
}