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
class Solution {
public:
    bool solve(TreeNode * x , TreeNode * y){
        if(!x && !y) return true;
        if(!x || !y) return false;

        if(x->val != y->val) return false;

        bool flip = solve(x->right,y->left) && solve(x->left,y->right);
        bool noflip = solve(x->left,y->left) && solve(x->right,y->right);

        return flip || noflip; 
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return solve(root1, root2);
    }
};