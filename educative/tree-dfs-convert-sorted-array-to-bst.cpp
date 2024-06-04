// Definition for a binary tree node
// template<class T>
// class TreeNode {
// public:
//     T data;
//     TreeNode<T>* left;
//     TreeNode<T>* right;

//     TreeNode(const T data) : data(data), left(nullptr), right(nullptr) {}
// };

TreeNode<int>* buildTree(vector<int> & nums, int low, int high){
    if (low == high)
        return new TreeNode<int> (nums[low]);

    if (high < low)
        return nullptr;

    int mid = low + (high - low)/2; // high-low/ 2 is an offset of the subbarray. add to low

    TreeNode<int> * r= new TreeNode<int> (nums[mid]);
    r -> left = buildTree(nums, low, mid - 1);
    r -> right = buildTree(nums, mid + 1, high);

    return r;
}

TreeNode<int>* SortedArrayToBst(std::vector<int>& nums) {
    
    return buildTree(nums, 0, nums.size()-1);
}