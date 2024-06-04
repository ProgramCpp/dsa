// 167. two sum 2: input array is sorted

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