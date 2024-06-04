EduTreeNode<int>* PopulateNextPointers(EduTreeNode<int>* root) {
    queue<EduTreeNode<int>*> q;
    if (root)
        q.push(root);

    while(!q.empty()){
        int len = q.size();
        for(int i = 0; i < len; i++){
            EduTreeNode<int>* node = q.front();
            q.pop();
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
            if (!q.empty() && i < len -1){// the right most node at each level must be null
                node->next = q.front();
            } else
                node->next = nullptr;
        }
    }
    
    return root;
}