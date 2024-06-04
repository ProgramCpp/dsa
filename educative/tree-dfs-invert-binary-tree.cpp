// Definition for a binary tree node
// template<class T>
// class TreeNode {
// public:
//     T data;
//     TreeNode<T>* left;
//     TreeNode<T>* right;

//     TreeNode(const T data) : data(data), left(nullptr), right(nullptr) {}
// };

TreeNode<int>* MirrorBinaryTree(TreeNode<int>* root){
    if (root == nullptr){
        return nullptr;
    }

    TreeNode<int> *l = MirrorBinaryTree(root->left);
    TreeNode<int> *r = MirrorBinaryTree(root->right);

    TreeNode<int> *t = root -> left;
    root -> left = root -> right;
    root -> right = t;

    return root;
}