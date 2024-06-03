// 2519. Count the Number of K-Big Indices

/*
count = 0
for i = k to n - k
    push 0 to k - 1 to min heap
    push n - k + 1 to n to min heap
    pop heap k times and check it is smaller than nums[i]
    increment count if k elements are smaller than nums[i]


O(n log k)
for each ith element, inserting/ deleting into tree of size k => log k. lookup in o(1)
*/

class Solution {
public:
    int kBigIndices(vector<int>& nums, int k) {
        
    }
};