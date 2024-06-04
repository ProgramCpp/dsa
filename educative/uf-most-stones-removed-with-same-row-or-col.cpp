// Initialize two empty dictionaries, parents and ranks. Initially, every coordinate of the stones is a parent of itself and has a rank of zero.

// For each stone, check if it shares a row or column with another stone using ranks. If it does, add it to the group that has both of these stones.

// Find the number of groups once all stones have been grouped.

// Return the difference between the number of stones and the number of groups formed.


// Connected stones can be reduced to 1 stone,
// the maximum stones can be removed = stones number - islands number.
// so just count the number of "islands".

//aka
// only one stone will be left in each group, rest are removed
// removed = total stones - groups(stones left)


// Struggle between rows and cols?
// You may duplicate your codes when you try to do the same thing on rows and cols.
// In fact, no logical difference between col index and rows index.
// An easy trick is that, add 10000/ max row to col index.
// So we use 0 ~ 9999 for row index and 10000 ~ 19999 for col.

https://youtu.be/OwMNX8SPavM


#include "UnionFind.cpp"

int uFind(map<int, int> &parent, int a){
    // Q: what if u dont find the parent and just chain the nodes? 
    // A: all nodes will be chained linearly. logically, can still work. try it
    while (a != parent[a])
        a = parent[a];

    // todo: path compression
    return a;
}

bool unionf(map<int, int> &parent, map<int, int> &rank, int a, int b){
    int pA = uFind(parent, a);
    int pB = uFind(parent, b);

    if(rank[pA] > rank[pB]){
        rank[pA] += rank[pB];
        parent[pB] = pA;
        return pA;
    } else{
        rank[pB] += rank[pA];
        parent[pA] = pB;
        return pB;
    }
}

int rowOrder(vector<int> & stone){
    int MAX_COLUMNS = 10000;
    return stone[0] * MAX_COLUMNS + stone[1];
}


int RemoveStones(vector<vector<int>> & stones)
{  
    map<int, int> parent;
    map<int, int> rank;

    int groups = stones.size();
    map<int, int> stoneRows;
    map<int, int> stoneCols;

    for(auto s : stones){
        int stoneId = rowOrder(s);
        parent[stoneId] = stoneId;
        rank[stoneId] = 1;

        // how to find if the stone has same row/ column as another stone?
        if(stoneRows.find(s[0]) == stoneRows.end()){
            stoneRows[s[0]] = stoneId;
        }else{
            cout << "merging stones: " << stoneId << ", " << stoneRows[s[0]] << endl;
            int p = unionf(parent, rank, stoneId, stoneRows[s[0]]);
            stoneRows[s[0]] = p;
            groups--;
        }

        if(stoneCols.find(s[1]) == stoneCols.end()){
            stoneCols[s[1]] = stoneId;
        }else{
            cout << "merging stones: " << stoneId << ", " << stoneCols[s[1]];
            int p = unionf(parent, rank, stoneId, stoneCols[s[1]]);
            stoneCols[s[1]] = p;
            groups--;
        }
    }

    if(groups == 0)
        return 0;

    return stones.size() - groups;
}

