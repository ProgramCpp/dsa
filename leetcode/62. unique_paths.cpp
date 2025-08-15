/* 62. Unique Paths
brute force: move the robot in the allowed directions to finish.
a cell can be visited in many ways. but the no of ways from that cell to finish line is the same.
cache the no of ways from each cell (a cells make a m X n matrix).
*/

class Solution {
public:
    // 1. OOB check 2. base case 3. cache check 4. computation 5. cache and return
    int up(int m, int n, int i, int j, vector<vector<int>> &ways){
        if(i == m - 1 && j == n - 1)
            return 1;

        if(i == m || j == n)// grid is 0 indexed.
            return 0;

        if(ways[i][j] != 0)
            return ways[i][j];

        ways[i][j] = up(m, n, i + 1, j, ways) + up(m, n, i, j + 1, ways);

        return ways[i][j];
    }

    int uniquePaths(int m, int n) { 
        vector<vector<int>> ways(m, vector<int>(n, 0));

        return up(m, n, 0, 0, ways);        
    }
};