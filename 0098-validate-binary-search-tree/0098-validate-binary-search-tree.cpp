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
    bool check = true;
    void solve(TreeNode *root, long long mini , long long maxi){
        if(root){
            solve(root->left,mini,root->val);
            if(root->val <= mini || root->val >= maxi){
                check =false;
                return ;
            }
            solve(root->right,root->val,maxi);
        }
        return ;
    }
    bool isValidBST(TreeNode* root) {
        long long mini = LONG_MIN, maxi = LONG_MAX;
        solve(root,mini,maxi);

        return check;
    }
};