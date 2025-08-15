/* 63. Unique Paths II
same as unique paths, with extra check to avoid obstacles.
*/

class Solution {
public:
    int upwo(vector<vector<int>>& grid, int m, int n, int i, int j, vector<vector<int>>& ways){
        if(i == m || j == n)
            return 0;

        if(grid[i][j] == 1)
            return 0;

        // obstacle could be in the dest cell
        if(i == m - 1 && j == n - 1)
            return 1;

        if(ways[i][j] != 0)
            return ways[i][j];

        ways[i][j] = upwo(grid, m , n, i + 1, j, ways) + upwo(grid, m , n, i, j + 1, ways);

        return ways[i][j];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> ways(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
        return upwo(obstacleGrid, obstacleGrid.size(), obstacleGrid[0].size(), 0 , 0, ways);
    }
};