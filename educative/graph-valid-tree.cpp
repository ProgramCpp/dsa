#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>

bool ValidTree(int n, std::vector<std::vector<int>>& edges) {
    if (edges.size() != n -1)
        return false;

    vector<vector<bool>> graph(n, vector<bool>(n, false));

    for(vector<int> &edge: edges){
        graph[edge[0]][edge[1]] = true;
    }

    // array lookup is O(1) 
    // array filled check is O(n)
    // map loopup is O(log n)
    // map size is O(1)
    bool visited[n]={false};
    int visitedCount = 0;

    // visited[0] = true;
    // visitedCount++;

    stack<int> trace;
    trace.push(0);

    while(!trace.empty()){
        int node = trace.top();
        trace.pop();

        if(visited[node])
            return false;

        if (visitedCount == n)
            return true;

        visited[node] = true;
        visitedCount++;

        for(int i = 0; i < n; i++) {
            // when i is same as n, it is fals eby default
            if (/*i != n &&*/ graph[node][i])
                trace.push(i);
        }
    }

    return true;
}