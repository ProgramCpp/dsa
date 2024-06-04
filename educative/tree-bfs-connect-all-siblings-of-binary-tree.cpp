// Function to populate next pointers
void PopulateNextNodePointers(EduTreeNode<int>* root){
	// Write your code here
	queue<EduTreeNode<int>*> traverse;
	traverse.push(root);

	while(!traverse.empty()){
		EduTreeNode<int>* f = traverse.front();
		traverse.pop();
		if(f->left)
			traverse.push(f->left);
		if(f->right)
			traverse.push(f->right);
		if(traverse.size())
			f->next = traverse.front();
	}
}