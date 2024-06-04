#include <limits.h>

int TwoCityScheduling(vector<vector<int>> &costs)
{
    sort(costs.begin(), costs.end(), [](vector<int>& a, vector<int>& b){
       return a[0]-a[1] < b[0]-b[1];
    });
    
    int n = costs.size()/2;
    int totalCost = 0;
    for (int i = 0; i < n; i++){
        totalCost += costs[i][0] + costs[i+n][1];
    }

    return totalCost;
}