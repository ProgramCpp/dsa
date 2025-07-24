/* 994. rotting oranges
intuition:
every orange is connected to every other orange in 4 directions
start dfs from a rotten orange. count the depth of oranges from the rotten orange. depth is equal to the number of minutes.
repeat from all initial rotton oranges. return the max of the depths.
wrong: with multiple rotting oranges, the number of minutes to rot reduces.
Suggested solution: BFS simultaneously from all rotting oranges
*/

struct cell {
    int i, j;
    int depth;
    cell(int i, int j, int d):i(i), j(j), depth(d){}
};

class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
        queue<cell> cells;
        int m = grid.size();
        int n = grid[0].size();

        int oranges = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2)
                    cells.push(cell(i,j, 0));
                else if(grid[i][j] == 1)
                    oranges++;
            }
        }

        int maxDepth = 0;
        while(!cells.empty()){
            cell c = cells.front();
            int i = c.i;
            int j = c.j;
            cells.pop();

            // move upto first row
            if(i > 0 && grid[i-1][j] == 1){
                grid[i-1][j] = 2; // rot oranges (visited). ensure you're not loopng infinitely
                int d = c.depth + 1;
                maxDepth = max(maxDepth, d);
                cells.push(cell(i-1,j, d));
                oranges--;
            } 
            
            // move upto last row
            if(i < m-1 && grid[i+1][j] == 1){
                grid[i+1][j] = 2;
                int d = c.depth + 1;
                maxDepth = max(maxDepth, d);
                cells.push(cell(i+1,j, d));
                oranges--;
            }

            if (j > 0 && grid[i][j-1] == 1){
                grid[i][j-1] = 2;
                int d = c.depth + 1;
                maxDepth = max(maxDepth, d);
                cells.push(cell(i,j-1, d));
                oranges--;
            } 

            if(j < n-1 && grid[i][j + 1] == 1){
                grid[i][j+1] = 2;
                int d = c.depth + 1;
                maxDepth = max(maxDepth, d);
                cells.push(cell(i,j+1, d));
                oranges--;
            }
        }

        if (oranges > 0)
            maxDepth = -1;

        return maxDepth;
    }
};

// not simultaneous BFS for all rotting oranges
// class Solution {
// public:

//     int rot(vector<vector<int>>& grid, int m, int n, int i, int j, int depth){
//         int rottenDepth = depth;
//         if(i > 0 || i < m ){
               // todo: rot only of there are cells with unrotten oranges 
//             int d =  rot(grid, m, n, i - 1, j, depth + 1);
//             rottonDepth = max(d, rottonDepth);

//             d =  rot(grid, m, n, i + 1, j, depth + 1);
//             rottonDepth = max(d, rottonDepth);
//         }

//         if(j > 0 || j < n ){
//             int d =  rot(grid, m, n, i, j - 1, depth + 1);
//             rottonDepth = max(d, rottonDepth);

//             d =  rot(grid, m, n, i, j + 1, depth + 1);
//             rottonDepth = max(d, rottonDepth);
//         }

//         return rottenDepth;
//     }

//     int orangesRotting(vector<vector<int>>& grid) {
//         if(grid.size() == 0)
//             return -1;
//         return rot(grid, grid.size(), grid[0].size(), 0, 0, 0);
//     }
// };