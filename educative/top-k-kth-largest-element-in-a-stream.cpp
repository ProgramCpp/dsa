class KthLargest{
    public:
    int k;
    //priority_queue<int, vector<int>, greater<int>> ele;
    // min heap to remove min elements. to drop the smallest elements and retain k largest elements
    // the top element is the smallest of k largest elements so far.
    priority_queue<int, vector<int>, greater<int>> ele;
    
    // constructor to initialize heap and add values in it
    KthLargest(int K, vector<int> nums):k(K) {
        for(vector<int>::const_iterator it = nums.begin(); it != nums.end(); it++){
            ele.push(*it);
            if (ele.size() > K){
                ele.pop();
            }
        }
    }

    // adds element in the heap
    void Add(int val){
        ele.push(val);
        if (ele.size() > k){
            ele.pop();
        }
    }

    // returns kth largest element from heap
    int ReturnKthLargest(){
        // Replace this placeholder return statement with your code
        return ele.top();
    }
};
