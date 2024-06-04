// Definition for a binary tree node
// template<class T>
// class TreeNode {
// public:
//     T data;
//     TreeNode<T>* left;
//     TreeNode<T>* right;

//     TreeNode(const T data) : data(data), left(nullptr), right(nullptr) {}
// };

//return multiple values
struct Dia {
    int diameter; // max diameter must be passed across callstacks
    int height;
    Dia(int d, int h): diameter(d), height(h){}
};

Dia dia(TreeNode<int> *root){
    if (root == NULL){
        return Dia(0, 0);
    }

    Dia l = dia(root -> left);
    Dia r = dia(root -> right);

    int d = max(l.height + r.height, max(l.diameter, r.diameter)); // max(c, max(a, b));
    int h = max(l.height, r.height) + 1;
    return Dia(d, h);
}


// DiameterOfBinaryTree returns the diameter of tree
int DiameterOfBinaryTree(TreeNode<int> *root)
{
    return dia(root).diameter;
}