#include <iostream>
#include <vector>
#include <queue>

struct Stop{
    int station;
    int buses;
    Stop(int s, int b): station(s), buses(b){}
};

int MinimumBuses(vector<vector<int>> busRoutes, int src, int dest)
{   
    // non-weighted adjacency list
    map<int, vector<int>> graph;

    for(vector<int> route: busRoutes){
        for(vector<int>::iterator i = route.begin(); i != route.end() - 1; i++){
            for(vector<int>::iterator j = i + 1; j != route.end(); j ++){
                graph[*i].push_back(*j);
                graph[*j].push_back(*i);
            }
        }
    }

    queue<Stop> ride;
    map<int, bool> visited; // in graphs, always beware of infinite cycles!

    ride.push(Stop(src, 0));
    visited[src] = true;

    while(!ride.empty()){
        Stop stn = ride.front();
        ride.pop();
        if (stn.station == dest)
            return stn.buses;

        for(int nextStn: graph[stn.station]){
            if(!visited[nextStn]){
                ride.push(Stop(nextStn, stn.buses + 1));
                visited[nextStn]=true;
            }
                
        }
    }

    return -1;
}