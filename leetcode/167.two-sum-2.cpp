// 167. two sum 2: input array is sorted


/*
two-sum: numbers are not sorted. in which case, you first sort. OR maintain a map of the reminders and the corresponding index of operand. look up the map if the 2nd operand is the reminder
two-sum-2:
trace i from front anf j from back. until the sum equals target, inc i if sum of ith and jth is less than target. dec j if the sum is greater than target
why? ex: if the target is bigger. moving j left would only make the target smaller. moving in that direction wont give the target. move i right to make the target bigger
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;
        while (i < j && numbers[i] + numbers[j] != target){
            if(numbers[i] + numbers[j] > target)
                j--;
            if(numbers[i] + numbers[j] < target)
                i++;

        }
        return vector<int>({i + 1, j + 1});
    }
};