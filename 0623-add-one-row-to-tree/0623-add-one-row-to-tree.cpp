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
    TreeNode* addOneRow(TreeNode* root, int val, int depth , int curr_depth = 1) {
        if(depth == 1){
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        if(!root) return nullptr;
        
        if(curr_depth  == depth-1){
            TreeNode * temp_left = root->left;
            TreeNode* temp_right  =root->right;

            root->left = new TreeNode(val);
            root->right = new TreeNode(val);
            root->left->left = temp_left;
            root->right->right = temp_right;
        }else{
            root->left = addOneRow(root->left, val, depth, curr_depth + 1);
            root->right = addOneRow(root->right, val, depth, curr_depth + 1);
        }
        return root;
    }
};