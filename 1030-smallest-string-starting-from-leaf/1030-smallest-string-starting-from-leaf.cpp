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
    void inorder(TreeNode * root, string curr ,string  &res){
        if(root){
            curr.push_back(root->val + 'a');
            if(!root->left && !root->right)
            {
                reverse(curr.begin(),curr.end());
                if(res.empty() || res > curr){
                    res = curr;
                }
            }
            inorder(root->left ,curr,res);
            inorder(root->right,curr,res);
            curr.pop_back();
        }
    }
    string smallestFromLeaf(TreeNode* root) {
        string res = "";
        string curr = "";

        inorder(root,curr,res);
        
        return res;
    }
};