# include <algorithm>


/*
In row major order, elements of a multi-dimensional array are arranged sequentially, row by row, which means filling all the indexes of the first row and moving on to the next row.
array index([r][c]) = r * no of cols + c // note, r starts from 0
*/

/*
suggested soln: count all 1's. group adjacent 1's - DFS/ UF, mark them 0 and decrement the count by number of neighbours
*/

/*
Breadth-First Search (BFS):

Implement a BFS traversal starting from each '1' in the grid.
Mark visited cells to avoid counting the same island multiple times.
Counting Islands:

Iterate through each cell in the grid.
If the cell contains '1' and has not been visited, start a BFS traversal from that cell and mark all connected '1's as visited.
Increment the count for each new island encountered.
Return Result:

The final count represents the number of islands in the grid.
*/


// int NumIslands(vector<vector<char>> & grid)
// {  
//     int m = grid.size();
//     int n = grid[0].size();

//     int islands = m * n;

//     // rank is not needed. there is no find operation
//     //map<int, int> parent;// row order parent grid

//     for(int i = 0; i < m; i++){
//         for(int j = 0; j < n; j++){
//             if(grid[i][j] == '1'){
//                 if( (i - 1 >= 0 && grid[i-1][j] == '1') ||
//                 (j - 1 >= 0 && grid[i][j-1] == '1')){
//                     islands--;
//                 }
//             }else{
//                // parent[i][j] = -1;
//                 islands--;
//             }
//         }
//     }

//     return islands;
// }
// [["1", "1", "1", "1", "0"], ["1", "0", "0", "0", "1"], ["1", "0", "0", "1", "1"], ["0", "1", "0", "1", "0"], ["1", "1", "0", "1", "1"]]
// exp: 3, actual 5
// u r assuming the previous 1's are already counted. remember, u are not decrementing the connection, but the cell
// ex:
// 0 1
// 1 1 4 - 1 -1 = 2. correct answer: 1. the previous 1's are counted twice
// the previous 1's may or may not be part of the same island already 
// ex:
// 1 1
// 1 1 <- i-1 and j-1 are part of same island already. islands = 1
// ex:
// 0 1
// 1 1 <- i-1 and j-1 are not part of same island already. islands = 1
// if not already part of island, decr islands - introduce parent to identify that

// no, dont count the edges. island is a cell count

// parent and rank pass by value
// void unionf(int a, int b, int parent[], int rank[]){
//     if(parent[a] == -1){
//         parent[a] = a;
//         rank[parent[a]]= 1;
//     }
//     if(parent[b] == -1){
//         parent[b] =b;
//         rank[parent[b]]=1;
//     }
//     if(rank[parent[a]] > rank[parent[b]]){
//         rank[parent[a]] += rank[parent[b]]; 
//         parent[b] = parent[a];
//     } else if(rank[parent[a]] < rank[parent[b]]){
//         rank[parent[b]] += rank[parent[a]]; 
//         parent[a] = parent[b];
//     } // do nothing if equal - DO NOT add rank
    
// }

// int rowOrder(int i, int j, int n){
//     return i * n + j;
// }

// int NumIslands(vector<vector<char>> & grid){
//     int m = grid.size();
//     int n = grid.size();

//     int islands = m * n;

//     int parent[m*n];
//     int rank[m*n];
//     fill(parent, -1);
//     fill(rank, 0);

//     for(int i = 0; i < m; i++){
//         for(int j = 0; j < n; j++){
//             if(grid[i][j] == '0'){
//                 islands--;
//             }else{
//                 // if(i ==0 && j ==0){
//                 //     parent[rowOrder(i,j,n)]= rowOrder(i,j,n);
//                 //     rank[rowOrder(i,j,n)]=1;
//                 //     continue;
//                 // }
//                 if(i-1 >= 0 && grid[i-1][j] == '1'){
//                     unionf(rowOrder(i, j, n), roworder(i-1, j, n));
//                     islands--;
//                 }
//                 if(j-1 >= 0 && grid[i][j-1] == '1'){
//                     // why are you not using "find"?
//                     if(parent[i][j] != parent[i][j-1]){
//                         islands--;
//                     }
//                     unionf(rowOrder(i, j, n), rowOrder(i, j-1, n));
//                 }
//             }
//         }
//     }
//     return islands;
// }
/*
dont decr islands if parents are different, simply use return value of union function
*/

using namespace std;
class Solution {
public:
    // void unionf(int a, int b, vector<int> &parent, vector<int> &rank){
    //     cout<< "a:" << a << " p" << parent[a] << ",b:" << b << " p" << parent[a];
    //     if(parent[a] == parent[b]){
    //         return;
    //     }

    //     if(rank[parent[a]] > rank[parent[b]]){
    //         rank[parent[a]] += rank[parent[b]]; 
    //         rank[parent[b]] = 0; // not needed - anyway parent changed and wont be referenced
    //         parent[b] = parent[a];
    //         cout << b << ":" << parent[b] << ":" << rank[parent[b]] << endl;
    //     } else{
    //         rank[parent[b]] += rank[parent[a]]; 
    //         parent[a] = parent[b];
    //         cout << a << ":" << parent[a] << ":" <<rank[parent[a]] << endl;
    //     } 
    
    // }
    /*
    unoion is not working as expected- u are changing the parent of one element. but all other nodes in the same group still point to the same parent. u must change the root, to affect all the children
    */

    int uFind(int a, vector<int> &parent){
        while(parent[a] != a){
            a = parent[a];
        }
        return a;
    }


    bool unionf(int a, int b, vector<int> &parent, vector<int> &rank){
        int ap = uFind(a, parent);
        int bp = uFind(b, parent);

        if(ap == bp){
            return false;
        }

        if(rank[ap] > rank[bp]){
            rank[ap] += rank[bp];
            parent[bp] = ap;
        } else{
            rank[bp] += rank[ap];
            parent[ap] = bp;
        }
        return true;
    }

    int rowOrder(int i, int j, int n){
        return i * n + j;
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int islands = m * n;

        // be it vector or map, doesnt matter.
        // rowOrder of Cell is the index/ key. value is the parent/rank
        // you could have even used a 2D vector like grid
        // to indicate a parent. u can use rowOrder
        vector<int> parent(m*n, -1);
        vector<int> rank(m*n, 0);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(parent[rowOrder(i, j, n)] == -1){ // no need to check this
                    
                    parent[rowOrder(i, j, n)] = rowOrder(i, j, n);
                    rank[rowOrder(i,j,n)] = 1;
                }
                // water- one less land area in the grid
                if(grid[i][j] == '0'){
                    islands--;
                }else{
                    if(i-1 >= 0 && grid[i-1][j] == '1'){
                        bool merged = unionf(rowOrder(i, j, n), rowOrder(i-1, j, n), parent, rank);
                        // not merging if already merged
                        if (merged) {
                            islands--;
                        }
                    }
                    if(j-1 >= 0 && grid[i][j-1] == '1'){
                        // use the result of union - parent changed or not
                        bool merged = unionf(rowOrder(i, j, n), rowOrder(i, j-1, n), parent, rank);
                        // not merging if already merged
                        /* ex:
                        1 1
                        1 1
                        4(total) - 1(cell 0,1) - 1(cell 1,0) -1(cell 1, 1 from top) -1(cell 1,1 from left) = 0 : wrong answer
                        4(total) - 1(cell 0,1) - 1(cell 1,0) -1(cell 1, 1 from top) = 1 : the last merge is ignored since already merged from top
                        */
                        if (merged){
                            islands--;
                        }
                    }
                }
            }
        }
        return islands; 
        }
};

// BFS also take m *n complexity. since visited nodes are marked 0 and wont be resursively visited again