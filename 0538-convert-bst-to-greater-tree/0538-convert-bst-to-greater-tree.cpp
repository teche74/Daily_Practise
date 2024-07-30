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
    void reverse_inorder(TreeNode * & root, int & sum){
        if(root){
            reverse_inorder(root->right,sum);
            sum+=root->val;
            root->val = sum;
            reverse_inorder(root->left,sum);
        }
    }
    TreeNode* convertBST(TreeNode* & root) {
        int sum = 0;
        reverse_inorder(root,sum);

        return root;
    }
};