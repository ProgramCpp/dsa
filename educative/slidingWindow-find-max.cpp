void Cleanup(deque<int>& maxs, int num) {
    for (deque<int>::iterator it = maxs.end() - 1; it >= maxs.begin(); it--){
        cout << "comparing " << *it << " " << num << endl;
        if (*it < num){
            cout << "removing " << *it << endl;
            nums.erase(it);
        } else
            break;
    }
}

vector<int> FindMaxSlidingWindow(vector<int>& nums, int w) {
    deque<int> maxs;
    vector<int> op = {};

    for (int i = 0; i< w; i++){
        Cleanup(maxs, nums[i]);
        maxs.push_back(nums[i]);
        cout << "adding " << nums[i] << endl;
    }
    op.push_back(maxs.front());


    for (int i = 1; i <= nums.size()- w; i++){
        Cleanup(maxs, nums[i + w -1]);
        maxs.push_back(nums[i + w -1]);
        if (nums[i - 1] == maxs.front()) {
            cout << "pop front" << maxs.front() << endl;
            maxs.pop_front();
        }
        op.push_back(maxs.front());
    }
    
    return op;
}