#include <set>

int NumberOfPaths(int n, std::vector<std::vector<int>>& corridors){
    // simply use a vector instead of set!
    vector<vector<int>> rooms(n+1);

    int cycles = 0;
    for(vector<int> & c: corridors){
        map<int, bool> found;
        for(vector<int>::iterator i=rooms[c[0]].begin(); i != rooms[c[0]].end(); i++){
            found[*i]=true;
        }
        for(vector<int>::iterator i=rooms[c[1]].begin(); i != rooms[c[1]].end(); i++){
            if(found[*i]){
                cycles++;
            }
        }

        rooms[c[0]].push_back(c[1]);
        rooms[c[1]].push_back(c[0]);
    }

    return cycles;
}