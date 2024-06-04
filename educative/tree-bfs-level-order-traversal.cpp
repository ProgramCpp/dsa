#include <iostream>
#include <iostream>
#include <vector>

// Definition for a binary tree node
// template<class T>
// class TreeNode {
// public:
//     T data;
//     TreeNode<T>* left;
//     TreeNode<T>* right;

//     TreeNode(const T data) : data(data), left(nullptr), right(nullptr) {}
// };

struct node {
	TreeNode<int> * n;
	int level;
	node(TreeNode<int> *n, int level):n(n), level(level){}
};

string LevelOrderTraversal(TreeNode<int>* root)
{
	if (root == nullptr)
		return "None";

	string levelOrder = "";
	queue<node> tree;
	tree.push(node(root, 0));
	int level = 0;

	while(!tree.empty()){
		node t = tree.front();
		tree.pop();

		if(t.level > level){
			level++;
			levelOrder = levelOrder + " : ";
		}else if(levelOrder != "")
			levelOrder = levelOrder + ", ";

		levelOrder = levelOrder + to_string(t.n->data);

		if (t.n->left)
			tree.push(node(t.n->left, t.level + 1));

		if(t.n->right)	
			tree.push(node(t.n->right, t.level + 1));

	}
	return levelOrder;
}
// better solution to track the borders on level: 
// 	mark the number of elements in queue before processing the current level