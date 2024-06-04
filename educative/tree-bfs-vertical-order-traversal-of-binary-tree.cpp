// Definition for a binary tree node
// template<class T>
// class TreeNode {
// public:
//     T data;
//     TreeNode<T>* left;
//     TreeNode<T>* right;

//     TreeNode(const T data) : data(data), left(nullptr), right(nullptr) {}
// };

struct Node {
  TreeNode<int> *node;
  int offset;
  Node(TreeNode<int> *n, int o):node(n),offset(o){}
};

std::vector<std::vector<int>> VerticalOrder(TreeNode<int> *root){
  map<int, vector<int>> verticalOrder;
  queue<Node> q;

  if(root)
    q.push(Node(root, 0));

  while(!q.empty()){
    Node node = q.front();
    q.pop();
    verticalOrder[node.offset].push_back(node.node->data);
    if(node.node->left)
      q.push(Node(node.node->left, node.offset -1));

    if(node.node->right)
      q.push(Node(node.node->right, node.offset +1));
  }

  vector<vector<int>> verticalOrders;
  for(map<int, vector<int>>::iterator i = verticalOrder.begin(); i != verticalOrder.end(); i++){
      verticalOrders.push_back(i->second);
  }

  return verticalOrders;
}