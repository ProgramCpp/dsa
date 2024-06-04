Node* cloneGraph(Node * root, map<int, Node*>& nodes){
    if (root == NULL)
        return root;

    if(nodes.find(root->data)!= nodes.end())
        return nodes[root->data];
        
    Node *graph = new Node(root->data);
    // graph -> data = root -> data;

    nodes[root->data] = graph;

    // nodes that are neighbours of multiple nodes will be visited again n again
    // resulting in infinite loop (neighbours are two way)
    for(Node *n: root ->neighbors){
        graph->neighbors.push_back(cloneGraph(n, nodes));
    }

    return graph;
}

Node* Clone(Node* root) {
    map<int, Node*> nodes;
    return cloneGraph(root, nodes);
}