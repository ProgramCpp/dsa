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
            int x = this->nums.top(); // what are you doing with x? just pop
            nums.pop();
        }
        return this->nums.top();
    }
};

/**
 * Your KthLargest object will be instantiated a108nd called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */


//---------------------------------------------

/*
kth highest score is also smallest of top k scores
input the elements into a priority queue (min heap) and keep only k biggest elements and drop the rest
 - if there are k - 1 elements in pq, drop min element and insert new element
access the top / min element in O(1)

why are you dropping the element first before inserting the element? simplify by directly inserting and directly popping - see above solution

*/

class KthLargest {
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this -> k = k;
        for (auto x : nums){
            add(x);
        }
    }
    
    int add(int val) {
            if (pq.size() == k && pq.top() < val){ // pq reached k elements, push the new larger elemnt
                pq.pop();
                pq.push(val);
            } else if (pq.size() == k && pq.top() >= val){ // pq reached k elements, but x is smaller than k elements
                // continue;
            } else { // pq has way lesser than k elements
                pq.push(val); 
            }

        return pq.top();
    }

    /*
    int add(int val) {
        nums.push(val);

        while(nums.size() > k){
            nums.pop();
        }
        return nums.top();
    */
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
