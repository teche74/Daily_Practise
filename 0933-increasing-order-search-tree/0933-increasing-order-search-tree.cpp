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
    void post(TreeNode * root, TreeNode *  &tail){
        if(root){
            post(root->left,tail);
            tail->right  = new  TreeNode(root->val);
            tail=tail->right;
            post(root->right,tail);
        }
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode * res = new TreeNode(-1);
        TreeNode * tail = res;

        post(root,tail);

        return res->right;
    }
};