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
    void solve(TreeNode * root, TreeNode* & res){
        if(root!= nullptr){
            solve(root->left,res);
            res->right = new TreeNode(root->val);
            res =res->right;
            solve(root->right,res);
        }
    }
    TreeNode* increasingBST(TreeNode* root) {
        if(!root) return nullptr;
        TreeNode * res = new TreeNode(-1);
        TreeNode *tail =res;
        solve(root, tail);

        return res->right;
    }
};