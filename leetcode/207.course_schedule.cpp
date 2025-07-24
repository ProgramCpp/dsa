/* 207. course schedule
intuition: the courses have dependency relationships like a graph.
a cycle means it is not possible to finish all courses.
the graph is not connected

*/

// reuse already computed values
class Solution {
public:
    bool dfs(int src, int courses, map<int, vector<int>> &adjList, map<int, bool> &visited, map<int, bool> &seen){
        if(seen[src])
            return false;

        if(visited[src])
            return true;// if cycle was detected, dfs terminates immediately. only valid value is true

        visited[src] = true;
        seen[src] = true;
        cout << "visited " << src << endl;
        for(auto i : adjList[src]){
            if(!dfs(i, courses, adjList, visited, seen))
                return false;
        }
        seen[src] = false;
        cout << "unvisited " << src << endl;

        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, bool> visited;
        map<int, bool> seen;

        map<int, vector<int>> adjList;

        for(auto i : prerequisites){
            adjList[i[0]].push_back(i[1]);
        }
        
        // disconnected graphs
        for(int i = 0; i < numCourses; i++){
            cout << "calling dfs " << i << endl;
            if(!dfs(i, numCourses,  adjList, visited, seen))
                return false;
        }

        return true;
    }
};

// TLE
// class Solution {
// public:
//     bool dfs(int src, int courses, map<int, vector<int>> &adjList, map<int, bool> &visited){
//         if(visited[src])
//             return false;

//         visited[src] = true;
//         cout << "visited " << src << endl;
//         for(auto i : adjList[src]){
//             if(!dfs(i, courses, adjList, visited))
//                 return false;
//         }
//         visited[src] = false;
//         cout << "unvisited " << src << endl;

//         return true;
//     }

//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         map<int, bool> visited;

//         map<int, vector<int>> adjList;

//         for(auto i : prerequisites){
//             adjList[i[0]].push_back(i[1]);
//         }
        
//         for(int i = 0; i < numCourses; i++){
//             cout << "calling dfs " << i << endl;
//             if(!dfs(i, numCourses,  adjList, visited))
//                 return false;
//         }

//         return true;
//     }
// };