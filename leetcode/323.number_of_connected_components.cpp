/* 323. Number of Connected Components in an Undirected Graph
intuition: build adj list.
O(n^2) // number of edges
start with a node and traverse until all connected nodes are visited.
O(n)
find a node thats unvisited and repeat.
O(n+n)
suggested solution: UF. O(E)
*/

class Solution {
public:

    int find(int a, map<int, int> &parent){
        while(a != parent[a])
            a = parent[a];
        return a;
    }

    void union_(int a, int b, map<int, int> &parent, map<int, int> &rank, int &cc){
        int pA = find(a, parent);
        int pB = find(b, parent);

        if(pA == pB)
            return;

        cc--;
        if(rank[pA] > rank[pB]){
            parent[pB] = pA;
            rank[pA] += rank[pB];
        } else{
            parent[pA] = pB;
            rank[pB] += rank[pA];
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        map<int, int> parent;
        map<int, int> rank;

        for(int i = 0; i < n; i++){
            parent[i] = i;
            rank[i] = 1;
        }

        int cc = n;
        for(auto i : edges){
            union_(i[0], i[1], parent, rank, cc);
        }

        return cc;
    }
};
