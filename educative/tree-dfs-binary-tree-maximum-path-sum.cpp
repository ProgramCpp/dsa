// Definiton of a binary tree node class
// class TreeNode<T> {
//     T data;
//     TreeNode<T> left;
//     TreeNode<T> right;

//     TreeNode(T data) {
//         this.data = data;
//         this.left = null;
//         this.right = null;
//     }
// }

#include<climits>

struct tMaxSum{
    int nodeMax;
    int max;
    tMaxSum(int n, int m):nodeMax(n), max(m){}
};

tMaxSum maxSum(TreeNode<int> * root){
    if (root == nullptr)
        return tMaxSum(0,INT_MIN);

    tMaxSum l = maxSum(root -> left);
    tMaxSum r = maxSum(root -> right);
 
    int m = max(root -> data, max(l.nodeMax, r.nodeMax) + root -> data);
    return tMaxSum(m, max(l.nodeMax + r.nodeMax + root -> data, max(l.max, r.max)));
}

int MaxPathSum(TreeNode<int>* root){
    tMaxSum s = maxSum(root);
    return s.max;
}