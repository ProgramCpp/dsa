/* 210. Course Schedule II
use topological sort to traverse dependencies first

*/


class Solution {
public:
    vector<int> dfs(int src, map<int, vector<int>> &adjList, map<int, bool> &visited, map<int, bool> &seen){
        if(seen[src])
            return vector<int>(); // impossible to finish all courses

        vector<int> result;
        seen[src] = true;
        for(auto i : adjList[src]){
            // all connected courses are already in the result
            if(visited[i])
                continue;

            vector<int> res = dfs(i, adjList, visited, seen);
            if(res.empty())
                return res;// impossible to finish all courses
            result.insert(result.end(), res.begin(), res.end()); // order matters
        }
        seen[src] = false;
        result.push_back(src); // topo sort. prerequisites come first
        visited[src] = true;

        return result;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> adjList;

        for(auto i: prerequisites){
            adjList[i[0]].push_back(i[1]);
        }

        map<int, bool> seen;
        map<int, bool> visited;

        vector<int> result;
        for(int i = 0; i < numCourses; i++){
            // all connected courses are already in the result
            if(visited[i])
                continue;
            vector<int> res = dfs(i, adjList, visited, seen);
            if(res.empty())
                return res;// impossible to finish all courses
            result.insert(result.end(), res.begin(), res.end());
        }

        return result;
    }
};