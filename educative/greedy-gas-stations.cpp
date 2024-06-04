#include <iostream>
#include <vector>

int sum(vector<int>::iterator s, vector<int>::iterator e) {
    int sum =0;
    for(;s != e; s++){
        sum += *s;
    }
    return sum;
}

int GasStationJourney(vector<int> gas, vector<int> cost)
{
    if (sum(gas.begin(), gas.end()) < sum(cost.begin(), cost.end())) 
        return -1;

    int gasSoFar = 0;
    int startingPoint = 0;
    for(int i =0; i < gas.size(); i++) {
        gasSoFar += (gas[i] - cost[i]);
        if (gasSoFar < 0) {
            gasSoFar = 0;
            startingPoint = i+1; // we dont check from starting point back to the starting point. since we already checked the sum of all costs is less than sum of all gas units
        }
    }

    return startingPoint;
}