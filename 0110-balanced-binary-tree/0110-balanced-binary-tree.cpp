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

    int height(TreeNode * node){
        if(!node) return 0;

        int left =  height(node->left);
        int right = height(node->right);

        return max(left, right ) +1;
    }

    void solve(TreeNode * p , bool  & check){
        if(p){
            solve(p->left, check);
            if( abs(height(p->left) - height(p->right)) > 1 ){
                check =  false;
                return;
            }
            solve(p->right, check);
        }
    }
    bool isBalanced(TreeNode* root) {
        bool  check = true;
        solve(root, check );
        return check; 
    }
};