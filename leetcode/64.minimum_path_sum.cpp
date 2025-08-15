/* 64. Minimum Path Sum
traverse all paths, at any point, pick the minimum cost.
cache the cost from a cell to the dest.

reasoning:all along the route, at every step, the cell with least cost will be chosen. 
example 1:
cost to reach [2][2] from [2][1] is 2 + 1 = 3 and to reach from [1][2] is 1 + 1 = 2. thus the last step will be reached from top. but the local minima might not produce global minima. explore every combination and pick optimal path, by chaching to avoid repetitive computation from different paths.
*/

class Solution {
public:
    int mps(vector<vector<int>>& grid, int m, int n, int i ,int j, vector<vector<int>>& mincost){
        if(i == m || j == n)
            return INT_MAX; // outside the grid, there's no path. cost higher than other paths

        if(i == m - 1 && j == n - 1) // outside the grid and base case handled separately
            return grid[i][j];

        if(mincost[i][j] != 0)
            return mincost[i][j];
        
        mincost[i][j] = grid[i][j] + min(mps(grid, m, n, i + 1, j, mincost),
            mps(grid, m, n, i, j + 1, mincost));

        return mincost[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> mincost(grid.size(), vector<int>(grid[0].size(), 0));
        return mps(grid, grid.size(), grid[0].size(), 0, 0, mincost);
    }
};