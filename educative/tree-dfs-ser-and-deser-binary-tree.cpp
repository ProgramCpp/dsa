// Definition for a binary tree node
// template<class T>
// class TreeNode {
// public:
//     T data;
//     TreeNode<T>* left;
//     TreeNode<T>* right;

//     TreeNode(const T data) : data(data), left(nullptr), right(nullptr) {}
// };

void Ser(TreeNode<int> *root, vector<string> &ser){
    if (root == NULL) {
        ser.push_back("*"); // need placeholders for empty branches
        return;
    }
    ser.push_back(to_string(root -> data));
    Ser(root -> left, ser);
    Ser(root -> right, ser);
}

// Function to serialize tree into list of integers.
vector<string> Serialize(TreeNode<int> *root){
    vector<string> ser;
    Ser(root, ser);
    return ser;
}

TreeNode<int>* Deser(vector<string> & stream, int &i){
    if (stream[i] == "*"){
        i++;
        return NULL;
    }

    TreeNode<int> * root = new TreeNode<int>(stoi(stream[i]));
    i++;
    if(i == stream.size())
        return root;
    root -> left = Deser(stream, i);
    if(i == stream.size())
        return root;
    root -> right = Deser(stream, i);
    return root;
}

// Function to deserialize integer list into a binary tree.
TreeNode<int> *Deserialize(vector<string> &stream){
    int i = 0;
    return Deser(stream, i);
}