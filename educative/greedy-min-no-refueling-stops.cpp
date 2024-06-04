#include<queue>

struct station {
    int distance;
    int fuel;
    station(int d, int f) {
        this->distance = d;
        this-> fuel = f;
    }
    bool operator<(const station &s) const{
        return this -> fuel < s.fuel;
    }   
};

int MinRefuelStops(int target, int startFuel, std::vector<std::vector<int>>& stations) {
    if (startFuel >= target) {
        return 0;
    }
    
    priority_queue<station> pStations;
    int stops = 0;
    int d = 0;
    int reachable = startFuel;

    for(int i = 0; i < stations.size() && reachable < target; ){
        if (startFuel - (stations[i][0]-d) < 0 ) {
            stops++;
            station s = pStations.top();
            startFuel = startFuel - (s.distance - d) + s.fuel;
            d = s.distance;
            reachable = d + startFuel;
            pStations.pop();
        } else if(startFuel - (stations[i][0]-d) == 0 ){
            stops++;
            startFuel = startFuel - (stations[i][0] - d) + stations[i][1];
            d = stations[i][0];
            reachable = d + startFuel;
            i++;
        }else {
            pStations.push(station(stations[i][0], stations[i][1]));
            i++;
        }  
            
    }

    cout << reachable;
    while(reachable < target){
        station s = pStations.top();
        startFuel = startFuel - (s.distance - d) + s.fuel;
        d = s.distance;
        reachable = d + startFuel;
        pStations.pop();
        stops++;
    }
    
    return stops;
}