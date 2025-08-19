/* 1049. Last Stone Weight II
smallest stone must be left. y may not be destroyed initially. but after a smash, whatever is left over could be completely destroyed.
what happens if you smash sequentially? vs a different order? 
for the given example, sequentially smashing stones, gives a result of 7. while the solution is 1.
what is the minimizing strategy? bigger number must smash the bigest number possible?
what about sort and smash sequentially?
given ex when sorted: 1, 1, 2, 4, 7, 8
1 - 1. 4-2. 7-2. 8-5 = 3
or. subtract pairs.
1-1. 4-2. 8-7 = 0, 2, 1. 2-1 = 1
ex: [31, 26, 33, 21, 40] odd pairs dont work. 40+33-31-26-21 = 5. sorted: [21, 26, 31, 33, 40] greedy picks 40+31+21-33-26 = 33. 

brute force. try every combination. a number with + and -.
=> O(2^n)
how does adding a new stone change the solution?
a set of stones with different combinations give a  set of results, of which the minimum value can be picked. when a new stone is introduced, add & subtract the new stone value to all these values and then pick the result.

how to store the results of stones?
each combination produces an unique result.

hint:  it can always be presented as (+/-)a(+/-)b(+/-)c, there is no other symbols. And you can always separate the stones to two groups by their symbols. Then you would get something as sum(group1)-sum(group2), and what makes the result closer to zero would be the correct answer. i.e, finding the minimum difference between the sum of two groups

hint: some stones get subtracted by other stones. group stones into 2 set, one with +ve sign and the other with -ve sign. bring the sum of each group of stones close to half the total value so that the difference is minimum.
=> O(2^n)


hint: bounded knapsack problem

so essentially partition sub set. but find the max sum possible. the remaining diff is the result

!!!!!! CAUTION !!!!!!! 
do not attempt to solve by starting from total and subtracting all the way to 0.
please dont ask me why. goes without saying, its too painful to talk about :pray:.
*/

class Solution {
public:
    void lsw(vector<int> & stones, int index, int n, int sum, int total, vector<vector<int>> &sums, int &maxSum){
        if(sum > total){
            return;
        }

        if(sums[index][sum] != -1)
            return;

        sums[index][sum] = 1;

        maxSum = max(maxSum, sum);

        if(index == n) // no more stones
            return;

        lsw(stones, index + 1, n, sum, total, sums, maxSum);
        lsw(stones, index + 1, n, sum + stones[index], total, sums, maxSum);
    }

    int lastStoneWeightII(vector<int>& stones) {
        int total =  accumulate(stones.begin(), stones.end(), 0);

        vector<vector<int>> sums(stones.size() + 1, vector<int>(total/2 + 1, -1));
        int maxSum = 0;
        lsw(stones, 0, stones.size(), 0, total/ 2, sums, maxSum);

        return total - 2 * maxSum;
    }
};

// 1. whats the formula for remaining weight of stones
// 2. total is made only after picking the stone

// void lsw(vector<int> &stones, int index, int n, int total, vector<vector<int>> &sums, int &minSum) {
//     if (total < 0) return;
//     if (index == n) return;
//     if (sums[index][total] != -1) return;

//     sums[index][total] = 1;
//     minSum = min(minSum, total);

//     // skip
//     lsw(stones, index + 1, n, total, sums, minSum);
//     // take
//     lsw(stones, index + 1, n, total - stones[index], sums, minSum);
// }

// int lastStoneWeightII(vector<int>& stones) {
//     int S = accumulate(stones.begin(), stones.end(), 0);
//     int target = S / 2;

//     vector<vector<int>> sums(stones.size(), vector<int>(target + 1, -1));
//     int minSum = INT_MAX;
//     lsw(stones, 0, stones.size(), target, sums, minSum);

//     return 2 * minSum;
// }
