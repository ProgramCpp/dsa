// Definition for a binary tree node
// template<class T>
// class TreeNode {
// public:
//     T data;
//     TreeNode<T>* left;
//     TreeNode<T>* right;

//     TreeNode(const T data) : data(data), left(nullptr), right(nullptr) {}
// };


// DiameterOfBinaryTree returns the diameter of tree
bool IsSymmetric(TreeNode<int> *root)
{
    vector<TreeNode<int>*> tree;
    tree.push_back(root);

    for(int i = 0; i <tree.size();){
        int len = tree.size() - i;
        for (int j = 0;j < len; j++){
            if(tree[i + j] && tree[i + len -1 - j] && tree[i + j] -> data != tree[i + len -1 - j]->data)
                return false;
            else if (tree[i+j]== nullptr && tree[i+j] != tree[i + len -1 - j]){
                return false;
            }

            if(tree[i+j]) {
                tree.push_back(tree[i+j] ->left);
                tree.push_back(tree[i+j] ->right);
            }
        }
        i += len;
    }
    return true;
}
/*
alternative solution:
Enqueue left node of the left, right node of the right, right node of the left, and left node of the right in queue.
dequeue two elements and compare
*/