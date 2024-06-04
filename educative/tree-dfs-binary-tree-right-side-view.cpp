// Definition for a binary tree node
// template<class T>
// class TreeNode {
// public:
//     T data;
//     TreeNode<T>* left;
//     TreeNode<T>* right;

//     TreeNode(const T data) : data(data), left(nullptr), right(nullptr) {}
// };

void rightView(TreeNode<int> * root, int level, vector<int>& l){
    if (root == nullptr)
        return;
    
    if (l.size() < level)
        l.push_back(root -> data);

    rightView(root -> right, level + 1, l);
    rightView(root -> left, level + 1, l);
}


// Function to get the right side view of a binary tree
std::vector<int> RightSideView(TreeNode<int>* root) {
    vector<int> l;
    rightView(root, 1, l);
    return l;
}