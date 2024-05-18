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
    void inorder(TreeNode* root, TreeNode* & res){
        if(root!=nullptr){
            inorder(root->left, res);
            res->right = new TreeNode(root->val);
            res = res->right;
            inorder(root->right, res);
        }
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode * res =new TreeNode();
        TreeNode * tail = res;
        inorder(root, tail);
        return res->right;
    }
};