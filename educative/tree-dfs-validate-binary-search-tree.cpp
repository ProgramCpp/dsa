// Definition for a binary tree node
// template<class T>
// class TreeNode {
// public:
//     T data;
//     TreeNode<T>* left;
//     TreeNode<T>* right;

//     TreeNode(const T data) : data(data), left(nullptr), right(nullptr) {}
// };

#include <climits>

// inorder traversal to check the order of elements
int isValid(TreeNode<int> *root, int& cur){
    if (!root)
        return true;

    if (!isValid(root -> left, cur))
        return false;

    if (root -> data < cur)
        return false;

    cur = root -> data;

    return isValid(root -> right, cur);
}

int ValidateBst(TreeNode<int>* root)
{
    // if (root == nullptr)
    //     return true;

    // if (root -> left && root -> data < root-> left -> data)
    //     return false;
    
    // if (root -> right && root -> data > root -> right -> data)
    //     return false;

    // return ValidateBst(root->left) && ValidateBst(root->right);


    // above solution: valid  BST if for each node, left is smaller than root and right is bigger than root.
    int cur = INT_MIN;
    return isValid(root, cur);
}