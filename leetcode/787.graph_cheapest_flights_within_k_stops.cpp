/* 787. Cheapest Flights Within K Stops
intuition:
build adjacency matrix for the graph.
track the min cost between src and dest so far, while traversing all the paths between src and dest.
DFS to reach the destination with k stops. track the cost of current path.
quit if min cost so far exceeded or k nodes already visited.
=> O(n^2)
TLE
add cost optimization
it is true that all possible paths must be explored to find the shortest path with k constraint. but the search can be optimized with techniques like memoization, pruning etc.
~~~~ this isnt useful. the remaining path after i must be explored to find optimal solution. only after traversing the graph to i, it memoized value will be looked up in which case, there is no use of memoization
you can memoize the min cost from src to i with dist stops. but adding dimensions to memoization increases the number of sub problems to be solved.
memoize min cost to reach the i from src. visited[city][stops] - pre order DFS, not post order
~~~~
memoize the min cost from an ith node to dst node with stops remaining. it doesnt matter what path it took. cost[i][stops_remaining]
WAIT!! what happens when i is reached from src with same dist but different paths.
memoization: recursive calls to solve sub problem and memoize. base case to build solutions. use the memoized solutions.
alternatively, BFS with priority queue (i.e., modified Dijkstra). 
visited[city][stops] to track the min cost to reach a city with the number of stops. stops are tracked since it is required to return a constrained result. otherwise stops are not required. though a city can be reached via different paths with the same number of stops, **the cost is all we care about and not the path**.
https://www.youtube.com/watch?v=5eIK3zUdYmE
although time complexity is the same, code is readable with bellman-ford
in the i'th iteration, you are finding the shortest path to all nodes that are i distance away.
the edges after i distance away are not considered, just yet
ex: i = 0, cost to reach nodes connected to the neighbor's of the src is infinity, since they are still not directly connected to the src.
    b
  /   \
a      d - e
  \   /
    c
`d` is reachable from `a` only after the first iteration. `e` is reachable from `a` only after the 2nd iteration, once there is a path to `d`
after k iterations, return the minimum cost to reach dst from src
*/


// ** memoization helped TLE **
// 47/58
// ex: n=5, k=3, src=0, dst=4
// flights = [[0,1,100],[0,2,100],[0,3,10],[1,2,100],[1,4,10],[2,1,10],[2,3,100],[2,4,100],[3,2,10],[3,4,100]]
// expedted= 40
class Solution {
public:
    // calculate minimum cost from i to dst within k - dist stops
    // insteaad of dist, you can even call stops remaining
    void dfs(int n, int i, int dst, int k, vector<vector<int>>& adjMat, int dist, map<int, bool> &seen, vector<vector<int>> &minCosts){
        // if(seen[i]){
        // detect cycle
        if(seen[i]){
            return; 
        }

        if (dist > k ) { // cannot take more stops
            return; // dst was unreachable in this path within k stops
        }

        // min cost from i with remaining stops
        // there maybe another path with lesser cost.
        // ensure this check is before any code that updates this value
        // once this is computed considering all the paths, there is no need to compute this again
        if(minCosts[i][k - dist] != INT_MAX){
            return; // already computed. skip  
        }

        if(i == dst){ // within k stops, we found the dst
            minCosts[i][k - dist] = 0;
            return ; // no other path gives min cost of 0
        } 

        // this is the last node, cannot traverse further
        // ofcourse you think the above check takes care in the next iteration
        // beware, dist is used to index fixed size containers in this call frame
        // this cannot be combined with above check to account for 0 stops left and reaching dst
        if (dist == k) 
            return;

        seen[i] = true;
        for (int nxt = 0; nxt < n; nxt++){
            // ignore a path from node to itself
            // and pairs of nodes that dont have an edge
            if (i == nxt || adjMat[i][nxt] == INT_MAX) 
                continue;

            dfs(n, nxt, dst, k, adjMat, dist + 1, seen, minCosts);

            // if (minCosts[nxt][k-(dist+1)] != INT_MAX )
            //     minCosts[i][k - dist] = min(minCosts[i][k - dist], adjMat[i][nxt] + minCosts[nxt][k-(dist+1)]);

            // BUGG!!?? min cost from i to dst via nxt can be with any number of stops less than k
            //     // no, minCosts[i][j] considers dst winthin k stops.
            //     // no, for nodes from i, minCosts is updated with the number of stops left (any value less than k)
            for (int j = dist + 1; j <= k; j++){
                if (minCosts[nxt][k-j] != INT_MAX ){
                        minCosts[i][k - dist] = min(minCosts[i][k - dist], adjMat[i][nxt] + minCosts[nxt][k-j]);
                }  
            } 
        }
        seen[i] = false;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> adjMat(n, vector<int>(n, INT_MAX)); // all node are disjoint. cost is max

        for(int i = 0; i < n; i++){
            adjMat[i][i] = 0; // cost to itself is 0
        }

        for(auto f : flights){
            adjMat[f[0]][f[1]] = f[2];
        }

        map<int, bool> seen;
        // min cost from i to dst within k stops
        // minCosts[i][k] = <min_cost> 
        k++; // one additional stop including dst. instead of using k+1 everywhere. code is more readable
        vector<vector<int>> minCosts(n, vector<int>(n + 2, INT_MAX)); // k < n. but k should be atleast < n - 2, excluding src and dst
        dfs(n, src, dst, k, adjMat, 0, seen, minCosts);
        // result is minimum of all costs with different number of stops less than k
        int minCost = INT_MAX;
        for(int i = 0; i < k + 2; i++){
            minCost = min(minCost, minCosts[src][i]); // any number of stops < k
        }

        if (minCost == INT_MAX)
            return -1;
        else
            return minCost;
    }
};

// TLE
// class Solution {
// public:
//     // return cost from dst to ith node
//     int dfs(int n, int src, int dst, int k, vector<vector<int>>& adjMat, int dist, map<int, bool> &seen){
//         if(seen[src]){
//             return INT_MAX; // dst cant be reached via this node
//         }

//         if (dist > k + 1) {
//             return INT_MAX; // dist was unreachable in this path within k stops
//         }   

//         if(src == dst){// within k stops, we found the dst
//             return 0; // keep adding upstream edges
//         }

//         int minCost = INT_MAX;
//         seen[src] = true;
//         for (int i = 0; i < n; i++){
//             // ignore a path from node to itself
//             // and pairs of nodes that dont have an edge
//             if (src == i || adjMat[src][i] == INT_MAX) 
//                 continue;

//             int cost = dfs(n, i, dst, k, adjMat, dist + 1, seen);
//             if (cost != INT_MAX && cost + adjMat[src][i] < minCost)
//                 minCost = cost + adjMat[src][i];
//         }
//         seen[src] = false;

//         return minCost; // return INT_MAX, if no paths down this node reached dst within k stops
//     }

//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//         vector<vector<int>> adjMat(n, vector<int>(n, INT_MAX)); // all node aare disjoint. cost is max

//         for(int i = 0; i < n; i++){
//             adjMat[i][i] = 0; // cost to itself is 0
//         }

//         for(auto f : flights){
//             adjMat[f[0]][f[1]] = f[2];
//         }

//         map<int, bool> seen;
//         int cost = dfs(n, src, dst, k, adjMat, 0, seen);
//         if (cost == INT_MAX)
//             return -1;
//         else
//             return cost;
//     }
// };