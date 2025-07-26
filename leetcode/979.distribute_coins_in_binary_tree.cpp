/* 979. distribute coins in binary tree
intuition:
the coins will be distributed from the nearest pool, since the problem asks for minimum moves
hint: every node can have only one coin and pass on the remmaining to child or parent
a coin requires 1 move to move between parent and children. two moves between siblings. choose min number of jumps.
a coin moving from a sibling to another takes 2 moves. similarly, a parent passing down a coin to one child and receiving coin from another child requires 2 moves.
start from leaf and if a node does not have a coin, inc moves to the parent until a parent or a sibling has a coin.
if a node has more than one coin, pass on the remaining coins to the parent
solution:
traverse the tree and maintain moves and extra coins. at every node, adjust the coin distribution.
suggested solution: use one variable to track extra coins and required coins
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// at every node, return tuple <extra coins, required coins and the number of moves>
// ex: the same number of required coins when moves 2 levels up, gives moves * required coins
struct coins {
    int moves, reqdCoins, extraCoins;
    coins(): moves(0), reqdCoins(0), extraCoins(0){}
    coins(int m, int r, int e): moves(m), reqdCoins(r), extraCoins(e){}
};

class Solution {
public:
    coins dC(TreeNode *root){
        if(root == NULL)
            return coins();

        coins lc = dC(root -> left);
        coins rc = dC(root -> right);

        // redistribute
        int moves = 0;
        // insufficient
        int reqdCoins = 0;
        // remaining 
        int extraCoins = 0; // HINT: only reqdcoins or extra coins can be non-zero

        if(lc.moves)    
            moves += lc.moves;
        
        if(rc.moves)    
            moves += rc.moves;

        // compute extra coins
        if (lc.extraCoins){ 
             extraCoins += lc.extraCoins;
             moves += lc.extraCoins; // extra coins move to parent
        }

        // HINT: club all extra coins since it doesnt matter which child has extra coins
        if (rc.extraCoins){ 
             extraCoins += rc.extraCoins;
             moves += rc.extraCoins;
        }
       
        if(root -> val > 1)
            extraCoins += root -> val - 1;

        // compute required coins
        if (lc.reqdCoins){ 
             reqdCoins += lc.reqdCoins;
             moves += lc.reqdCoins; // all reqd coins move one level up to parent
        }

        if (rc.reqdCoins){ 
             reqdCoins += rc.reqdCoins;
             moves += rc.reqdCoins;
        }

        // reallocate extra coins to required coins
        if(reqdCoins && extraCoins){ 
            if(reqdCoins > extraCoins){
                // moves += extraCoins; // reqd coins count moves to parent. just allocte coins
                reqdCoins -= extraCoins;
                extraCoins = 0;
            } else{
                // moves += reqdCoins;
                extraCoins -= reqdCoins;
                reqdCoins = 0;
            }
        }

        // handling root required coins separately since it does nnot require any moves
        if (root -> val == 0){
            if(extraCoins){
                extraCoins--;
            } else{
                reqdCoins++;
            }
        }
        

        return coins(moves, reqdCoins, extraCoins);
    }

    int distributeCoins(TreeNode* root) {
        coins c = dC(root);
        // at the root, the extra coins and required coins must be zero as per prob stmt
        return c.moves;
    }
};