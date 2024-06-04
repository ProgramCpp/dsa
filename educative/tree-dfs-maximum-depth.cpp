// Definition for a binary tree node
// template<class T>
// class TreeNode {
// public:
//     T data;
//     TreeNode<T>* left;
//     TreeNode<T>* right;

//     TreeNode(const T data) : data(data), left(nullptr), right(nullptr) {}
// };

int FindMaxDepth(TreeNode<int>* root){
  if (root == nullptr)
    return 0;

  return max(FindMaxDepth(root->left), FindMaxDepth(root -> right)) + 1;
}