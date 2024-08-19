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
    void solve(TreeNode * root, long mini , long maxi, bool  & check){
        if(root){
            if(root->val <= mini || root->val >= maxi){
                check  =false;
                return;
            }
            solve(root->left , mini , root->val, check);
            solve(root->right, root->val , maxi, check);
        }
    }
    bool isValidBST(TreeNode* root) {
        long mini = LONG_MIN , maxi = LONG_MAX;

        bool check  = true;

        solve(root, mini, maxi, check);

        return check;
    }
};