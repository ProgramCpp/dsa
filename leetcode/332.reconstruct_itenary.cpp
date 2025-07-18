/*
332. Reconstruct Itinerary

intuition:
construct agjlist to travverse the graph
sort the adjacent nodes in the lexical order
NOTE: use ALL tickets once and only ONCE.
since there is a valid itenary, every node with say 2 outgoing edges will have 2 incoming edges.
traverse the graph from jfk in DFS. track visited nodes since cycles are possible
what if the first traversal reaches the dest without exploring thhe branches?
ex: what if the graph traverses a -> b-> d-> e
      c
   ^     \
  /       V
a - >b -> d -> e
 ^--------/   
what if the next node is picked based on indegrees? what if there were more loops after e?
      c             f
   ^     \       ^     \
  /       V     /       V
a - >b -> d -> e -> g -> h -> i
 ^--------/     ^--------/ 
ex: a-> b -> d -> e -> g -> h -> i
every path must be visited, in order. traversal is the solution.
suggested solution: 
result size is E + 1
backtrack if the result size is not E + 1 and the node doesnt have any more outgoing edges
OR
find eulerian circuit/ path. Hierholzer's Algorithm
*/

// TLE
class Solution {
public:

    // total stops excluding src/ number of edges.
    bool dfs(map<string, vector<string>> &flightmap, int totalStops, string src, int stops, vector<string> &result, map<string, map<string, bool>> &visited){
        // traversed all edges
        if (totalStops == stops){ // terminating condition when all edges traversed
            cout << totalStops << endl;
            result.push_back(src);
            return true;
        }

        result.push_back(src);
        cout << "reached " << src << " at steps " << stops << endl;
        for(auto i : flightmap[src]){
            if(visited[src][i])
                continue;
            visited[src][i] = true;
            // do not overwrite stops
            int isValid = dfs(flightmap, totalStops, i, stops + 1, result, visited);
            if (isValid) // if a valid itenary is found, stop processing other paths. else, continue processing other paths
                return true; // solution found. skip to return result.
            visited[src][i] = false;
        }
        result.pop_back();
        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, vector<string>> flightmap;

        for(auto ticket : tickets){
            flightmap[ticket[0]].push_back(ticket[1]);
        }

        for(auto i = flightmap.begin(); i != flightmap.end(); i++){
            sort(i->second.begin(), i->second.end()); // sort edges for lexical order
        }

        vector<string> result;
        map<string, map<string, bool>> visited;
        // theres atleast one valid itenary. not checking return value
        dfs(flightmap, tickets.size(), "JFK" , 0, result, visited);

        return  result;
    }
};

// // TLE
// O(n^2!) - n^2 edges permutation of all edges npn = n!
// class Solution {
// public:

//     // total stops excluding src/ number of edges.
//     int dfs(map<string, vector<string>> &flightmap, int totalStops, string src, int stops, vector<string> &result, map<string, map<string, bool>> &visited){
//         // traversed all edges
//         if (totalStops == stops){ // terminating condition when all edges traversed
//             cout << totalStops << endl;
//             result.push_back(src);
//             return stops;
//         }

//         result.push_back(src);
//         cout << "reached " << src << " at steps " << stops << endl;
//         for(auto i : flightmap[src]){
//             // when the same node is revisited in a cycle, do not process already visited edges
//             // NOTE: cycles are allowed. but same edge cannot be revisited. thus track visited edges and not visited nodes
//             // when a node is a centre of several cycles, this loop explores cycles in all possible orders
//             // ex: [["JFK","SFO"],["JFK","ATL"],["SFO","JFK"],["ATL","AAA"],["AAA","ATL"],["ATL","BBB"],["BBB","ATL"],["ATL","CCC"],["CCC","ATL"],["ATL","DDD"],["DDD","ATL"],["ATL","EEE"],["EEE","ATL"],["ATL","FFF"],["FFF","ATL"],["ATL","GGG"],["GGG","ATL"],["ATL","HHH"],["HHH","ATL"],["ATL","III"],["III","ATL"],["ATL","JJJ"],["JJJ","ATL"],["ATL","KKK"],["KKK","ATL"],["ATL","LLL"],["LLL","ATL"],["ATL","MMM"],["MMM","ATL"],["ATL","NNN"],["NNN","ATL"]]

//             if(visited[src][i])
//                 continue;
//             visited[src][i] = true;
//             // do not overwrite stops
                // DECLARE SEPARATE VARIABLES FOR DIFFERNT PURPOSES. DO NOT REUSE VARS
//             int stopsI = dfs(flightmap, totalStops, i, stops + 1, result, visited);
//             if (totalStops == stopsI) // if a valid itenary is found, stop processing other paths. else, continue processing other paths
//                 return stopsI; // solution found. skip to return result.
//             visited[src][i] = false;
//         }
//         result.pop_back();
//         return stops;
//     }

//     vector<string> findItinerary(vector<vector<string>>& tickets) {
//         cout << tickets.size() << endl;
//         map<string, vector<string>> flightmap;

//         for(auto ticket : tickets){
//             flightmap[ticket[0]].push_back(ticket[1]);
//         }

//         for(auto i = flightmap.begin(); i != flightmap.end(); i++){
//             sort(i->second.begin(), i->second.end()); // sort edges for lexical order
//         }

//         vector<string> result;
//         map<string, map<string, bool>> visited;
//         dfs(flightmap, tickets.size(), "JFK" , 0, result, visited);

//         return  result;
//     }
// };