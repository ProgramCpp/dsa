vector<int> NextGreaterElement(vector<int> nums1, vector<int> nums2)
{  
    stack<int> orderedNums;
    map<int, int> nextGreatestNum;

    for(auto i = nums2.begin(); i != nums2.end(); i++){
        while(!orderedNums.empty()){
            int n = orderedNums.top();
            if(n < *i){
                nextGreatestNum[n] = *i;
                orderedNums.pop();
            } else
                break;
        }
        orderedNums.push(*i);
    }

    vector<int> result;
    for(auto i = nums1.begin(); i != nums1.end(); i++){
        if(nextGreatestNum.find(*i) != nextGreatestNum.end()){
            result.push_back(nextGreatestNum[*i]);
        } else
            result.push_back(-1);
    }

    return result;
}
