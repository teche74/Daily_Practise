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
    void solve(TreeNode * root, TreeNode * & prev , int  &res){
        if(root){
            solve(root->left, prev, res);
            if(prev){
                res = min(res,  root->val - prev->val);
            }
            prev = root;
            solve(root->right,prev,res);
        }
    }
    int minDiffInBST(TreeNode* root) {
        int res = INT_MAX;
        TreeNode * prev = nullptr;
        solve(root, prev, res);
        return res;
    }
};