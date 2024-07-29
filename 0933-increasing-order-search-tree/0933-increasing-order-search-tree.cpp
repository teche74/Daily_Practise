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
    void solve(TreeNode * root , TreeNode *  & tail ){
        if(root){
            solve(root->left,tail);
            tail->right = new TreeNode(root->val);
            tail->left = nullptr;
            tail=tail->right;
            solve(root->right,tail);
        }
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode * new_root = new TreeNode(-1);
        TreeNode * tail = new_root;

        solve(root, tail);

        return new_root->right;
    }
};