//https://medium.com/@c0D3M/leetcode-1970-last-day-where-you-can-still-cross-29007dda26a8
/*
approach 4:
connect water cells in first column to a virtual node. similarly, the cells in last column.
when the parent of the virtual nodes are same, you cannot cross anymore

left --[grid]-- right
*/


/*
brute force: use DFS from any top cell to reach botton cell. repeat after flooding each day
binary search: use binary search to find the day when the top cells are not reachable to botton cells. use DFS
Union Find: connect all adjacent flooded cells. when left most and right most are a single component, return the day
time complexity: 
O(num of cells * m * n)
=>
O(num of cells)
*/
#include "UnionFind.cpp"

int toInt(int r, int c) {
    // cout << "toInt" << endl;
    // could use rows value instead of 10000
    cout << r << ":" << c << ":" << 100000 * (r - 1) + (c - 1) << endl;
    return 100000 * (r - 1) + (c - 1);
}

int findu(map<int, int> &parent, int a){
    // cout << "find" << endl;
    int p = a;
    while(parent[a] != a){
        a = parent[a];
    }
    parent[p] = a;
     cout << "parent of " << p << " is " << a << endl;
    return a;
}

void unionf(map<int, int> &parent, map<int, int> &rank, int a, int b){
    // cout << "union " << a << " and " << b << endl;
    int pA = findu(parent, a);
    int pB = findu(parent, b);

    if (pA == pB)
        return;

    if(rank[pA] > rank[pB]){
        rank[pA] += rank[pB];
        parent[pB] = pA;
        cout  << "parent of "<< pB << " is " << pA << endl;
        // cout << "connected. parent of "<< pB << " is " << pA << endl;
    } else{
        rank[pB] += rank[pA];
        parent[pA] = pB;
        cout << "parent of "<< pA << " is " << pB << endl;
        // cout << "connected. parent of "<< pA << " is " << pB << endl;
    }
}

void Connect(vector<vector<int>> &land, map<int, int> &parent, map<int, int> &rank, int row, int col){
    // cout << "connect all " << row << "," << col << endl;
    // top row
    if(row - 1 >= 1){
        if (land[row -1][col])
            // cout << "connect row - 1, col " << endl;
            unionf(parent, rank, toInt(row, col), toInt(row -1, col));
        if (col - 1 >= 1 && land[row -1][col - 1]){
            unionf(parent, rank, toInt(row, col), toInt(row -1, col - 1));
        }
        if (col + 1 < land[0].size() && land[row -1][col + 1]){
            unionf(parent, rank, toInt(row, col), toInt(row -1, col + 1));
        }
    }

    // same row
    if (col - 1 >= 1 && land[row][col - 1]){
        unionf(parent, rank, toInt(row, col), toInt(row, col - 1));
    }

    // same row
    if (col + 1 < land[0].size() && land[row][col + 1]){
        unionf(parent, rank, toInt(row, col), toInt(row, col + 1));
    }

    // bottom row
    // off by one error - vector always upto less than size. not boundary cases for maps. check vector sizes
    if(row + 1 < land.size()){
        if (land[row + 1][col])
            unionf(parent, rank, toInt(row, col), toInt(row +1, col));
        if (col - 1 >= 1 && land[row +1][col - 1]){
            unionf(parent, rank, toInt(row, col), toInt(row +1, col - 1));
        }
        if (col + 1 < land[0].size() && land[row +1][col + 1]){
            unionf(parent, rank, toInt(row, col), toInt(row +1, col + 1));
        }
    }
}

int LastDayToCross(int rows, int cols, vector<vector<int>> waterCells)
{
    map<int, int> parent;
    map<int, int> rank;
    // virtual nodes that connect all left cells and all right cells
    int left = (rows - 1) * 100000 + cols + 1;
    int right = (rows - 1) * 100000 + cols + 2;
    parent[left] = left;
    rank[left] = 1;
    parent[right] = right;
    rank[right] = 1;
    
    cout << left << endl;
    cout << right << endl;
    // rows and cols start from 1. allocate 1 extra
    vector<vector<int>> land = vector(rows + 1, vector(cols + 1, 0));

    for(int i = 0; i < waterCells.size(); i++){
        int cell = toInt(waterCells[i][0], waterCells[i][1]);
        parent[cell] = cell;
        cout << "parent of " << cell << parent[cell] << endl;
        rank[cell] = 1;
        int row = waterCells[i][0];
        int col = waterCells[i][1];
        land[row][col] = 1;
        if (col == 1){
            // cout << "connect " << cell << " and " << left << endl;
            unionf(parent, rank, cell, left);
        }
        if (col == cols){
            // cout << "connect " << cell << " and " << right << endl;
            unionf(parent, rank, cell, right);
        }

        Connect(land, parent, rank, row, col);
        // cout << "checking equality" << endl;
        if(findu(parent, left) == findu(parent, right)){
            return i; // day starts from 0
        }

    }

    return 0;
}
