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
    TreeNode * checkpoint ;
    void solve(TreeNode * root, int  & count, int prev ){
        if(root){
            if(root->val >= prev ){
                count++;
            }
            prev = max(prev ,root->val);
            solve(root->left, count,prev);
            if(root == checkpoint){
                prev = checkpoint->val;
            }
            solve(root->right, count, prev);
        }
    }
    int goodNodes(TreeNode* root) {
        int count = 0 ,prev =INT_MIN;
        checkpoint = root;
        solve(root, count, prev);

        return count;
    }
};