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
    void solve(TreeNode * root, int low, int high, int &val){
        if(root){
            solve(root->left, low, high,val);
            if(root->val >= low && root->val <= high ) val+=root->val;
            solve(root->right,low, high, val);
        }
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int val = 0 ;

        solve(root, low, high, val);

        return val;

    }
};