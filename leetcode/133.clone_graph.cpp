/*133. Clone Graph
traverse until all nodes are visited. keep track of nodes cloned and reuse.
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* clone(Node *node, map<int, Node*> &visited){
        if(node == NULL) // not possible
            return node;

        if(visited[node -> val] != NULL)
            return visited[node->val];

        Node* n = new Node(node -> val);
        visited[node -> val] = n;

        for(auto i: node -> neighbors){
                n->neighbors.push_back(clone(i, visited));
        }

        return n;
    }
    Node* cloneGraph(Node* node) {
        map<int, Node*> visited;
        return clone(node, visited);
    }
};