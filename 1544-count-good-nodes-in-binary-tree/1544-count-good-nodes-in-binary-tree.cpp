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
    TreeNode * reset = nullptr;

    void inorder(TreeNode * root, int & res , int  prev){
        if(root){
            if( prev <= root->val){
                res++;
            }
            prev =root->val;
            inorder(root->left,res,prev);
            if(root == reset){
                prev = reset->val;
            }
            inorder(root->right,res,prev);
        }
    }
    int goodNodes(TreeNode* root) {
        reset  = root;
        int res = 0, prev = root->val;
        inorder(root,res,prev);

        return res;
    }
};