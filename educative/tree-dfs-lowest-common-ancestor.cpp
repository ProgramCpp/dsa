// Definition for a binary tree node
// template<class T>
// class TreeNode {
// public:
//     T data;
//     TreeNode<T>* left;
//     TreeNode<T>* right;

//     TreeNode(const T data) : data(data), left(nullptr), right(nullptr) {}
// };

struct LCA {
    int found;
    TreeNode<int> * lca;
    LCA(int f, TreeNode<int> * l):found(f), lca(l){}
};

LCA FindLCA(TreeNode<int>* root, TreeNode<int>* p, TreeNode<int>* q) {
    if (root == nullptr)
        return LCA(0, nullptr);

    LCA lcal = FindLCA(root-> left, p, q);
    LCA lcar = FindLCA(root-> right, p, q);

    if (lcal.lca)
        return lcal;

    if (lcar.lca)
        return lcar;

    if (lcal.found + lcar.found == 2){
        cout << *root << endl;
        return LCA(2, root);
    }
        

    if (root == p || root == q){
        if (lcal.found || lcar.found){
             cout << *root << endl;
             return LCA(2, root);
        }
        cout << "found " << *root << endl;
        return LCA(1, nullptr);
    }

    if (lcal.found)
        return lcal;

    if (lcar.found)
        return lcar;
        
    return LCA(0, nullptr); // always return non void funtions
}

class Solution {
    public:
        TreeNode<int>* LowestCommonAncestor(TreeNode<int>* root, TreeNode<int>* p, TreeNode<int>* q) {
           LCA a = FindLCA(root, p, q);
           return a.lca;
        }
};
