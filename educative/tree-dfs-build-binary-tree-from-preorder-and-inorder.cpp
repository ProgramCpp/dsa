// Definition for a binary tree node
// template<class T>
// class TreeNode {
// public:
//     T data;
//     TreeNode<T>* left;
//     TreeNode<T>* right;

//     TreeNode(const T data) : data(data), left(nullptr), right(nullptr) {}
// };

int findInorder(vector<int> &inorder, int data, int s, int e){
    for (int i = s; i <=e; i++){
        if (inorder[i] == data)
            return i;
    }
    return -1;
}

// r must be reference value. both left and right tree modifies it
TreeNode<int>* newTree(vector<int> &preorder, vector<int> &inorder, int& p, int s, int e){
    if (p == preorder.size())
        return nullptr;

    // when dealing with range of elements, check for overlaps
    if (s == e){
        return new TreeNode<int>(inorder[s]);
    }

    if (s > e)
        return nullptr;

    TreeNode<int> *r = new TreeNode<int> (preorder[p]);
    int i = findInorder(inorder, preorder[p], s, e);
    
    p++;r -> left = newTree(preorder, inorder, p, s, i - 1);
    p++;r -> right = newTree(preorder, inorder, p, i + 1, e);

    return r;
}

TreeNode<int>* BuildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
    int p = 0;
    return newTree(preorder, inorder, p, 0, inorder.size()-1);
}