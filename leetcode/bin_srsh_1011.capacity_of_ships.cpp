// 1011. Capacity To Ship Packages Within D Days

/*
intuition/ proposed solution: minimum ship weight is greater than the average of weights since packages cannot be broken down to fill the whole ship weight. 
check if average weight ships all packages within `days`. increment and repeat until optimal weight.

suggested solution: optimal ship weight = binary search between, maximum weight (or least possible weight) and total weight.
criteria to move low and high for binary search?
    >so after we get less than or eqaul to given days ie we should limit the capacity 
    >ie right = mid
    >and if the days required are more then we have assumed less capacity so we need to increase it
    >ie left = mid + 1

PS: 
find average: O(n)
find optimal ship weight: O(n * n) - for every possible ship weight, see if all the packages can be shipped within `days`. is this the most optimal?
=> O(n^2)

SS:
find max weight: O(n) - the weights are not sorted
find optimal ship weight: O(log n * n) - checking if all packages can be shipped for a given weight cannot be optimized further.

=> (n log n)

optimize SS. binary search between average weight and total weight ?

hint: what are you asked to find? HOW is it a function of the input? all problems have a solution relative to input?
find ship's minimum weight (DP?)
ship's weight is relative to package weights. obviously
when we have a range of values, which is line segment of [min, max], and we know that our answer is somewhere on the line - we can guess it with binary search
*/

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxWeight = 0;
        int totalWeight = 0;

        for (int i=0; i< weights.size(); i++){
            if (maxWeight < weights[i]){
                maxWeight = weights[i];
            }
            totalWeight += weights[i];
        }

        int low, shipWeight, high;
        int minShipWeight = INT_MAX;// result:  the LEAST of the ship weights that can load aall packages within `days`
        low = maxWeight;
        high = totalWeight;
        do {
             
            shipWeight = ((high - low)/2 ) + low; // always sub dividing the range between high and low ensures we arent looping infinitely

            cout << low << ":" << high << ":" << shipWeight << endl;

            int shipLoaded = 0;
            int d = 1;
            int i = 0;
            for(;i < weights.size(); ){
                if(shipLoaded + weights[i] > shipWeight){
                    shipLoaded = 0;
                    d++;
                } else {
                    shipLoaded += weights[i];
                    i++;
                }
            }

            // all packages were loaded AND within the given daays
            if (i == weights.size() && minShipWeight > shipWeight && d <= days){
                minShipWeight = shipWeight;
            }
            cout << "days loaded: " << d << " within days: " << days << endl;
            if (d > days) {
                low  = shipWeight + 1; // increase ship's weight. need to ship in lesser days
            } else {
                high = shipWeight - 1;// decrease ship's weight
            }

        }while ( low <= high); // compute when both high and low are same

        return minShipWeight;
    }
};

/*
- minShipWeight to be updated ONLY when all packages are shipped within `days`
- if multiple shipweights can ship all packages within `days`, pick the one with least weight
- pick sub range of weight in each iteration based on the number of days taken to ship all thhe packages - dont terminate shipping as soon as days are reached.
- the same range is not computed over and over again because once the range is discarded, it is never considered again- new low is always higer than the previous one. new high is always loweer than the previous one.
- compute when both high and low are same. min ship weight is in the inclusive range of weights
*/