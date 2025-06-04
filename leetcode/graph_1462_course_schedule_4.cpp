// 1462. Course Schedule IV
// proposed soln: 
// you can start from the target course and work way up to the given preriquisite course
// or, you can work forwards from the prerequisite course. build a map for easy lookup
// given hints: (visualize the dependencies! a graph)
// a course can have multiple prerequites. BFS
// build a 2d array for every pair of course to avoid recomputation for every query

// adj mat or list for BFS? a list is fine, there is no repeated tracing.

// suggested  soln(S): build adj matrix and then build isReachable and then answer queries
// proposed soln(P): is that faster than just answering the queries directly?

/*
m : num of courses
n : num of prereq = m ^ 2 // N*(N-1) is number of edges in directed graph. Number of edge in undirected graph is (N * (N-1)) / 2 [nC2]
q : num of queries 
S: O(n) + O(m * m-1) + O(q) => O(m^2)
P: O(q * m * m-1) => O(q * m ^2). note the queries are the largest 10^4. optimize for queries

S, although it has more steps
m^2 is still bad. but cannot optimize for that. pre computation helps repeating the computation for q queries
*/

// Topological Sort - Kahn's Algorithm & Floyd Warshall Algorithm

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // a 2d map of all combinations of courses to indicate whether a course is a prereq of the other
        vector<vector<bool>> prereqs(numCourses, vector<bool>(numCourses, false));

        // all courses for which a course is a prereq
        map<int, vector<int>> indirectPrereqs; // adj list

        for (int i = 0; i < prerequisites.size(); i++){
            if (indirectPrereqs.find(prerequisites[i][0]) == indirectPrereqs.end())
                indirectPrereqs[prerequisites[i][0]] = vector<int>();    
            indirectPrereqs[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for(int i = 0; i < numCourses; i++){
            vector<int> nextCourse;
            nextCourse.insert(nextCourse.end(),indirectPrereqs[i].begin(), indirectPrereqs[i].end());
            while(!nextCourse.empty()){
                int nc = nextCourse.front();
                nextCourse.erase(nextCourse.begin());
                if (!prereqs[i][nc]) { // optimization. already processed. this fixed TLE
                    prereqs[i][nc] = true;
                    nextCourse.insert(nextCourse.end(),indirectPrereqs[nc].begin(), indirectPrereqs[nc].end());
                }
                
            }
        }

        vector<bool> result(queries.size(), false);
        for (int i = 0; i < queries.size(); i++){
            auto q = queries[i];
            if (prereqs[q[0]][q[1]])
                result[i] = true;
        }

        return result;
    }
};