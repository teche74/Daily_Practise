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
    int sumOfLeftLeaves(TreeNode* root) {
        int res = 0;
        function<void(TreeNode*,TreeNode *)>solve = [&](TreeNode * root , TreeNode  *prev){
            if(root){
                solve(root->left ,root);
                if(!root->left && !root->right){
                    if(prev && prev->left == root){
                        res += root->val;
                    }
                }
                solve(root->right,root);
            }
        };

        solve(root, nullptr);
        return res;
    }
};