// 703. Kth Largest Element in a Stream

class KthLargest {
    int k;
    priority_queue<int, vector<int>, greater<int>> nums;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto i : nums){
            this->nums.push(i);
        }
    }
    
    // keep maximum k largest elements
    int add(int val) {
        this->nums.push(val);

        while(this->nums.size() > k){
            int x = this->nums.top();
            nums.pop();
        }
        return this->nums.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

