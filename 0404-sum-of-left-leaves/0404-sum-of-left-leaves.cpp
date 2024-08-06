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
    void pre(TreeNode *root , TreeNode * & prev , int  & sum){
        if(root){
            if(prev && prev->left == root && !root->left && !root->right){
                sum+=root->val;
            }
            prev =root;
            pre(root->left,prev,sum);
            pre(root->right,prev,sum);
        }
    } 
    int sumOfLeftLeaves(TreeNode* root) {
        TreeNode * prev = nullptr;
        int sum = 0;

        pre(root,prev,sum);
        return sum;
    }
};