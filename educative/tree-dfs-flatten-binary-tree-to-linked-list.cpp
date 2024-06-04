// Definition for a binary tree node
// template<class T>
// class TreeNode {
// public:
//     T data;
//     TreeNode<T>* left;
//     TreeNode<T>* right;

//     TreeNode(const T data) : data(data), left(nullptr), right(nullptr) {}
// };

TreeNode<int> *FlattenTree(TreeNode<int> *root){
    if (root == NULL)
        return NULL;

    // ######## incorrect solution ######

    // queue<TreeNode<int>*> nodes;
    // nodes.push(root);

    // TreeNode<int> *l = NULL;

    // while(!nodes.empty()){
    //     TreeNode<int> *t = nodes.front();
    //     nodes.pop();

    //     if(t -> left != NULL)
    //         nodes.push(t->left);
    //     if(t -> right != NULL)
    //         nodes.push(t->right);

    //     t -> left = NULL;
    //     t -> right = l;
    //     l = t;
    // }

    TreeNode<int> *left = FlattenTree(root->left);
    TreeNode<int> *right = FlattenTree(root->right);

    root -> left = NULL;
    root -> right = left;
    if (left != NULL){
        while(left -> right != NULL)
            left = left -> right;
        left -> right = right;
    }
    else 
        root -> right = right;
    return root;
}


/*

For every node, check whether or not it has a left child. If it does not have a left child, we move to the right child.

Otherwise, find the node on the rightmost branch of the left subtree that does not have a right child.

Once we find this rightmost node, connect it with the right child of the current node. After connecting, set the right child of the current node to the left child of the current node.

Finally, set the left child of the current node to NULL.

Repeat the process until the given binary tree becomes flattened.


*/