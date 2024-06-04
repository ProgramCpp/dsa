// house robber 3

/*
level order of tree. either include parent or exclude parent.
max(parent included, children included)
both right and left child may be included or not. pick max. no need to pick/ exclude both
can cache results for a given node
*/ 

// Definition for a binary tree node
// template<class T>
// class TreeNode {
// public:
//     T data;
//     TreeNode<T>* left;
//     TreeNode<T>* right;

//     TreeNode(const T data) : data(data), left(nullptr), right(nullptr) {}
// };

int robAll(TreeNode<int>* root, bool included){
  if (root == NULL)
    return 0;

  int value = 0;

  // do u see the repeated robAll functions? optimize and call them once
  if (included){
    value += root -> data;
    value += robAll(root->left, false);
    value += robAll(root->right, false);
  } else{
    value += max(robAll(root->left, true), robAll(root->left, false));
    value += max(robAll(root->right, true), robAll(root->right, false));
  }

  return value;
}

int Rob(TreeNode<int>* root){
  return max(robAll(root, true), robAll(root, false));
}


