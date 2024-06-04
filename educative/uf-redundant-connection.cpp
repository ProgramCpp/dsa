#include "UnionFind.cpp"

/*
visited array
*/

// vector<int> RedundantConnections(vector<vector<int>> edges)
// {
//     vector<int> visited;

//     for(auto e: edges){
//         if(find(visited.begin(), visited.end(), e[0]) != visited.end() && 
//             find(visited.begin(), visited.end(), e[1]) != visited.end()){
//                 return e;
//             }
//         visited.push_back(e[0]);
//         visited.push_back(e[1]);
//     }
//     return {};
// }

/*
union find
*/

#include "UnionFind.cpp"

int uFind(map<int, int> &parent, int a){
    int p = a;
    while(p != parent[p]){
        p = parent[p];
    }
    parent[a] = p; // path compression  optimization
    return p;
}

void unionF(map<int, int> &parent, map<int, int> &rank, int a, int b){
    int p1 = uFind(parent, a);
    int p2 = uFind(parent, b);

    if(p1 == p2){
        return;
    }

    if(rank[p1] > rank[p2]){
        parent[b] = p1;
        rank[p1] += rank[p2]; // union by rank optimization
    } else{
        parent[a] = p2;
        rank[p2] += rank[p1];
    }
}

vector<int> RedundantConnections(vector<vector<int>> edges)
{
    map<int, int> parent;
    map<int, int> rank;

    for(auto e : edges){
        if(parent.find(e[0]) == parent.end()){
            parent[e[0]]=e[0];
            rank[e[0]] = 1;
        } 
        if(parent.find(e[1]) == parent.end()){
            parent[e[1]]=e[1];
            rank[e[1]] = 1;
        }
        if( uFind(parent, e[0]) == uFind(parent, e[1])){
            return e;
        }
        unionF(parent, rank, e[0], e[1]);
    }
    return {};
}