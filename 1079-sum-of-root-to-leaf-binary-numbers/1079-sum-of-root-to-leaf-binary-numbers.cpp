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
    void solve(TreeNode * root, unsigned int &res, unsigned int val){
        if(!root) return ;

        val = val*2 + root->val;

        if(root->left == nullptr && root->right == nullptr){
            res+=val;
        }

        solve(root->left, res, val);
        solve(root->right, res, val);
    }
    int sumRootToLeaf(TreeNode* root) {
        unsigned int res = 0 ,val =0;

        solve(root, res,val);

        return res;
    }
};