#include <deque>

using namespace std;
typedef TreeNode<int>* NodePtr;

vector<vector<int>> ZigzagLevelOrder(TreeNode<int>* root){
    vector<vector<int>> zigzagOrder;
    if (!root)
        return zigzagOrder;
        
    deque<TreeNode<int>*> q;
    bool forward = true;
    q.push_front(root);

    while(!q.empty()){
        int len = q.size();
        vector<int> levelOrder;
        for(int i = 0; i < len; i++){
            if (forward){
                TreeNode<int> * element = q.front();
                q.pop_front();
                levelOrder.push_back(element -> data);
                if (element->right)
                    q.push_front(element->right);
                if (element->left)
                    q.push_front(element->left);
            } else{
                TreeNode<int> * element = q.back();
                q.pop_back();
                levelOrder.push_back(element -> data);
                if (element->left)
                    q.push_back(element->left);
                if (element->right)
                    q.push_back(element->right);
            }
        }
        forward = !forward;
        zigzagOrder.push_back(levelOrder);
    }

    return zigzagOrder;
}